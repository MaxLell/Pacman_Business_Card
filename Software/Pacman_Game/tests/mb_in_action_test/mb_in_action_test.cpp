#include <iostream>
#include "assert.h"
#include "common_types.h"
#include "message_broker.h"

#include "CppUTest/TestHarness.h"

// clang-format off
TEST_GROUP(MessageBroker_in_action_with_modules){
    void setup(){

    }
    void teardown()
    {
        // nothing much happening here
    }
};
// clang-format on

/**
 * ----------------------------------------------------------------------------------------------------
 * Some dummy Module - just to experiment with the Message Broker
 * in a realistic scenario
 * ----------------------------------------------------------------------------------------------------
 */

enum class TestTopic
{
    TOPIC_1 = 0,
    TOPIC_2,
    TOPIC_3,
    LAST_TOPIC
};

struct coordintates
{
    u8 x;
    u8 y;
};

class Module
{
public:
    Module(MessageBroker<TestTopic, 5> mb); // Specify template arguments
    ~Module();
    void subscribeToTopics();
    void sendCoordinatesXY(coordintates coordinate);
    coordintates getCoordinatesXY();

private:
    MessageBroker<TestTopic, 5> msgBroker;
    coordintates coordinate;
};

Module::Module(MessageBroker<TestTopic, 5> mb) : msgBroker(mb)
{
}

Module::~Module()
{
}

void Module::subscribeToTopics()
{
    u32 randomId = msgBroker.getRandomCbId();
    msgBroker.subscribe(TestTopic::TOPIC_1, 
                       {randomId, [this](const message &msg)
                                    {
                                        if (msg.sizeBytes == sizeof(coordintates))
                                        {
                                            coordintates *receivedCoordinate = static_cast<coordintates *>(msg.data);
                                            coordinate = *receivedCoordinate;
                                        }
                                        else
                                        {
                                            ASSERT(false); // Invalid message size
                                        }
                                    }});
}

void Module::sendCoordinatesXY(coordintates coordinate)
{
    message msg;
    msg.data = &coordinate;
    msg.sizeBytes = sizeof(coordintates);
    msgBroker.publish(TestTopic::TOPIC_1, msg);
}

coordintates Module::getCoordinatesXY()
{
    return coordinate;
}

/**
 * ----------------------------------------------------------------------------------------------------
 * ----------------------------------------------------------------------------------------------------
 */

TEST(MessageBroker_in_action_with_modules, moduleA_sends_msg_to_itself)
{
    MessageBroker<TestTopic, 5> mb;
    Module moduleA(mb);
    moduleA.subscribeToTopics();

    coordintates sent = {5, 10};
    moduleA.sendCoordinatesXY(sent);
    coordintates recv = moduleA.getCoordinatesXY();
    CHECK_EQUAL(sent.x, recv.x);
    CHECK_EQUAL(sent.y, recv.y);
}

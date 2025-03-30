
#include <iostream>
#include "message_broker.h"
#include "message_definitions.h"
#include "assert.h"

#include "CppUTest/TestHarness.h"

TEST_GROUP(MB){
    void setup(){
        
}

void teardown()
{
}
}
;

enum class TestTopic
{
    TOPIC_1 = 0,
    TOPIC_2,
    TOPIC_3,
    LAST_TOPIC
};

TEST(MB, messageBroker_can_create_a_random_number)
{
    MessageBroker<TestTopic, 1000> mb;
    std::array<u32, 5> randomNumbers;
    for (u32& number : randomNumbers){
        number = mb.getRandomCbId();
    }

    // Check if all random numbers are unique
    for (size_t i = 0; i < randomNumbers.size(); ++i) {
        for (size_t j = i + 1; j < randomNumbers.size(); ++j) {
            CHECK(randomNumbers[i] != randomNumbers[j]);
        }
    }    
}

TEST(MB, messageBroker_can_transfer_message_via_subscribe_and_publish)
{
    MessageBroker<TestTopic, 5> mb;
    u32 randomId = mb.getRandomCbId();
    message msg;
    bool msgReceived = false;

    callbackEntry cbEntry;
    cbEntry.callbackIdNumber = randomId;
    cbEntry.callback = [&msgReceived](const message& msg) {
        msgReceived = true;
    };

    mb.subscribe(TestTopic::TOPIC_1, cbEntry);
    mb.publish(TestTopic::TOPIC_1, msg);

    // Check if the message was received
    CHECK(msgReceived);
}

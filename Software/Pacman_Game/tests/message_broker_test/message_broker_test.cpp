#include "CppUTest/TestHarness.h"

#include <iostream>
#include "message_broker.h"
#include "assert.h"

bool messageWasReceived = false;

TEST_GROUP(MB){
    void setup(){
        messageWasReceived = false;
}

void teardown()
{
}
}
;



void callback_test(message &msg)
{
    messageWasReceived = true;
}

TEST(MB, subscribe_increases_the_topicsVector)
{
    std::string testTopic = "testTopic";
    u8 maxNofTopics = 1;
    u8 maxNofSubscribers = 1;
    MessageBroker msgBroker(maxNofTopics, maxNofSubscribers);

    // Test Topic must not exist yet
    std::vector<topic> testTopicsVector = msgBroker.getTopics();
    CHECK_TRUE(testTopicsVector.size() == 0);

    // Subscribe to the topic
    msgBroker.subscribe(testTopic, callback_test);

    // Test topic must have been added to the list, so the vector
    // must have increased in size
    testTopicsVector = msgBroker.getTopics();
    CHECK_EQUAL(testTopicsVector.size(), 1);
}

TEST(MB, subscribe_places_function_in_topicsVector)
{
    std::string testTopic = "testTopic";
    u8 maxNofTopics = 1;
    u8 maxNofSubscribers = 1;
    MessageBroker msgBroker(maxNofTopics, maxNofSubscribers);
    msgBroker.subscribe(testTopic, callback_test);
    std::vector<topic> testTopicsVector = msgBroker.getTopics();
    messageCb msgCallback = testTopicsVector[0].subscribers[0];
    CHECK_EQUAL(callback_test, msgCallback);

    // Make sure that the function can be called and that this function's
    // output is as expected
    CHECK_FALSE(messageWasReceived);
    message dummy;
    msgCallback(dummy);
    CHECK_TRUE(messageWasReceived);
}

TEST(MB, subscribe_does_not_add_topic_twice)
{
    std::string testTopic = "testTopic";
    u8 maxNofTopics = 1;
    u8 maxNofSubscribers = 2;
    MessageBroker msgBroker(maxNofTopics, maxNofSubscribers);
    msgBroker.subscribe(testTopic, callback_test);
    msgBroker.subscribe(testTopic, callback_test);
    std::vector<topic> testTopicsVector = msgBroker.getTopics();
    CHECK_EQUAL(testTopicsVector.size(), 1);
    CHECK_EQUAL(testTopicsVector[0].subscribers.size(), 2);
}

TEST(MB, messageBroker_can_transfer_message_via_subscribe_and_publish)
{
    std::string testTopic = "testTopic";
    u8 maxNofTopics = 1;
    u8 maxNofSubscribers = 1;
    MessageBroker msgBroker(maxNofTopics, maxNofSubscribers);

    msgBroker.subscribe(testTopic, callback_test);
    CHECK_FALSE(messageWasReceived);

    message dummy;
    msgBroker.publish(testTopic, dummy);

    CHECK_TRUE(messageWasReceived);
}

#include <iostream>
#include "message_broker.h"
#include "assert.h"

#include "CppUTest/TestHarness.h"

struct dummySubscriber
{
    subscriberId subscriber;
    bool cbWasCalled;
};

std::vector<dummySubscriber> msgCallbacks;

TEST_GROUP(MB){
    void setup(){
        msgCallbacks.clear();
}

void teardown()
{
}
}
;

TEST(MB, subscribe_increases_the_topicsVector)
{
    std::string testTopic = "testTopic";
    u8 maxNofTopics = 1;
    u8 maxNofSubscribers = 1;
    MessageBroker msgBroker(maxNofTopics, maxNofSubscribers);

    // Test Topic must not exist yet
    std::vector<topic> testTopicsVector = msgBroker.getTopics();
    CHECK_EQUAL_ZERO(testTopicsVector.size());

    // Create a dummy subscriber
    dummySubscriber testSub1;
    testSub1.cbWasCalled = false;
    testSub1.subscriber.subscriberName = "testSub1";
    testSub1.subscriber.callback = [&testSub1](const message &msg)
    {
        testSub1.cbWasCalled = true;
    };

    // Subscribe to the topic
    msgBroker.subscribeToTopic(testTopic, testSub1.subscriber);

    // Test topic must have been added to the list, so the vector
    // must have increased in size
    testTopicsVector = msgBroker.getTopics();
    CHECK_EQUAL(testTopicsVector.size(), 1);
    CHECK_EQUAL(testTopicsVector[0].topicId, testTopic);
    CHECK_EQUAL(testTopicsVector[0].subscriber.size(), 1);
    CHECK_EQUAL(testTopicsVector[0].subscriber[0].subscriberName, testSub1.subscriber.subscriberName);
}

TEST(MB, subscribe_does_not_add_topic_twice)
{
    std::string testTopic = "testTopic";
    u8 maxNofTopics = 1;
    u8 maxNofSubscribers = 2;
    MessageBroker msgBroker(maxNofTopics, maxNofSubscribers);

    dummySubscriber testSub1, testSub2;
    testSub1.cbWasCalled = false;
    testSub1.subscriber.subscriberName = "testSub1";
    testSub1.subscriber.callback = [&testSub1](const message &msg)
    {
        testSub1.cbWasCalled = true;
    };
    testSub2.cbWasCalled = false;
    testSub2.subscriber.subscriberName = "testSub2";
    testSub2.subscriber.callback = [&testSub2](const message &msg)
    {
        testSub2.cbWasCalled = true;
    };
    // Subscribe to the topic
    msgBroker.subscribeToTopic(testTopic, testSub1.subscriber);
    msgBroker.subscribeToTopic(testTopic, testSub2.subscriber);

    std::vector<topic> testTopicsVector = msgBroker.getTopics();
    CHECK_EQUAL(testTopicsVector.size(), 1);
    CHECK_EQUAL(testTopicsVector[0].subscriber.size(), 2);
}

TEST(MB, messageBroker_can_transfer_message_via_subscribe_and_publish)
{
    std::string testTopic = "testTopic";
    u8 maxNofTopics = 1;
    u8 maxNofSubscribers = 1;
    MessageBroker msgBroker(maxNofTopics, maxNofSubscribers);

    // create a dummy message callback
    dummySubscriber testSub;
    testSub.cbWasCalled = false;
    testSub.subscriber.subscriberName = "testSub1";
    testSub.subscriber.callback = [&testSub](const message &msg)
    {
        testSub.cbWasCalled = true;
    };

    // Subscribe to the topic
    msgBroker.subscribeToTopic(testTopic, testSub.subscriber);
    CHECK_FALSE(testSub.cbWasCalled);

    message dummy;
    msgBroker.publishToTopic(testTopic, dummy);

    CHECK_TRUE(testSub.cbWasCalled);
    testSub.cbWasCalled = false;
    msgBroker.publishToTopic(testTopic, dummy);
    CHECK_TRUE(testSub.cbWasCalled);
}

TEST(MB, unsubscribe_removes_a_subscriber)
{
    std::string testTopic = "testTopic";
    u8 maxNofTopics = 1;
    u8 maxNofSubscribers = 2;
    std::vector<topic> testTopicsVector;

    MessageBroker msgBroker(maxNofTopics, maxNofSubscribers);

    // Create two dummy subscribers
    dummySubscriber testSub1, testSub2;
    testSub1.cbWasCalled = false;
    testSub1.subscriber.subscriberName = "testSub1";
    testSub1.subscriber.callback = [&testSub1](const message &msg)
    {
        testSub1.cbWasCalled = true;
    };
    testSub2.cbWasCalled = false;
    testSub2.subscriber.subscriberName = "testSub2";
    testSub2.subscriber.callback = [&testSub2](const message &msg)
    {
        testSub2.cbWasCalled = true;
    };
    // Subscribe to the topic
    msgBroker.subscribeToTopic(testTopic, testSub1.subscriber);
    msgBroker.subscribeToTopic(testTopic, testSub2.subscriber);
    CHECK_FALSE(testSub1.cbWasCalled);
    CHECK_FALSE(testSub2.cbWasCalled);

    // Verify that there are 2 subscribers
    testTopicsVector = msgBroker.getTopics();
    CHECK_EQUAL(testTopicsVector[0].subscriber.size(), 2);

    // Unsubscribe from this topic
    msgBroker.unsubscribeFromTopic(testTopic, testSub1.subscriber);

    // Verify that there are 1 subscribers
    testTopicsVector = msgBroker.getTopics();
    CHECK_EQUAL(testTopicsVector[0].subscriber.size(), 1);

    // Unsubscribe from this topic
    msgBroker.unsubscribeFromTopic(testTopic, testSub2.subscriber);

    // Verify that also the topic got removed
    testTopicsVector = msgBroker.getTopics();
    CHECK_EQUAL(testTopicsVector.size(), 0);
}

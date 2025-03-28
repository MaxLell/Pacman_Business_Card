#include <iostream>
#include <memory>
#include <utility>
#include <cstring> 
#include "message_broker.h"
#include "assert.h"

#include "CppUTest/TestHarness.h"

static bool messageWasReceived = false;

TEST_GROUP(MB_Alice_and_Bob){
    void setup(){
        messageWasReceived = false;
    }
    void teardown()
    {
        // nothing much happening here
    }
};

class Person
{
private:
    MessageBroker &msgBroker;
    std::string topicToPublish;
    message lastMsg;

public:
    Person(MessageBroker &broker) : msgBroker(broker)
    {
        lastMsg.sizeBytes = 0;
    }
    ~Person()
    {
        if (lastMsg.sizeBytes != 0) {
            // Reset
            delete[] static_cast<char*>(lastMsg.data);
            lastMsg.sizeBytes = 0;
        }
    }

    void subscribeToTopic(std::string topic) {
        msgBroker.subscribeToTopic(topic, [this](const message &msg)
        {
            this->recvMsg(msg);
        });
    }

    void sendMsg(message &msg, std::string topicToPublish)
    {
        
        msgBroker.publishToTopic(topicToPublish, msg);
    }

    void recvMsg(const message &msg)
    {
        if (lastMsg.sizeBytes != 0) {
            // Reset
            delete[] static_cast<char*>(lastMsg.data);
            lastMsg.sizeBytes = 0;
        }

        lastMsg.data = new char[msg.sizeBytes];
        std::memcpy(lastMsg.data, msg.data, msg.sizeBytes);
        lastMsg.sizeBytes = msg.sizeBytes;
    }

    const message& getLastMsg(){
        return lastMsg;
    }
};

TEST(MB_Alice_and_Bob, alice_sends_a_message_to_bob)
{
    // Configure the Message Broker
    u8 nofTopics = 2;
    u8 nofSubsPerTopic = 1;
    message sentMsg, receivedMsg;
    
    // Create the message broker instance
    MessageBroker messageBroker(nofTopics,nofSubsPerTopic);

    // Create two persons
    Person alice(messageBroker);
    Person bob(messageBroker);

    // Create two topics
    std::string aliceNews = "News from ALICE";
    std::string bobNews = "News from BOB";

    // Subscribe to the topics  
    alice.subscribeToTopic(bobNews);
    bob.subscribeToTopic(aliceNews);

    // Send a message from Alice to Bob
    
    std::string messageString = "Hello Bob, this is Alice >:)";
    sentMsg.data = (void *)messageString.c_str();
    sentMsg.sizeBytes = messageString.size();

    alice.sendMsg(sentMsg, aliceNews);
    receivedMsg = bob.getLastMsg();
    CHECK_EQUAL(receivedMsg.sizeBytes, sentMsg.sizeBytes);

    // Send a message from Bob to Alice
    messageString = "Hello Alice, this is Bob :O";
    sentMsg.data = (void *)messageString.c_str();
    sentMsg.sizeBytes = messageString.size();

    bob.sendMsg(sentMsg, bobNews);
    receivedMsg = alice.getLastMsg();
    CHECK_EQUAL(receivedMsg.sizeBytes, sentMsg.sizeBytes);
}

TEST(MB_Alice_and_Bob, Bazar_talk) {
    /**
     * This is a bazar test
     * - there are many topics
     * - there are many subscribers to said topics
     * - People are dropping in (subscribe) and out of topics (unsubscribe) at random
     * 
     * This test shall verify that the system is robust
     */

    // Configure the Message Broker
    u8 nofTopics = 5;
    u8 nofSubsPerTopic = 5;
    u8 nofPersons = 5;
    message sentMsg, receivedMsg;

    // Create the message broker instance
    MessageBroker messageBroker(nofTopics, nofSubsPerTopic);

    // Create many persons
    std::vector<Person> persons;
    for (int i = 0; i < nofPersons; i++) {
        persons.emplace_back(messageBroker);
    }

    // Create many topics
    std::string topics[nofTopics];
    for (int i = 0; i < nofTopics; i++)
    {
        topics[i] = "Topic" + std::to_string(i);
    }

    // Subscribe to the topics -> All persons now subscribe to all topics
    for (int i = 0; i < nofPersons; i++)
    {
        for (int j = 0; j < nofTopics; j++)
        {
            persons[i].subscribeToTopic(topics[j]);
        }
    }

    // Send a message from each person to each topic
    for (int i = 0; i < nofPersons; i++)
    {
        for (int j = 0; j < nofTopics; j++)
        {
            std::string messageString = "Hello Topic" + std::to_string(j) + ", this is Person" + std::to_string(i);
            sentMsg.data = (void *)messageString.c_str();
            sentMsg.sizeBytes = messageString.size();
            persons[i].sendMsg(sentMsg, topics[j]);
        }
    }

    // Check that each person received the message
    for (int i = 0; i < nofPersons; i++)
    {
        for (int j = 0; j < nofTopics; j++)
        {
            receivedMsg = persons[i].getLastMsg();
            CHECK_EQUAL(receivedMsg.sizeBytes, sentMsg.sizeBytes);
        }
    }
}
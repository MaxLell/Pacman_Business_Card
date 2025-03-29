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
    std::vector<std::string> subscribedTopics;

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
        subscribedTopics.push_back(topic);
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

    void unsubscribeFromTopic(std::string topic)
    {
        auto it = std::find(subscribedTopics.begin(), subscribedTopics.end(), topic);
        if (it != subscribedTopics.end()) {
            msgBroker.unsubscribeFromTopic(topic, [this](const message &msg)
            {
                this->recvMsg(msg);
            });
            subscribedTopics.erase(it);
        }
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

// TEST(MB_Alice_and_Bob, Bazar_talk) {
//     /**
//      * This is a bazar test
//      * - there are many topics
//      * - there are many subscribers to said topics
//      * - People are dropping in (subscribe) and out of topics (unsubscribe) at random
//      * 
//      * This test shall verify that the system is robust
//      */

//     // Configure the Message Broker
//     u8 nofTopics = 5;
//     u8 nofSubsPerTopic = 5;
//     u8 nofPersons = 5;
//     message sentMsg, receivedMsg;

//     // Create the message broker instance
//     MessageBroker messageBroker(nofTopics, nofSubsPerTopic);

//     // Create many persons
//     std::vector<Person> persons;
//     for (int i = 0; i < nofPersons; i++) {
//         persons.emplace_back(messageBroker);
//     }

//     // Create many topics
//     std::string topics[nofTopics];
//     for (int i = 0; i < nofTopics; i++)
//     {
//         topics[i] = "Topic" + std::to_string(i);
//     }

//     // Subscribe to the topics -> Now each person is subscribed to all topics
//     // That means sending one message from one person results in nofSubsPerTopic messages,
//     // whose receival can also be prooven
//     for (int i = 0; i < nofPersons; i++) {
//         for (int j = 0; j < nofTopics; j++) {
//             persons[i].subscribeToTopic(topics[j]);
//         }
//     }

//     // Create one generic Hello world Message
//     message msg;
//     std::string messageString = "Hello World!";
//     msg.data = (void *)messageString.c_str();
//     msg.sizeBytes = messageString.size();

//     // Have all people send messages and confirm their receival
//     for (int i = 0; i < nofPersons; i++) {
//         for (int j = 0; j < nofTopics; j++) {
//             persons[i].sendMsg(msg, topics[j]);
//             receivedMsg = persons[i].getLastMsg();
//             CHECK_EQUAL(receivedMsg.sizeBytes, msg.sizeBytes);
//         }
//     }

//     // Unsubscribe all persons from all topics and verify that their topic lists are empty
//     for (int i = 0; i < nofPersons; i++) {
//         for (int j = 0; j < nofTopics; j++) {
//             persons[i].unsubscribeFromTopic(topics[j]);
//         }
//     }

//     // Check that all persons are unsubscribed from all topics
//     std::vector<topic> tmpTopic = messageBroker.getTopics();
//     CHECK_EQUAL_ZERO(tmpTopic.size());
// }

    

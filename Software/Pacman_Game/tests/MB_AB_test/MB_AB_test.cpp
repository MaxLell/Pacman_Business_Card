#include <iostream>
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
    std::string ownName;
    std::string topicToPublish;

public:
    Person(MessageBroker &broker,
           std::string ownName) : msgBroker(broker), ownName(ownName)
    {
        
    }
    ~Person()
    {
    }

    void subscribeToMsg(std::string topic) {
        msgBroker.subscribe(topic, [this](const message &msg)
        {
            this->recvMsg(msg);
        });
    }

    void sendMsg(message &msg, std::string topicToPublish)
    {
        
        msgBroker.publish(topicToPublish, msg);
    }

    void recvMsg(const message &msg)
    {
        std::string senderName((char *)msg.data, msg.sizeBytes);
        std::cout << "received: " << senderName << std::endl;
    }
};

TEST(MB_Alice_and_Bob, alice_sends_a_message_to_bob)
{
    // Configure the Message Broker
    u8 nofTopics = 2;
    u8 nofSubsPerTopic = 1;
    MessageBroker mb(nofTopics,nofSubsPerTopic);

    // Create two persons
    Person alice(mb, "Alice");
    Person bob(mb, "Bob");

    // Subscribe to the topics  
    alice.subscribeToMsg("news from BOB");
    bob.subscribeToMsg("news from ALICE");

    // Send and receive message
    message msg;
    std::string messageString = "Hello Bob, this is Alice";
    msg.data = (void *)messageString.c_str();
    msg.sizeBytes = messageString.size();
    alice.sendMsg(msg, "news from ALICE");

    messageString = "Hello Alice, this is Bob";
    msg.data = (void *)messageString.c_str();
    msg.sizeBytes = messageString.size();
    bob.sendMsg(msg, "news from BOB");
}
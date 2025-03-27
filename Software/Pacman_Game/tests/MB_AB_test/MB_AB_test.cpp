#include <iostream>
#include "message_broker.h"
#include "assert.h"

#include "CppUTest/TestHarness.h"



bool messageWasReceived = false;

TEST_GROUP(MB_Alice_and_Bob){
    void setup(){
        messageWasReceived = false;
    }
    void teardown() { 
        // nothing much happening here
    }
};

class Person
{
private:
    MessageBroker &msgBroker;

public:
    Person(MessageBroker &broker) : msgBroker(broker) {
        msgBroker.subscribe("HelloWorld", [this](message &msg) {
            this->recvCb(msg); // Rufe die Memberfunktion recvCb auf
        });
    }
    ~Person()
    {
    }

    void sendMsg(message &msg) {
        
    }

    void recvCb(message& msg) {
        // Do things
    }
};


TEST(MB_Alice_and_Bob, alice_sends_a_message_to_bob)
{
}
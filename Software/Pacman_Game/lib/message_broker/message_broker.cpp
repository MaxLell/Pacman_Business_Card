#include "message_broker.h"
#include "assert.h"
#include <iostream>

MessageBroker::MessageBroker(u8 maxNofTopics, u8 maxNofSubscribers)
    : maxNofTopics(maxNofTopics), maxNofSubscribers(maxNofSubscribers)
{
}

MessageBroker::~MessageBroker()
{
}




void MessageBroker::subscribeToTopic(const std::string &topicId, const subscriberId &inputSubscriber)
{
    
}

void MessageBroker::unsubscribeFromTopic(const std::string &topicId, const subscriberId &subscriber)
{
    
}

void MessageBroker::publishToTopic(const std::string &topicId, const message &msg)
{
    
}

const std::vector<topic> &MessageBroker::getTopics()
{
   
}

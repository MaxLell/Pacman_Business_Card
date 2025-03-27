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

void MessageBroker::subscribe(const std::string& topicId, const messageCb callback)
{
    // Make sure that the provided topic has at least one character
    ASSERT(topicId.length() != 0);
    
    // Check if the topic exists already
    bool topicExists = false;
    for (auto& topic : this->topicsVector) {
        if (topic.topicId == topicId) {
            topicExists = true;
        }
    }

    if (topicExists) {
        // If the topic exists: Add the callback to the existing subscriber vector
        for (topic& topic : this->topicsVector) {
            if (topic.topicId == topicId) {
                topic.subscribers.push_back(callback);

                // Make sure that the subscribers vector cannot grow indefinitly
                ASSERT(topic.subscribers.size() <= maxNofSubscribers);
            }
        }
    } else {
        // If the topic does NOT exist: Add the topic to topics AND add the callback to its subscriber vector
        topic newTopic;
        newTopic.topicId = topicId;
        newTopic.subscribers.push_back(callback);
        this->topicsVector.push_back(newTopic);        
    }

    // Make sure that the topicsVector cannot grow indefinitly
    ASSERT(this->topicsVector.size() <= maxNofTopics);
}

void MessageBroker::unsubscribe(const std::string& topicId, const messageCb callback)
{
    // To be done
}

void MessageBroker::publish(const std::string& topicId, const message& msg)
{
    // Input Sanity Checks
    topic topicToPublish;
    for (topic& topic : this->topicsVector) {
        if (topic.topicId == topicId) {
            topicToPublish = topic;
            break;
        }
    }
    // Check that topicToPublish is not empty
    ASSERT(topicToPublish.topicId.length() != 0);

    // Check that the subscribers vector is not empty
    ASSERT(topicToPublish.subscribers.size() != 0);

    // Publish the message to all subscribers
    for (messageCb& subscriberCallback : topicToPublish.subscribers) {
        subscriberCallback(msg);
    }
}

std::vector<topic>& MessageBroker::getTopics()
{
    return this->topicsVector;
}
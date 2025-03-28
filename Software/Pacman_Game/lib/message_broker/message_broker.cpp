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

void MessageBroker::subscribeToTopic(const std::string& topicId, const messageCb callback)
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

void MessageBroker::unsubscribeFromTopic(const std::string& topicId, const messageCb callback)
{
    // Input Sanity Checks
    topic* topicToUnsubscribe = nullptr;
    for (topic& topic : this->topicsVector) {
        if (topic.topicId == topicId) {
            topicToUnsubscribe = &topic;
            break;
        }
    }

    // Check that topicToUnsubscribe is not null
    ASSERT(topicToUnsubscribe != nullptr);

    // Check that the subscribers vector is not empty
    ASSERT(topicToUnsubscribe->subscribers.size() != 0);

    // Unsubscribe the callback from the topic
    auto it = std::remove_if(
        topicToUnsubscribe->subscribers.begin(),
        topicToUnsubscribe->subscribers.end(),
        [&callback](const messageCb& subscriberCallback) {
            auto subCb = subscriberCallback.target<void(*)(const message&)>();
            auto inputCb = callback.target<void(*)(const message&)>();
            return subCb && inputCb && *subCb == *inputCb; 
        });

    // There must not be more then one callback being removed
    ASSERT(std::distance(it, topicToUnsubscribe->subscribers.end()) == 1);

    topicToUnsubscribe->subscribers.erase(it, topicToUnsubscribe->subscribers.end());

    // if (topicToUnsubscribe->subscribers.empty()) {
    //     // If the subscriber vector is empty, remove the topic from the topicsVector
    //     auto topicIt = std::remove_if(
    //         this->topicsVector.begin(),
    //         this->topicsVector.end(),
    //         [&topicId](const topic& t) { return t.topicId == topicId; });


    //     this->topicsVector.erase(topicIt, this->topicsVector.end());
    // }
}

void MessageBroker::publishToTopic(const std::string& topicId, const message& msg)
{
    // Input Sanity Checks
    // Make sure that the module is only able to publish if there is at least one subscriber
    // otherwise the message is lost
    topic topicToPublish;
    topicToPublish.topicId = "";
    topicToPublish.subscribers.clear();
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

const std::vector<topic>& MessageBroker::getTopics()
{
    return this->topicsVector;
}
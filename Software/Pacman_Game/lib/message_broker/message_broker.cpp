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

std::vector<topic>::iterator MessageBroker::findTopic(const std::string &topicId)
{
    return std::find_if(
        topicsVector.begin(),
        topicsVector.end(),
        [&topicId](const topic &inputTopic)
        {
            return topicId == inputTopic.topicId;
        });
}

bool MessageBroker::isSubscriberRegistered(const std::string &topicId, const subscriberId &inputSubscriber) const
{
    ASSERT(!topicId.empty());
    ASSERT(!inputSubscriber.subscriberName.empty());

    bool isRegistered = false; // Variable to store the result

    // Find the topic by topicId
    auto topicIterator = std::find_if(
        topicsVector.begin(),
        topicsVector.end(),
        [&topicId](const topic &inputTopic)
        {
            return inputTopic.topicId == topicId;
        });

    if (topicIterator != topicsVector.end())
    {
        // If the topic exists, check if the subscriber is already registered
        const auto &subscribers = topicIterator->subscriber;
        auto subscriberIt = std::find_if(
            subscribers.begin(),
            subscribers.end(),
            [&inputSubscriber](const subscriberId &sub)
            {
                return sub.subscriberName == inputSubscriber.subscriberName;
            });

        if (subscriberIt != subscribers.end())
        {
            isRegistered = true; // Subscriber is found
        }
    }

    return isRegistered; // Single return statement
}

void MessageBroker::subscribeToTopic(const std::string &topicId, const subscriberId &inputSubscriber)
{
    ASSERT(!topicId.empty());
    ASSERT(!inputSubscriber.subscriberName.empty());
    ASSERT(!isSubscriberRegistered(topicId, inputSubscriber));

    // Check whether the topic already exists
    auto it = findTopic(topicId);

    if (it == topicsVector.end())
    {
        // Topic does not exist, create a new one
        topicsVector.push_back({topicId, {}});
        it = std::prev(topicsVector.end());
    }

    // Add the subscriber to the topic
    it->subscriber.push_back(inputSubscriber);
}

void MessageBroker::unsubscribeFromTopic(const std::string &topicId, const subscriberId &subscriber)
{
    ASSERT(!topicId.empty());
    auto topicIt = findTopic(topicId);
    ASSERT(topicIt != topicsVector.end());

    auto &subscribers = topicIt->subscriber;
    auto subIt = std::remove_if(
        subscribers.begin(),
        subscribers.end(),
        [&subscriber](const subscriberId &sub)
        {
            return sub.subscriberName == subscriber.subscriberName;
        });

    bool subscriberExists = (subIt != subscribers.end());
    ASSERT(subscriberExists);

    subscribers.erase(subIt, subscribers.end());

    // if there are no subscribers in the topic any more, remove the topic
    if (subscribers.empty())
    {
        topicsVector.erase(topicIt);
    }
}

void MessageBroker::publishToTopic(const std::string &topicId, const message &msg)
{
    // Input Checks
    ASSERT(!topicId.empty());

    // Check that the topic is already registered
    auto it = findTopic(topicId);
    ASSERT(it != topicsVector.end());

    // Check that there are existing subscribers for this topic
    ASSERT(!it->subscriber.empty());

    // Publish the message to all subscribers
    for (const auto &subscriber : it->subscriber)
    {
        subscriber.callback(msg); // Call the callback member
    }
}

const std::vector<topic> &MessageBroker::getTopics()
{
    return this->topicsVector;
}

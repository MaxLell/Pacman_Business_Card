#pragma once
#include "common_types.h"
#include <string>
#include <vector>
#include <functional>


struct message
{
    void *data;
    u32 sizeBytes;
};

using messageCb = std::function<void(const message&)>;

struct subscriberId {
    std::string subscriberName;
    messageCb callback;
};

struct topic {
    std::string topicId;
    std::vector<subscriberId> subscriber;
};

class MessageBroker 
{
private:
    std::vector<topic> topicsVector;
    u8 maxNofTopics;
    u8 maxNofSubscribers;

    std::vector<topic>::iterator findTopic(const std::string& topicId);
    bool isSubscriberRegistered(const std::string& topicId, const subscriberId& inputSubscriber) const;
public:
    MessageBroker(u8 maxNofTopics, u8 maxNofSubscribers);
    ~MessageBroker();

    const std::vector<topic>& getTopics();
    void publishToTopic(const std::string& topicId, const message& msg);
    void subscribeToTopic(const std::string& topicId, const subscriberId& subscriber);
    void unsubscribeFromTopic(const std::string& topicId, const subscriberId& subscriber);
};

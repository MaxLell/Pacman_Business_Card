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

using messageCb = std::function<void(const message &)>;

class MessageBroker
{
public:
    MessageBroker(u8 maxNofTopics, u8 maxNofSubscribers);
    ~MessageBroker();

    void subscribeToTopic(const std::string &topicId, const subscriberId &subscriber);
    void publishToTopic(const std::string &topicId, const message &msg);
    void unsubscribeFromTopic(const std::string &topicId, const subscriberId &subscriber);

    const std::vector<topic> &getTopics();

private:
 
};

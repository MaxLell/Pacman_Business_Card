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

using messageCb =  std::function<void(const message&)>;

struct topic {
    std::string topicId;
    std::vector<messageCb> subscribers;
};

class MessageBroker 
{
private:
    std::vector<topic> topicsVector;
    u8 maxNofTopics;
    u8 maxNofSubscribers;
public:
    MessageBroker(u8 maxNofTopics, u8 maxNofSubscribers);
    ~MessageBroker();

    std::vector<topic>& getTopics();
    void publishToTopic(const std::string& topicId, const message& msg);
    void subscribeToTopic(const std::string& topicId, const messageCb callback);
    void unsubscribeFromTopic(const std::string& topicId, const messageCb callback);
};

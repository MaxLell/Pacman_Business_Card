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
    void publish(const std::string& topicId, const message& msg);
    void subscribe(const std::string& topicId, const messageCb callback);
    void unsubscribe(const std::string& topicId, const messageCb callback);
};

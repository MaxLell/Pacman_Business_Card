#pragma once
#include "common_types.h"
#include <string>
#include <vector>

struct message
{
    void *data;
    u32 sizeBytes;
};

using messageCb =  void(*)(message&);

struct topic {
    std::string topicId;
    std::vector<messageCb> subscribers;
};

class IMessageBroker
{
public:
    virtual void publish(const std::string& topicId, message& msg) = 0;
    virtual void subscribe(const std::string& topicId, messageCb callback) = 0;
    virtual void unsubscribe(std::string& topicId, messageCb callback) = 0;
};

class MessageBroker : public IMessageBroker
{
private:
    std::vector<topic> topicsVector;
    u8 maxNofTopics;
    u8 maxNofSubscribers;
public:
    MessageBroker(u8 maxNofTopics, u8 maxNofSubscribers);
    ~MessageBroker();

    std::vector<topic>& getTopics();
    void publish(const std::string& topicId, message& msg);
    void subscribe(const std::string& topicId, messageCb callback);
    void unsubscribe(std::string& topicId, messageCb callback);
};

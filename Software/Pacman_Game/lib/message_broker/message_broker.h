#pragma once
#include <array>
#include <functional>
#include "common_types.h"
#include "custom_assert.h"

struct message
{
    void *data;
    u32 sizeBytes;
};

using messageCb = std::function<void(const message &)>;

struct callbackEntry {
    u32 callbackIdNumber;
    messageCb callback;   
};

constexpr std::size_t MAX_TOPICS = 100; // Maximum number of topics allowed

template <typename Topic, std::size_t nofCbPerTopic>
class MessageBroker
{
public:
    MessageBroker();
    ~MessageBroker();

    void subscribe(Topic topic, callbackEntry cbEntry);
    void unsubscribe(Topic topic, callbackEntry cbEntry);
    void publish(Topic topic, const message &msg);
    u32 getRandomCbId();

private:
    static_assert(static_cast<std::size_t>(Topic::LAST_TOPIC) <= MAX_TOPICS,
                  "The number of topics exceeds the maximum allowed limit");
    static constexpr std::size_t maxTopics = static_cast<std::size_t>(Topic::LAST_TOPIC);
    std::array<std::array<callbackEntry, nofCbPerTopic>, maxTopics> topicLookUpTable;
    u32 seed;
};

// ######################################################################
// ######################################################################
// ######################################################################

// Implementation of MessageBroker
// Template classes must have their implementation in the header file
template <typename Topic, std::size_t nofCbPerTopic>
MessageBroker<Topic, nofCbPerTopic>::MessageBroker()
{
    for (std::size_t i = 0; i < maxTopics; ++i)
    {
        for (std::size_t j = 0; j < nofCbPerTopic; ++j)
        {
            topicLookUpTable[i][j].callbackIdNumber = 0;
            topicLookUpTable[i][j].callback = nullptr;
        }
    }
    seed = 2463534242;
}

template <typename Topic, std::size_t nofCbPerTopic>
MessageBroker<Topic, nofCbPerTopic>::~MessageBroker()
{
    for (std::size_t i = 0; i < maxTopics; ++i)
    {
        for (std::size_t j = 0; j < nofCbPerTopic; ++j)
        {
            topicLookUpTable[i][j].callbackIdNumber = 0;
            topicLookUpTable[i][j].callback = nullptr;
        }
    }
}

template <typename Topic, std::size_t nofCbPerTopic>
void MessageBroker<Topic, nofCbPerTopic>::subscribe(Topic topic, callbackEntry cbEntry)
{
    std::size_t topicIdx;
    topicIdx = static_cast<std::size_t>(topic);

    // Input Checks
    ASSERT(topicIdx < maxTopics);// Check if the topic is valid
    ASSERT(cbEntry.callbackIdNumber != 0);// cbEntry's Id must not be 0
    // cbEntry's Id must be unique
    for (std::size_t i = 0; i < nofCbPerTopic; ++i)
    {
        ASSERT(topicLookUpTable[topicIdx][i].callbackIdNumber != cbEntry.callbackIdNumber);
    }

    // Add the callback entry to the topicLookUpTable
    // Check if we have space in the topicLookUpTable
    // If not, we have a problem
    // We assume that the topicLookUpTable is not full, so we can add the callback
    // entry to the first free space
    bool foundSpace = false;
    for (std::size_t i = 0; i < nofCbPerTopic; ++i)
    {
        if (topicLookUpTable[topicIdx][i].callbackIdNumber == 0)
        {
            topicLookUpTable[topicIdx][i] = cbEntry;
            foundSpace = true;
            break;
        }
    }
    // Check if we found a free space in the topicLookUpTable -> if not, we have a problem
    ASSERT(foundSpace);
}

template <typename Topic, std::size_t nofCbPerTopic>
void MessageBroker<Topic, nofCbPerTopic>::unsubscribe(Topic topic, callbackEntry cbEntry)
{
    std::size_t topicIdx;
    topicIdx = static_cast<std::size_t>(topic);
    // Check if the topic is valid
    ASSERT(topicIdx < maxTopics);
    ASSERT(cbEntry.callbackIdNumber != 0);// cbEntry's Id must not be 0

    // Remove the callback entry from the topicLookUpTable
    bool removedCallback = false;
    for (std::size_t i = 0; i < nofCbPerTopic; ++i)
    {
        if (topicLookUpTable[topicIdx][i].callbackIdNumber == cbEntry.callbackIdNumber)
        {
            topicLookUpTable[topicIdx][i].callbackIdNumber = 0;
            topicLookUpTable[topicIdx][i].callback = nullptr;

            removedCallback = true;
            break;
        }
    }
    ASSERT(removedCallback);
}

template <typename Topic, std::size_t nofCbPerTopic>
void MessageBroker<Topic, nofCbPerTopic>::publish(Topic topic, const message &msg)
{
    std::size_t topicIdx;
    topicIdx = static_cast<std::size_t>(topic);
    // Check if the topic is valid
    ASSERT(topicIdx < maxTopics);

    // Call all callbacks for the given topic
    bool callbackCalled = false;
    for (std::size_t i = 0; i < nofCbPerTopic; ++i)
    {
        if (topicLookUpTable[topicIdx][i].callbackIdNumber != 0)
        {
            callbackCalled = true;
            topicLookUpTable[topicIdx][i].callback(msg);
        }
    }
    // Check if at least one callback was called
    ASSERT(callbackCalled);
}

template <typename Topic, std::size_t nofCbPerTopic>
u32 MessageBroker<Topic, nofCbPerTopic>::getRandomCbId()
{
    // Simple random number generator using XOR shift
    // See: https://en.wikipedia.org/wiki/Xorshift
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;

    ASSERT(seed != 0);
    return seed;
}


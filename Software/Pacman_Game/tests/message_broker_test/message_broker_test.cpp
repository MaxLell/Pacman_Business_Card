#include "message_broker.h"
#include "assert.h"
#include "message_definitions.h"
#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

// clang-format off
TEST_GROUP(MB){
    void setup(){
      mock().clear();
    }
    void teardown(){
      mock().clear();
    }
};
// clang-format on

enum class TestTopic { TOPIC_1 = 0, TOPIC_2, TOPIC_3, LAST_TOPIC };

TEST(MB, messageBroker_can_create_a_random_number) {
  MessageBroker<TestTopic, 5> mb;
  std::array<u32, 5> randomNumbers;
  for (u32& number : randomNumbers) {
    number = mb.getRandomCbId();
  }

  // Check if all random numbers are unique
  for (size_t i = 0; i < randomNumbers.size(); ++i) {
    for (size_t j = i + 1; j < randomNumbers.size(); ++j) {
      CHECK(randomNumbers[i] != randomNumbers[j]);
    }
  }
}

// TEST(MB, messageBroker_can_transfer_message_via_subscribe_and_publish) {
//   MessageBroker<TestTopic, 5> mb;
//   u32 randomId = mb.getRandomCbId();
//   message msg;
//   bool msgReceived = false;

//   callbackEntry cbEntry;
//   cbEntry.callbackIdNumber = randomId;
//   cbEntry.callback = [&msgReceived](const message& msg) { msgReceived = true; };

//   mb.subscribe(TestTopic::TOPIC_1, cbEntry);
//   mb.publish(TestTopic::TOPIC_1, msg);

//   // Check if the message was received
//   CHECK(msgReceived);
// }

TEST(
    MB,
    messageBroker_cannot_subscribe_publish_unsubscribe_with_callbackIdNumber_0) {
  
  MessageBroker<TestTopic, 5> mb;
  message msg;
  bool msgReceived = false;

  callbackEntry cbEntry;
  cbEntry.callbackIdNumber = 0;
  cbEntry.callback = [&msgReceived](const message& msg) { msgReceived = true; };

  mock()
      .expectOneCall("assert_failed")
      .withParameter("condition", "cbEntry.callbackIdNumber != 0")
      .ignoreOtherParameters();

  // subscribe
  mb.subscribe(TestTopic::TOPIC_1, cbEntry);

  mock().checkExpectations();
  
  // mb.publish(TestTopic::TOPIC_1, msg);

  // mb.unsubscribe(TestTopic::TOPIC_1, cbEntry);

  
}

// TEST(MB, messageBroker_cannot_subscribe_with_duplicated_callbackIdNumber) {
//   MessageBroker<TestTopic, 5> mb;
//   u32 randomId = mb.getRandomCbId();
//   message msg;
//   bool msgReceived = false;

//   callbackEntry cbEntry;
//   cbEntry.callbackIdNumber = randomId;
//   cbEntry.callback = [&msgReceived](const message& msg) { msgReceived = true;
//   };

//   mb.subscribe(TestTopic::TOPIC_1, cbEntry);  // subscribe once
//   try {
//     mb.subscribe(TestTopic::TOPIC_1, cbEntry);  // attempt to subscribe again
//   } catch (const std::runtime_error& e) {
//     STRCMP_EQUAL("ASSERT", e.what());
//   }
// }

// TEST(
//     MB,
//     messageBroker_cannot_subscribe_more_callbacks_than_space_in_callback_array)
//     {
//   MessageBroker<TestTopic, 5> mb;
//   message msg;

//   // Create 6 different callbacks
//   std::array<callbackEntry, 6> cbEntries;
//   for (size_t i = 0; i < cbEntries.size(); ++i) {
//     cbEntries[i].callbackIdNumber = mb.getRandomCbId();
//     cbEntries[i].callback = [](const message& msg) {
//       // do nothing
//     };
//   }

//   // Subscribe 5 callbacks
//   for (size_t i = 0; i < 5; ++i) {
//     mb.subscribe(TestTopic::TOPIC_1, cbEntries[i]);
//   }

//   // Try to subscribe the 6th callback
//   try {
//     mb.subscribe(TestTopic::TOPIC_1, cbEntries[5]);
//   } catch (const std::runtime_error& e) {
//     STRCMP_EQUAL("ASSERT", e.what());
//   }
// }

// TEST(MB,
// unsubscribe_cannot_unsubscribe_a_callbackId_it_has_never_seen_before) {
//   MessageBroker<TestTopic, 5> mb;
//   u32 randomId = mb.getRandomCbId();

//   callbackEntry cbEntry;
//   cbEntry.callbackIdNumber = randomId;
//   cbEntry.callback = [](const message& msg) {};

//   mb.subscribe(TestTopic::TOPIC_1, cbEntry);
//   mb.unsubscribe(TestTopic::TOPIC_1, cbEntry);  // unsubscribe the callback

//   // Try to unsubscribe the callback again
//   try {
//     mb.unsubscribe(TestTopic::TOPIC_1, cbEntry);
//   } catch (const std::runtime_error& e) {
//     STRCMP_EQUAL("ASSERT", e.what());
//   }
// }

// TEST(MB, publish_is_failing_when_no_fitting_callback_is_registered) {
//   MessageBroker<TestTopic, 5> mb;
//   message msg;

//   // Publish a message to a topic for which no callback is registered
//   try {
//     mb.publish(TestTopic::TOPIC_1, msg);
//   } catch (const std::runtime_error& e) {
//     STRCMP_EQUAL("ASSERT", e.what());
//   }
// }

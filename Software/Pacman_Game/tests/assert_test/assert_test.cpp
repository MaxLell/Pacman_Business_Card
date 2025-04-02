#include "assert.h"
#include <iostream>
#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(assert_tests) {
    void setup() {
        mock().clear(); // Mock-Daten vor jedem Test zurücksetzen
    }
    void teardown() {
        mock().clear();
    }
};

TEST(assert_tests, triggering_an_assert_shall_call_mocked_assert_failed) {
    // Erwartung setzen, bevor ASSERT aufgerufen wird
    mock().expectOneCall("assert_failed")
          .withParameter("condition", "false")
          .ignoreOtherParameters();
    
    ASSERT(false); 

    mock().checkExpectations();
}
#include <iostream>
#include <stdexcept>
#include "assert_mock.h"

#include "assert.h"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"


// Mock für ASSERT
void assert_failed(const char *condition,
                   const char *file, int line)
{
    mock()
        .actualCall("assert_failed")
        .withParameter("condition", condition)
        .withParameter("file", file)
        .withParameter("line", line);

    throw std::runtime_error("ASSERT");
}

void mock_verifyAssertWasTriggered(const std::string& condition, const std::function<void()>& func) {
    // Set up the mock expectation
    mock()
        .expectOneCall("assert_failed")
        .withParameter("condition", condition.c_str())
        .ignoreOtherParameters();

    bool assertTriggered = false;
    try {
        // Execute the function that is expected to trigger the ASSERT
        func();
        FAIL("Expected ASSERT to throw an exception, but it did not.");
    } catch (const std::runtime_error& e) {
        STRCMP_EQUAL("ASSERT", e.what()); // Verify the exception message
        assertTriggered = true;
    }

    CHECK_TRUE(assertTriggered);

    // Check the mock expectations
    mock().checkExpectations();
    mock().clear();
}
#include <iostream>
#include "assert_mock.h"
#include "assert.h"

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"

// clang-format off
TEST_GROUP(assert_tests){
    void setup(){
        mock().clear(); // Mock-Daten vor jedem Test zurücksetzen
    }
    void teardown()
    {
        mock().clear();
    }
};
// clang-format on

TEST(assert_tests, triggering_an_assert_shall_call_mocked_assert_failed)
{
    // Erwartung setzen, bevor ASSERT aufgerufen wird

    mock().expectOneCall("assert_failed").withParameter("condition", "false").ignoreOtherParameters();

    try
    {
        ASSERT(false);
        FAIL("Expected ASSERT to throw an exception, but it did not.");
    }
    catch (const std::runtime_error &e)
    {
        STRCMP_EQUAL("ASSERT", e.what()); // Überprüfen der Ausnahme-Nachricht
    }

    mock().checkExpectations();
}

void failing_function()
{
    ASSERT(false);
}

TEST(assert_tests, calling_a_failing_function_shall_trigger_assert)
{
    mock_verifyAssertWasTriggered(
        "false",
        []()
        { failing_function(); });
}
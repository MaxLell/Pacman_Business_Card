#include "CppUTest/TestHarness.h"

#include "average.h"

TEST_GROUP(Average)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(Average, average_shall_return_0_for_empty_list)
{
    std::vector<float> values = {};
    float result = average(values);
    DOUBLES_EQUAL(0, result, 0.01);
}

TEST(Average, average_shall_return_1_for_list_with_1)
{
    std::vector<float> values = {1, 1, 1, 1};
    float result = average(values);
    DOUBLES_EQUAL(1, result, 0.01);
}

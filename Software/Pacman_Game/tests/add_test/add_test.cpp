#include "CppUTest/TestHarness.h"

#include "add.h"

TEST_GROUP(Add)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(Add, add_shall_sum_2_values)
{
    int result = add(17, 23);
    CHECK_EQUAL(40, result);
}

TEST(Add, add_shall_sum_2_other_values)
{
    int result = add(1, 2);
    CHECK_EQUAL(3, result);
}

TEST(Add, add_shall_sum_2_new_values)
{
    int result = add(1, 3);
    CHECK_EQUAL(4, result);
}


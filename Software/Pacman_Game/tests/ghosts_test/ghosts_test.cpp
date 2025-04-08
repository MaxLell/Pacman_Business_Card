#include <iostream>
#include <string>
#include "custom_assert.h"
#include "custom_assert_mock.h"
#include "common_types.h"
#include "environment_generator.h"


#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"

// clang-format off
TEST_GROUP(Ghosts_tests){
    void setup(){
        mock().checkExpectations();
        mock().clear();
    }
    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
    }
};
// clang-format on




#include <iostream>
#include <string>
#include "custom_assert.h"
#include "custom_assert_mock.h"
#include "common_types.h"
#include "environment_generator.h"
#include "maze.h"


#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"

// clang-format off
TEST_GROUP(EnvironmentGen_tests){
    void setup(){

    }
    void teardown()
    {
        // nothing much happening here
    }
};
// clang-format on


TEST(EnvironmentGen_tests, walls_can_be_generated_without_asserts_being_triggered)
{
    EnvironmentGenerator envGen;
    Walls walls;

    envGen.loadWallsFromStringArray(testMaze, walls);
}

TEST(EnvironmentGen_tests, pellets_can_be_generated_without_asserts_being_triggered)
{
    EnvironmentGenerator envGen;
    Pellets pellets;

    envGen.loadPelletsFromStringArray(testMaze, pellets);
}


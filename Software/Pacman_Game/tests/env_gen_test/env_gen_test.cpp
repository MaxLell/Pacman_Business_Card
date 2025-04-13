#include <iostream>
#include <string>
#include "custom_assert.h"
#include "custom_assert_mock.h"
#include "common_types.h"
#include "environment_generator.h"


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
    std::array<std::bitset<NOF_COLUMNS>, NOF_ROWS> walls;
    envGen.loadMazeElementFromStringArray(MazeElementType::Walls, walls);
}

TEST(EnvironmentGen_tests, pellets_can_be_generated_without_asserts_being_triggered)
{
    EnvironmentGenerator envGen;
    std::array<std::bitset<NOF_COLUMNS>, NOF_ROWS> pellets;
    envGen.loadMazeElementFromStringArray(MazeElementType::Pellets, pellets);
}

TEST(EnvironmentGen_tests, env_gen_can_setup_aStar) {
    EnvironmentGenerator envGen;
    AStar::Generator a_star;
    envGen.loadMazeIntoPathFinding(a_star);

    const AStar::Vec2i START_POSITION = {1, 1};
    const AStar::Vec2i TARGET_POSITION = {26, 29};

    auto path = a_star.findPath(START_POSITION, TARGET_POSITION);

    // Make sure that the last coordinate is the target
    CHECK_EQUAL(path.back().x, TARGET_POSITION.x);
    CHECK_EQUAL(path.back().y, TARGET_POSITION.y);
}


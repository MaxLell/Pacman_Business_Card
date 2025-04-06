#include <iostream>
#include "custom_assert.h"
#include "custom_assert_mock.h"
#include "common_types.h"
#include "data_pool.h"
#include <string>
#include "environment_generator.h"
#include "maze.h"

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"

// clang-format off
TEST_GROUP(DataPool_test){
    void setup(){

    }
    void teardown()
    {
        // nothing much happening here
    }
};
// clang-format on

TEST(DataPool_test, walls_can_be_set_and_get)
{
    // Access the Singleton instance
    auto &dataPool = DataPool::getInstance();

    // Load walls from testMaze
    Walls walls;
    EnvironmentGenerator envGen;
    envGen.loadWallsFromStringArray(testMaze, walls);
    dataPool.setWalls(walls);

    // Check if the walls are set correctly
    const Walls &retrievedWalls = dataPool.getWalls();
    for (std::size_t i = 0; i < NOF_ROWS; ++i)
    {
        for (std::size_t j = 0; j < NOF_COLUMNS; ++j)
        {
            if (walls[i][j] != retrievedWalls[i][j])
            {
                FAIL("Walls are not set correctly");
            }
        }
    }
}

TEST(DataPool_test, pellets_can_be_set_and_get) {
    // Access the Singleton instance
    auto &dataPool = DataPool::getInstance();

    // Load pellets from testMaze
    Pellets pellets;
    EnvironmentGenerator envGen;
    envGen.loadPelletsFromStringArray(testMaze, pellets);
    dataPool.setPellets(pellets);

    // Check if the pellets are set correctly
    const Pellets &retrievedPellets = dataPool.getPellets();
    for (std::size_t i = 0; i < NOF_ROWS; ++i)
    {
        for (std::size_t j = 0; j < NOF_COLUMNS; ++j)
        {
            if (pellets[i][j] != retrievedPellets[i][j])
            {
                FAIL("Pellets are not set correctly");
            }
        }
    }
}

TEST(DataPool_test, isWallAt_returns_true_for_wall_positions)
{
    // Access the Singleton instance
    auto &dataPool = DataPool::getInstance();

    // Load walls from testMaze
    Walls walls;
    EnvironmentGenerator envGen;
    envGen.loadWallsFromStringArray(testMaze, walls);
    dataPool.setWalls(walls);

    // Check if the isWallAt function returns true for wall positions
    positionXY pos;
    pos.x = 0;
    pos.y = 0;
    CHECK(dataPool.isWallAt(pos));

    pos.x = 2;
    pos.y = 2;
    CHECK(dataPool.isWallAt(pos));
}

TEST(DataPool_test, isWallAt_returns_false_for_non_wall_positions)
{
    // Access the Singleton instance
    auto &dataPool = DataPool::getInstance();

    // Load walls from testMaze
    Walls walls;
    EnvironmentGenerator envGen;
    envGen.loadWallsFromStringArray(testMaze, walls);
    dataPool.setWalls(walls);

    // Check if the isWallAt function returns false for non-wall positions
    positionXY pos;
    pos.x = 1;
    pos.y = 2;
    CHECK(!dataPool.isWallAt(pos));

    pos.x = 2;
    pos.y = 1;
    CHECK(!dataPool.isWallAt(pos));

    pos.x = 1;
    pos.y = 3;
    CHECK(!dataPool.isWallAt(pos));
}

TEST(DataPool_test, isWallAt_throws_assertion_error_for_out_of_bounds)
{
    // Access the Singleton instance
    auto &dataPool = DataPool::getInstance();

    // Load walls from testMaze
    Walls walls;
    EnvironmentGenerator envGen;
    envGen.loadWallsFromStringArray(testMaze, walls);
    dataPool.setWalls(walls);

    // Check if the isWallAt function throws an assertion error for out-of-bounds positions
    positionXY pos;
    pos.x = -10; // Out of bounds
    pos.y = 0;
    mock_verifyAssertWasTriggered(
        "pos.x >= 0",
        [&dataPool, &pos]()
        { dataPool.isWallAt(pos); });
}

TEST(DataPool_test, pacman_position_can_be_set_and_get)
{
    // Access the Singleton instance
    auto &dataPool = DataPool::getInstance();

    // Set the pacman position
    positionXY pacmanPosition = {9, 5};
    dataPool.setPacmanPosition(pacmanPosition);

    // Check if the pacman position is set correctly
    positionXY retrievedPosition = dataPool.getPacmanPosition();
    CHECK(retrievedPosition.x == pacmanPosition.x);
    CHECK(retrievedPosition.y == pacmanPosition.y);
}

TEST(DataPool_test, pacman_position_throws_assertion_error_for_out_of_bounds)
{
    // Access the Singleton instance
    auto &dataPool = DataPool::getInstance();

    // Check if the pacman position throws an assertion error for out-of-bounds positions
    positionXY pos;
    pos.x = -10; // Out of bounds
    pos.y = 0;
    mock_verifyAssertWasTriggered(
        "pos.x >= 0",
        [&dataPool, &pos]()
        { dataPool.setPacmanPosition(pos); });
}

TEST(DataPool_test, control_input_can_be_set_and_get)
{
    // Access the Singleton instance
    auto &dataPool = DataPool::getInstance();

    // Set the control input
    ctrlInput input = ctrlInput::Up;
    dataPool.setControlInputs(input);

    // Check if the control input is set correctly
    ctrlInput retrievedInput = dataPool.getControlInputs();
    CHECK(retrievedInput == input);
}

TEST(DataPool_test, control_input_throws_assertion_error_for_invalid_input)
{
    // Access the Singleton instance
    auto &dataPool = DataPool::getInstance();

    // Check if the control input throws an assertion error for invalid inputs
    ctrlInput input = static_cast<ctrlInput>(255); // Invalid input
    mock_verifyAssertWasTriggered(
        "validInput",
        [&dataPool, &input]()
        { dataPool.setControlInputs(input); });
}



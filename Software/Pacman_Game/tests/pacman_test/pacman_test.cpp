#include <iostream>
#include "custom_assert.h"
#include "custom_assert_mock.h"
#include "message_data_types.h"
#include "topic_definitions.h"
#include "pacman.h"
#include "data_pool.h"
#include "environment_generator.h"

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"

// clang-format off
TEST_GROUP(pacman_tests){
    void setup(){
        mock().checkExpectations();
        mock().clear(); // Mock-Daten vor jedem Test zurücksetzen
    }
    void teardown()
    {
        mock().checkExpectations();
        mock().clear();
    }
};
// clang-format on

TEST(pacman_tests, pacman_can_change_coordinates_with_move_function)
{
    // Set up the DataPool
    DataPool &dataPool = DataPool::getInstance();
    positionXY_t pacmanPosition = {1, 1}; // Initial position
    dataPool.setPacmanPosition(pacmanPosition);

    // Set up the control input
    ctrlInput controlInput = ctrlInput::Right;

    // Initialize Pacman with the DataPool
    Pacman pacman(dataPool);

    // Call the move function
    positionXY_t newPosition = pacman.move(controlInput, pacmanPosition);

    // Check if the new position is correct
    CHECK_EQUAL(2, newPosition.x);
    CHECK_EQUAL(1, newPosition.y);
}

TEST(pacman_tests, can_move_around_in_a_maze)
{
    // Load walls using the refactored function
    std::array<std::bitset<NOF_COLUMNS>, NOF_ROWS> walls;
    EnvironmentGenerator envGen;
    envGen.loadMazeElementFromStringArray(MazeElementType::Walls, walls);

    // Set the walls in the DataPool
    DataPool &dataPool = DataPool::getInstance();
    dataPool.setWalls(static_cast<walls_t>(walls));

    dataPool.setPacmanPosition({1, 1});

    // Set the control input
    ctrlInput controlInput = ctrlInput::Right;
    dataPool.setControlInputs(controlInput);

    // Initialize Pacman with the DataPool
    Pacman pacman(dataPool);
    pacman.update();

    positionXY_t updatedPosition = dataPool.getPacmanPosition();

    CHECK(updatedPosition.x == 2);
    CHECK(updatedPosition.y == 1);
}

TEST(pacman_tests, moving_pacman_through_the_maze_does_not_trigger_assert)
{
    // Have Pacman move through the maze with many random moves
    // At each iteration, run the integrity check -> no asserts must be triggered

    // Load walls using the refactored function
    std::array<std::bitset<NOF_COLUMNS>, NOF_ROWS> walls;
    EnvironmentGenerator envGen;
    envGen.loadMazeElementFromStringArray(MazeElementType::Walls, walls);

    DataPool &dataPool = DataPool::getInstance();
    dataPool.setWalls(static_cast<walls_t>(walls));
    dataPool.setPacmanPosition({1, 1});

    const int nofIterations = 100000;
    for (int i = 0; i < nofIterations; ++i)
    {
        ctrlInput controlInput = static_cast<ctrlInput>(rand() % static_cast<int>(ctrlInput::LAST_ENTRY));
        dataPool.setControlInputs(controlInput);

        Pacman pacman(dataPool);
        pacman.update();

        // Run integrity check - no asserts must be triggered
        dataPool.runIntegrityChecks();
    }
}

TEST(pacman_tests, when_pacman_eats_a_pellet_the_score_is_increased)
{
    DataPool &dataPool = DataPool::getInstance();
    positionXY_t pacmanPosition = {1, 1}; // Position where there is also a pellet
    dataPool.setPacmanPosition(pacmanPosition);

    // Load pellets using the refactored function
    pellets_t pellets;
    EnvironmentGenerator envGen;
    envGen.loadMazeElementFromStringArray(MazeElementType::Pellets, pellets);
    dataPool.setPellets(static_cast<pellets_t>(pellets));
    dataPool.setScore(0);

    Pacman pacman(dataPool);
    pacman.eatPellet(pacmanPosition);

    // Check if the score is increased
    score_t newScore = dataPool.getScore();
    CHECK(newScore > 0);
}

TEST(pacman_tests, pacman_can_find_all_the_pellets_in_the_maze)
{
    DataPool &dataPool = DataPool::getInstance();
    EnvironmentGenerator envGen;

    // Load the maze -> set in datapool
    walls_t walls;
    envGen.loadMazeElementFromStringArray(MazeElementType::Walls, walls);
    dataPool.setWalls(walls);

    // load the pellets -> set in datapool
    pellets_t pellets;
    envGen.loadMazeElementFromStringArray(MazeElementType::Pellets, pellets);
    dataPool.setPellets(pellets);

    // create pacman
    Pacman pacman(dataPool);
    positionXY_t pacmanPosition = {13, 23}; 
    dataPool.setPacmanPosition(pacmanPosition);

    // have pacman move around in the maze eventually eating all the pellets
    const int nofIterations = 100000;
    for (int i = 0; i < nofIterations; ++i)
    {
        ctrlInput controlInput = static_cast<ctrlInput>(rand() % static_cast<int>(ctrlInput::LAST_ENTRY));
        dataPool.setControlInputs(controlInput);

        Pacman pacman(dataPool);
        pacman.update();

        // Run integrity check - no asserts must be triggered
        dataPool.runIntegrityChecks();
    }

    // Make sure that there are no pellets left
    pellets = dataPool.getPellets();
    bool isPelletLeft = false;
    for (size_t i = 0; i < pellets.size(); i++) {
        for (size_t j = 0; j < pellets[i].size(); j++) {
            if (pellets[i][j] == 1) {
                isPelletLeft = true;
            }
        }
    }
    CHECK_FALSE(isPelletLeft);

    score_t score =  dataPool.getScore();
    CHECK(score == 2560);
}

TEST(pacman_tests, pacman_sets_direction)
{
    DataPool &dataPool = DataPool::getInstance();
    positionXY_t pacmanPosition = {1, 1}; // Position where there is also a power pellet
    dataPool.setPacmanPosition(pacmanPosition);
    dataPool.setControlInputs(ctrlInput::Right);
    dataPool.setPacmanDirection(pacmanDirection::Right);
}
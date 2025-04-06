#include <iostream>
#include "custom_assert.h"
#include "custom_assert_mock.h"
#include "message_data_types.h"
#include "topic_definitions.h"
#include "pacman.h"
#include "data_pool.h"

#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"

// clang-format off
TEST_GROUP(pacman_tests){
    void setup(){
        mock().clear(); // Mock-Daten vor jedem Test zurücksetzen
    }
    void teardown()
    {
        mock().clear();
    }
};
// clang-format on

static const std::string testMaze[NOF_ROWS] = {
    "##########",
    "#        #",
    "# ## ### #",
    "#        #",
    "# ### ## #",
    "#        #",
    "# ## ### #",
    "#        #",
    "##########",
    "          "
};

void loadWallsFromStringArray(const std::string maze[NOF_ROWS], Walls& walls) {
    for (std::size_t i = 0; i < NOF_ROWS; ++i) {
        std::string row;
        for (std::size_t j = 0; j < NOF_COLUMNS; ++j) {
            row += (maze[i][j] == '#' ? '1' : '0'); // Convert '#' to '1' and space to '0'
        }
        walls[i] = std::bitset<NOF_COLUMNS>(row); // Assign the converted row to the walls
    }
}

TEST(pacman_tests, pacman_can_change_coordinates_with_move_function) {
    // set up the datapool
    DataPool& dataPool = DataPool::getInstance();
    positionXY pacmanPosition = {1, 1}; // Initial position
    dataPool.setPacmanPosition(pacmanPosition);

    // set up the control input
    ctrlInput controlInput = ctrlInput::Right;

    // initialize pacman with said datapool
    Pacman pacman(dataPool);

    // Call the move function
    positionXY newPosition = pacman.move(controlInput, pacmanPosition);

    // Check if the new position is correct
    CHECK_EQUAL(2, newPosition.x);
    CHECK_EQUAL(1, newPosition.y);
} 

TEST(pacman_tests, can_move_around_in_a_maze)
{
    Walls walls;
    // Generate a maze with 10 columns and 10 rows
    loadWallsFromStringArray(testMaze, walls);

    // Set the walls in the DataPool
    DataPool& dataPool = DataPool::getInstance();
    dataPool.setWalls(walls);

    dataPool.setPacmanPosition({1,1});

    // Set the control input
    ctrlInput controlInput = ctrlInput::Right;
    dataPool.setControlInputs(controlInput);

    // initialize pacman with said datapool
    Pacman pacman(dataPool);
    pacman.update();

    positionXY updatedPosition = dataPool.getPacmanPosition();
    
    CHECK(updatedPosition.x == 2);
    CHECK(updatedPosition.y == 1);   
}

TEST(pacman_tests, moving_pacman_through_the_maze_does_not_trigger_assert) {
    // have pacman run move throught the maze with many random moves
    // At each iteration run the integrity check -> which must not be triggered

    Walls walls;
    loadWallsFromStringArray(testMaze, walls);
    DataPool& dataPool = DataPool::getInstance();
    dataPool.setWalls(walls);
    dataPool.setPacmanPosition({1, 1});

    const int nofIterations = 100;

    for (int i = 0; i < nofIterations; ++i) {
        ctrlInput controlInput = static_cast<ctrlInput>(rand() % static_cast<int>(ctrlInput::LAST_INPUT));
        dataPool.setControlInputs(controlInput);

        // initialize pacman with said datapool
        Pacman pacman(dataPool);
        pacman.update();

        // run integrity check - no asserts must be triggered
        dataPool.runIntegrityChecks();
    }
}

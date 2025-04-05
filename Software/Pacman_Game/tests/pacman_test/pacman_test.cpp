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

TEST(pacman_tests, can_move_around_in_a_maze)
{
    // set up the maze for the datapool
    // set up the walls
    // set up the pacman position
    // set up the control input
    // set up the pacman object
    // get the datapool instance
    // DataPool& dataPool = DataPool::getInstance();
    Walls walls;
    // Generate a maze with 10 columns and 10 rows
    loadWallsFromStringArray(testMaze, walls);

    // Set the walls in the DataPool
    DataPool& dataPool = DataPool::getInstance();
    dataPool.setWalls(walls);

    // Set the pacman position
    positionXY pacmanPosition = {1, 1}; 
    dataPool.setPacmanPosition(pacmanPosition);

    // Set the control input
    ctrlInput controlInput = ctrlInput::Right;
    dataPool.setControlInputs(controlInput);

    // initialize pacman with said datapool
    Pacman pacman(dataPool);
    // Call the update function
    pacman.update();

    // Check the new position of Pacman
    positionXY newPosition = dataPool.getPacmanPosition();
    
    CHECK_EQUAL(2, newPosition.x); 
    CHECK_EQUAL(1, newPosition.y); 
}

#include <iostream>
#include <string>
#include "custom_assert.h"
#include "custom_assert_mock.h"
#include "common_types.h"
#include "environment_generator.h"
#include "AStar.hpp"


#include "CppUTestExt/MockSupport.h"
#include "CppUTest/TestHarness.h"

// clang-format off
TEST_GROUP(a_star_tests){
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

TEST(a_star_tests, test_a_star_with_path)
{
    constexpr int WORLD_SIZE_X = 20;
    constexpr int WORLD_SIZE_Y = 20;
    constexpr int WALL_Y = 10;
    constexpr int WALL_GAP_X = 5;
    const AStar::Vec2i START_POSITION = {0, 0};
    const AStar::Vec2i TARGET_POSITION = {19, 19};

    AStar::Generator generator;
    generator.setWorldSize({WORLD_SIZE_X, WORLD_SIZE_Y}); // Set world size
    generator.setHeuristic(AStar::Heuristic::euclidean);
    generator.setDiagonalMovement(true);

    // Create a wall in the middle of the grid
    for (int x = 0; x < WORLD_SIZE_X; ++x) {
        generator.addCollision({x, WALL_Y}); // Wall at y = WALL_Y
    }

    // Remove a gap in the wall to test the algorithm
    generator.removeCollision({WALL_GAP_X, WALL_Y}); // Opening at (WALL_GAP_X, WALL_Y)

    auto path = generator.findPath(START_POSITION, TARGET_POSITION); // Path from START_POSITION to TARGET_POSITION

    // // Make sure that the last coordinate is the target
    CHECK_EQUAL(path.back().x, TARGET_POSITION.x);
    CHECK_EQUAL(path.back().y, TARGET_POSITION.y);
}

TEST(a_star_tests, test_a_start_with_maze) {
    std::array<std::bitset<NOF_COLUMNS>, NOF_ROWS> walls;
    EnvironmentGenerator envGen;
    envGen.loadMazeElementFromStringArray(MazeElementType::Walls, walls);

    const AStar::Vec2i START_POSITION = {1, 1};
    const AStar::Vec2i TARGET_POSITION = {26, 29};  

    AStar::Generator a_star;
    a_star.setWorldSize({NOF_COLUMNS, NOF_ROWS}); // Set world size
    a_star.setHeuristic(AStar::Heuristic::euclidean);

    // Create a wall where the maze is
    for (int row = 0; row < NOF_ROWS; ++row) {
        for (int column = 0; column < NOF_COLUMNS; ++column) {
            if (walls[row][column]) {
                a_star.addCollision({column, row}); // Wall at (x, y)
            }
        }
    }
    auto path = a_star.findPath(START_POSITION, TARGET_POSITION); // Path from START_POSITION to TARGET_POSITION

    // Print the maze with the path
    for (int row = 0; row < NOF_ROWS; ++row) {
        for (int column = 0; column < NOF_COLUMNS; ++column) {
            if (walls[row][column]) {
                std::cout << "#"; // Wall
            } else if (std::find(path.begin(), path.end(), AStar::Vec2i{column, row}) != path.end()) {
                std::cout << "."; // Path
            } else {
                std::cout << " "; // Empty space
            }
        }
        std::cout << std::endl;
    }

    // Make sure that the last coordinate is the target
    CHECK_EQUAL(path.back().x, TARGET_POSITION.x);
    CHECK_EQUAL(path.back().y, TARGET_POSITION.y);
}


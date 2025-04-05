#include <iostream>
#include "custom_assert.h"
#include "custom_assert_mock.h"
#include "common_types.h"
#include "data_pool.h"

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
    const std::size_t NOF_ROWS = 5;
    const std::size_t NOF_COLUMNS = 5;

    // Create a random 5x5 maze (needs to fit into Walls datastructure)
    auto& dataPool = DataPool<NOF_ROWS, NOF_COLUMNS>::getInstance();
    Walls<NOF_ROWS, NOF_COLUMNS> walls;
    walls[0] = std::bitset<NOF_COLUMNS>("11111");
    walls[1] = std::bitset<NOF_COLUMNS>("10001");
    walls[2] = std::bitset<NOF_COLUMNS>("10101");
    walls[3] = std::bitset<NOF_COLUMNS>("10001");
    walls[4] = std::bitset<NOF_COLUMNS>("11111");
    dataPool.setWalls(walls);

    // Check if the walls are set correctly
    const Walls<NOF_ROWS, NOF_COLUMNS>& retrievedWalls = dataPool.getWalls();
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

TEST(DataPool_test, isWallAt_returns_true_for_wall_positions)
{
    const std::size_t NOF_ROWS = 5;
    const std::size_t NOF_COLUMNS = 5;

    // Create a random 5x5 maze (needs to fit into Walls datastructure)
    auto& dataPool = DataPool<NOF_ROWS, NOF_COLUMNS>::getInstance();
    Walls<NOF_ROWS, NOF_COLUMNS> walls;
    walls[0] = std::bitset<NOF_COLUMNS>("11111");
    walls[1] = std::bitset<NOF_COLUMNS>("10001");
    walls[2] = std::bitset<NOF_COLUMNS>("10101");
    walls[3] = std::bitset<NOF_COLUMNS>("10001");
    walls[4] = std::bitset<NOF_COLUMNS>("11111");
    dataPool.setWalls(walls);

    // Check if the isWallAt function returns true for wall positions
    position pos;
    pos.x = 0;
    pos.y = 0;
    CHECK(dataPool.isWallAt(pos));

    pos.x = 2;
    pos.y = 2;
    CHECK(dataPool.isWallAt(pos));

    pos.x = 4;
    pos.y = 4;
    CHECK(dataPool.isWallAt(pos));
}
TEST(DataPool_test, isWallAt_returns_false_for_non_wall_positions)
{
    const std::size_t NOF_ROWS = 5;
    const std::size_t NOF_COLUMNS = 5;

    // Create a random 5x5 maze (needs to fit into Walls datastructure)
    auto& dataPool = DataPool<NOF_ROWS, NOF_COLUMNS>::getInstance();
    Walls<NOF_ROWS, NOF_COLUMNS> walls;
    walls[0] = std::bitset<NOF_COLUMNS>("11111");
    walls[1] = std::bitset<NOF_COLUMNS>("10001");
    walls[2] = std::bitset<NOF_COLUMNS>("10101");
    walls[3] = std::bitset<NOF_COLUMNS>("10001");
    walls[4] = std::bitset<NOF_COLUMNS>("11111");
    dataPool.setWalls(walls);

    // Check if the isWallAt function returns false for non-wall positions
    position pos;
    pos.x = 1;
    pos.y = 2;
    CHECK(!dataPool.isWallAt(pos));

    pos.x = 2;
    pos.y = 1;
    CHECK(!dataPool.isWallAt(pos));

    pos.x = 3;
    pos.y = 3;
    CHECK(!dataPool.isWallAt(pos));
}

TEST(DataPool_test, isWallAt_throws_assertion_error_for_out_of_bounds)
{
    const std::size_t NOF_ROWS = 5;
    const std::size_t NOF_COLUMNS = 5;

    // Create a random 5x5 maze (needs to fit into Walls datastructure)
    auto& dataPool = DataPool<NOF_ROWS, NOF_COLUMNS>::getInstance();
    Walls<NOF_ROWS, NOF_COLUMNS> walls;
    walls[0] = std::bitset<NOF_COLUMNS>("11111");
    walls[1] = std::bitset<NOF_COLUMNS>("10001");
    walls[2] = std::bitset<NOF_COLUMNS>("10101");
    walls[3] = std::bitset<NOF_COLUMNS>("10001");
    walls[4] = std::bitset<NOF_COLUMNS>("11111");
    dataPool.setWalls(walls);

    // Check if the isWallAt function throws an assertion error for out-of-bounds positions
    position pos;
    pos.x = NOF_ROWS + 1; // Out of bounds
    pos.y = 0;
    mock_verifyAssertWasTriggered(
        "pos.x < NOF_ROWS && pos.y < NOF_COLUMNS",
        [&dataPool, &pos]()
        { dataPool.isWallAt(pos); });
}
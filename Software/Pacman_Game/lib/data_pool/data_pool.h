#pragma once
#include <bitset>
#include <array>
#include "common_types.h"
#include "custom_assert.h"


struct positionXY {
    u8 x;
    u8 y;
};

#define NOF_ROWS 10
#define NOF_COLUMNS 10

using Walls = std::array<std::bitset<NOF_COLUMNS>, NOF_ROWS>;

class DataPool
{
public:
    // Singleton instance accessor
    static DataPool& getInstance();

    // Delete copy constructor and assignment operator to enforce Singleton
    DataPool(const DataPool&) = delete;
    DataPool& operator=(const DataPool&) = delete;

    // Getter and Setter for Walls
    void setWalls(const Walls& inputWalls);
    const Walls& getWalls() const;

    // Check if a wall exists at a specific position
    bool isWallAt(positionXY pos) const;

private:
    // Private constructor and destructor for Singleton
    DataPool();
    ~DataPool();

    Walls walls; // Stores the walls as a 2D bitset
};
#pragma once
#include <bitset>
#include <array>
#include "common_types.h"
#include "custom_assert.h"
#include "custom_data_types.h"


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

    void setWalls(const Walls& inputWalls);
    const Walls& getWalls() const;

    void setControlInputs(ctrlInput input);
    ctrlInput getControlInputs() const;

    void setPacmanPosition(positionXY pos);
    positionXY getPacmanPosition() const;

    // Check if a wall exists at a specific position
    bool isWallAt(positionXY pos) const;

    // bool isPelletAt(positionXY pos) const;
    // bool isGhostAt(ghostType ghost, positionXY);

    void runIntegrityChecks() const;

private:
    // Private constructor and destructor for Singleton
    DataPool();
    ~DataPool();

    Walls walls;
    ctrlInput controlInput;
    positionXY pacmanPosition;
};
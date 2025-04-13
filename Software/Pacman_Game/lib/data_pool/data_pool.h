#pragma once
#include <bitset>
#include <array>
#include "common_types.h"
#include "custom_assert.h"
#include "custom_data_types.h"
#include "environment_generator.h"
#include "AStar.hpp"

using walls_t = std::array<std::bitset<NOF_COLUMNS>, NOF_ROWS>;
using pellets_t = std::array<std::bitset<NOF_COLUMNS>, NOF_ROWS>;
using score_t = u32;

class DataPool
{
public:
    // Singleton instance accessor
    static DataPool& getInstance();

    // Delete copy constructor and assignment operator to enforce Singleton
    DataPool(const DataPool&) = delete;
    DataPool& operator=(const DataPool&) = delete;

    void setWalls(const walls_t& inputWalls);
    const walls_t& getWalls() const;

    void setPellets(const pellets_t& inputPellets);
    const pellets_t& getPellets() const;

    void setScore(score_t score);
    score_t getScore() const;

    void setControlInputs(ctrlInput input);
    ctrlInput getControlInputs() const;

    void setPacmanPosition(positionXY_t pos);
    positionXY_t getPacmanPosition() const;

    void setPacmanDirection(pacmanDirection direction);
    pacmanDirection getPacmanDirection() const;

    void 

    // Check if a wall exists at a specific position
    bool isWallAt(positionXY_t pos) const;
    bool isPelletAt(positionXY_t pos) const;

    
    // bool isGhostAt(ghostType ghost, positionXY);

    void runIntegrityChecks() const;

private:
    // Private constructor and destructor for Singleton
    DataPool();
    ~DataPool();

    walls_t walls;
    pellets_t pellets;
    
    ctrlInput controlInput;
    positionXY_t pmPosition;
    pacmanDirection pmDirection;
    score_t score;
};
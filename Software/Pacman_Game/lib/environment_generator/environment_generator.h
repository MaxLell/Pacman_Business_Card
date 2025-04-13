#pragma once
#include <bitset>
#include <array>
#include "environment_maze.h"
#include "AStar.hpp"

enum class MazeElementType
{
    Walls,
    Pellets
};

class EnvironmentGenerator
{
private:
    /* data */
public:
    EnvironmentGenerator(/* args */);
    ~EnvironmentGenerator();

    void loadMazeElementFromStringArray(MazeElementType type, std::array<std::bitset<NOF_COLUMNS>, NOF_ROWS> &inoutElement);

    void loadMazeIntoPathFinding(AStar::Generator& inout_aStarAlgorithm);
    
};

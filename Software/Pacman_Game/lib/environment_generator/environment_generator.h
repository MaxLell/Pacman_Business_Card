#pragma once
#include "data_pool.h"

class EnvironmentGenerator
{
private:
    /* data */
public:
    EnvironmentGenerator(/* args */);
    ~EnvironmentGenerator();

    // generate walls from string
    void loadWallsFromStringArray(const std::string maze[NOF_ROWS], Walls& inoutWalls);

    // generatePellets
    void loadPelletsFromStringArray(const std::string maze[NOF_ROWS], Pellets& inoutPellets);

    // generateSuperPellet
};


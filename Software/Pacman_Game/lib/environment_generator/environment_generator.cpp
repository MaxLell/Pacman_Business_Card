#include "environment_generator.h"

EnvironmentGenerator::EnvironmentGenerator(/* args */)
{
}

EnvironmentGenerator::~EnvironmentGenerator()
{
}

void EnvironmentGenerator::loadWallsFromStringArray(const std::string maze[NOF_ROWS], Walls &walls)
{
    bool addedBit = false;
    for (std::size_t i = 0; i < NOF_ROWS; ++i)
    {
        std::string row;
        for (std::size_t j = 0; j < NOF_COLUMNS; ++j)
        {
            if (maze[i][j] == '#')
            {
                row += '1';
                addedBit = true;
            }
            else
            {
                row += '0';
            }
        }
        walls[i] = std::bitset<NOF_COLUMNS>(row); // Assign the converted row to the walls
    }
    ASSERT(addedBit);   
}

void EnvironmentGenerator::loadPelletsFromStringArray(const std::string maze[NOF_ROWS], Pellets &pellets)
{
    bool addedBit = false;
    for (std::size_t i = 0; i < NOF_ROWS; ++i)
    {
        std::string row;
        for (std::size_t j = 0; j < NOF_COLUMNS; ++j)
        {
            if (maze[i][j] == '.')
            {
                row += '1';
                addedBit = true;
            }
            else
            {
                row += '0';
            }
        }
        pellets[i] = std::bitset<NOF_COLUMNS>(row); // Assign the converted row to the pellets
    }
    ASSERT(addedBit);
}
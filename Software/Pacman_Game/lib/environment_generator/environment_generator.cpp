#include "environment_generator.h"
#include "custom_assert.h"

EnvironmentGenerator::EnvironmentGenerator(/* args */)
{
}

EnvironmentGenerator::~EnvironmentGenerator()
{
}

void EnvironmentGenerator::loadMazeElementFromStringArray(MazeElementType type, std::array<std::bitset<NOF_COLUMNS>, NOF_ROWS> &inoutElement)
{
    

    bool addedBit = false;
    for (std::size_t i = 0; i < NOF_ROWS; ++i)
    {
        std::string row;
        for (std::size_t j = 0; j < NOF_COLUMNS; ++j)
        {
            if ((type == MazeElementType::Walls && environmentMaze[i][j] == '#') ||
                (type == MazeElementType::Pellets && environmentMaze[i][j] == '.'))
            {
                row += '1';
                addedBit = true;
            }
            else
            {
                row += '0';
            }
        }
        inoutElement[i] = std::bitset<NOF_COLUMNS>(row);
    }
    ASSERT(addedBit);
}
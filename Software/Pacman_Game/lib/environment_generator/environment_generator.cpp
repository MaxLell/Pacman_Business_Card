#include "environment_generator.h"

#include "custom_assert.h"

EnvironmentGenerator::EnvironmentGenerator(/* args */) {}

EnvironmentGenerator::~EnvironmentGenerator() {}

void EnvironmentGenerator::loadMazeElementFromStringArray(
    MazeElementType type,
    std::array<std::bitset<NOF_COLUMNS>, NOF_ROWS>& inoutElement) {
  bool addedBit = false;
  for (std::size_t i = 0; i < NOF_ROWS; ++i) {
    std::string row;
    for (std::size_t j = 0; j < NOF_COLUMNS; ++j) {
      if ((type == MazeElementType::Walls && environmentMaze[i][j] == '#') ||
          (type == MazeElementType::Pellets && environmentMaze[i][j] == '.')) {
        row += '1';
        addedBit = true;
      } else {
        row += '0';
      }
    }
    inoutElement[i] = std::bitset<NOF_COLUMNS>(row);
  }
  ASSERT(addedBit);
}

void EnvironmentGenerator::loadMazeIntoPathFinding(AStar::Generator& inout_aStarAlgorithm) {
  std::array<std::bitset<NOF_COLUMNS>, NOF_ROWS> walls;
  loadMazeElementFromStringArray(MazeElementType::Walls, walls);

  inout_aStarAlgorithm.setWorldSize({NOF_COLUMNS, NOF_ROWS});  // Set world size
  inout_aStarAlgorithm.setHeuristic(AStar::Heuristic::euclidean);

  // Create a wall where the maze is
    for (int row = 0; row < NOF_ROWS; ++row) {
        for (int column = 0; column < NOF_COLUMNS; ++column) {
            if (walls[static_cast<std::size_t>(row)][static_cast<std::size_t>(column)]) {
                inout_aStarAlgorithm.addCollision({column, row}); // Wall at (x, y)
            }
        }
    }
}
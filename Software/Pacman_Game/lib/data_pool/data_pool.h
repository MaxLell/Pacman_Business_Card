#pragma once
#include <bitset>
#include <array>
#include "common_types.h"
#include "assert.h"

enum class Entity {
    PacMan = 0,
    Wall,
};

struct position {
    u8 x;
    u8 y;
};

template<std::size_t NOF_ROWS, std::size_t NOF_COLUMNS>
using Walls = std::array<std::bitset<NOF_COLUMNS>, NOF_ROWS>;

template<std::size_t NOF_ROWS, std::size_t NOF_COLUMNS>
class DataPool
{
public:
    // Singleton-Pattern    
    static DataPool& getInstance() {
        static DataPool instance; 
        return instance;
    }

    DataPool(const DataPool&) = delete;
    DataPool& operator=(const DataPool&) = delete;

    // Getters and Setters
    void setWalls(Walls<NOF_ROWS, NOF_COLUMNS>& inputWalls) {
        walls = inputWalls;
    }

    const Walls<NOF_ROWS, NOF_COLUMNS>& getWalls(void) const {
        return walls;
    }

    bool isWallAt(position pos) const {
        ASSERT(pos.x < NOF_ROWS && pos.y < NOF_COLUMNS);
        return walls[pos.x][pos.y];
    }

private:
    DataPool() {
        // Initialize walls with all bits set to 0 (no walls)
        for (auto& row : walls) {
            row.reset();
        }
    }

    ~DataPool() {
        // Destructor (no dynamic memory to clean up)
    }

    // Private data
    Walls<NOF_ROWS, NOF_COLUMNS> walls;
};
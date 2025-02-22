#pragma once

#include "types.h"

struct Coordinate
{
    u8 x;
    u8 y;
};

class DataPool
{
private:
    Coordinate pacman_position;
public:
    DataPool(/* args */);
    ~DataPool();

    void setPacmanPosition(u8 x, u8 y);
    Coordinate getPacmanPosition() const;
};


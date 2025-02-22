#pragma once

#include "types.h"

struct Coordinate
{
    u8 x;
    u8 y;
};

class GameState
{
private:
    Coordinate pacman_position;
public:
    GameState(/* args */);
    ~GameState();

    void setPacmanPosition(u8 x, u8 y);
    Coordinate getPacmanPosition() const;
};
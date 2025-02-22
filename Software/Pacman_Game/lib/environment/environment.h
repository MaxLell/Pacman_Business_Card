#pragma once

#include "types.h"


enum class Input
{
    ArrowUp,
    ArrowDown,
    ArrowLeft,
    ArrowRight,
    NoInput
};

struct Coordinate
{
    u8 x;
    u8 y;
};

class Environment
{
private:
    Coordinate pacman_position;
public:
    Environment(/* args */);
    ~Environment();

    void setPacmanPosition(u8 x, u8 y);
    Coordinate getPacmanPosition() const;
};
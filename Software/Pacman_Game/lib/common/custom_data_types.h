#pragma once
#include "common_types.h"

enum class ctrlInput {
    Up,
    Down,
    Left,
    Right,
    LAST_ENTRY
};

enum class pacmanDirection {
    Up,
    Down,
    Left,
    Right,
    LAST_ENTRY
};

// x -> y
struct positionXY_t {
    s8 x;
    s8 y;
};
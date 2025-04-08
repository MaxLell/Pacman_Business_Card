#pragma once

enum class ctrlInput {
    Up,
    Down,
    Left,
    Right,
    LAST_INPUT
};

// x -> y
struct positionXY_t {
    s8 x;
    s8 y;
};
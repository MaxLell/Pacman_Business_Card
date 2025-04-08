#pragma once

enum class ctrlInput {
    Up,
    Down,
    Left,
    Right,
    LAST_INPUT
};

// x -> y
struct positionXY {
    s8 x;
    s8 y;
};
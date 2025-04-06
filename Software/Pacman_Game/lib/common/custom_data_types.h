#pragma once

enum class ctrlInput {
    Up,
    Down,
    Left,
    Right,
    LAST_INPUT
};

struct positionXY {
    u8 x;
    u8 y;
};
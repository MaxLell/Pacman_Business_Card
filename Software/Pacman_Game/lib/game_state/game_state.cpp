#include "game_state.h"
#include "assert.h"

GameState::GameState(/* args */)
{
    // Initialisiere die Pacman-Position, z.B. auf (0, 0)
    pacman_position = {0, 0};
}

GameState::~GameState()
{
}

void GameState::setPacmanPosition(u8 x, u8 y)
{
    ASSERT(x != 0);
    ASSERT(y != 0);

    pacman_position.x = x;
    pacman_position.y = y;
}

Coordinate GameState::getPacmanPosition() const
{
    return pacman_position;
}
#include "environment.h"
#include "assert.h"

Environment::Environment(/* args */)
{
    // Initialisiere die Pacman-Position mit Standardwerten
    pacman_position = {0, 0};
}

Environment::~Environment()
{
}

void Environment::setPacmanPosition(u8 x, u8 y)
{
    ASSERT(x != 0);
    ASSERT(y != 0);

    pacman_position.x = x;
    pacman_position.y = y;
}

Coordinate Environment::getPacmanPosition() const
{
    return pacman_position;
}
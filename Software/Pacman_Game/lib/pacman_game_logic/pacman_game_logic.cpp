#include "pacman_game_logic.h"
#include "assert.h"

PacmanGameLogic::PacmanGameLogic(/* args */)
{
}

PacmanGameLogic::~PacmanGameLogic()
{
}

bool PacmanGameLogic::isGameOver()
{
    return false;
}

void PacmanGameLogic::update(Environment &env, Input input)
{
    // update the environment based on the input
    switch (input)
    {
    case Input::ArrowUp:
        env.setPacmanPosition(env.getPacmanPosition().x, env.getPacmanPosition().y - 1);
        break;
    case Input::ArrowDown:
        env.setPacmanPosition(env.getPacmanPosition().x, env.getPacmanPosition().y + 1);
        break;
    case Input::ArrowLeft:
        env.setPacmanPosition(env.getPacmanPosition().x - 1, env.getPacmanPosition().y);
        break;
    case Input::ArrowRight:
        env.setPacmanPosition(env.getPacmanPosition().x + 1, env.getPacmanPosition().y);
        break;
    case Input::NoInput:
        break;
    default:
        ASSERT(false); // Must never happen
        break;
    }
}

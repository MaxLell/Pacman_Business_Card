#include "pacman.h"
#include "assert.h"

Pacman::Pacman(MessageBroker<PacmanLogicTopics, 5> messageBroker) : mb(messageBroker)
{
    // subscribe to configured Walls -> Updates the private member reference

    // subscribe to  control inputs

    // subscribe to initial pacman position
}

Pacman::~Pacman()
{
}



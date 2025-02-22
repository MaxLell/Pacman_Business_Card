#pragma once

#include "environment.h"

class PacmanGameLogic
{
private:
    /* data */
public:
    PacmanGameLogic(/* args */);
    ~PacmanGameLogic();

    bool isGameOver();

    void update(Environment& env, Input input);
};


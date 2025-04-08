#pragma once
#include "data_pool.h"

class Pacman
{
public:
    Pacman(DataPool& dP);
    ~Pacman();

    void update();

    positionXY_t move(ctrlInput input, positionXY_t currentPosition);

    void eatPellet(positionXY_t currentPosition);

    // void eatPowerPellet();

    // void eatGhost(ghostType ghost);

private:
    DataPool& dataPool;
};


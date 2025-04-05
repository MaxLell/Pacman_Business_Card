#pragma once
#include "data_pool.h"


class Pacman
{
public:
    Pacman(DataPool& dP);
    ~Pacman();

    void update();

    positionXY move(ctrlInput input, positionXY currentPosition);

    // void eatPellet();

    // void eatPowerPellet();

    // void eatGhost(ghostType ghost);

private:
    DataPool& dataPool;
};


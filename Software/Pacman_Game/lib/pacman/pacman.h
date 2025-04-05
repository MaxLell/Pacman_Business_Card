#pragma once
#include "data_pool.h"


class Pacman
{
public:
    Pacman();
    ~Pacman();

    // void update();

    // controlInputs getControlInput();

    // positionXY move(controlInputs input, positionXY currentPosition);

    // bool isWallAt(positionXY position);


private:

};

/**
 * How it shall look like:
 */

/*
void Pacman::update() {
    controlInput = getControlInput();

    updatedPosition = move(controlInput, currentPosition);

    if (isWallAt(updatedPosition)) {
        // Falls Pacman gegen eine Wand läuft, Bewegung rückgängig machen
        updatedPosition = undoMove(currentPosition);
    }

    if (isPelletAt(updatedPosition)) {
        eatPellet();
    }

    if (isSuperPelletAt(updatedPosition)) {
        eatPowerPellet();
    }

    for (Ghost& ghost : ghosts)
    if (isGhostAt(ghost, updatedPosition)) {
        if(isGhostScared(ghost)) 
        {
            eatGhost(ghost);
        } else {
            die();
        }
    }

}

    */
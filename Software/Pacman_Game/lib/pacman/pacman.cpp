#include "pacman.h"
#include "custom_assert.h"

Pacman::Pacman(DataPool &dP)
    : dataPool(dP) // Initialisiere die Referenz auf den DataPool
{
    // Hier können zusätzliche Initialisierungen vorgenommen werden, falls nötig
}

Pacman::~Pacman()
{
}

void Pacman::update()
{
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

        

        if (isSuperPelletAt(updatedPosition)) {
            eatPowerPellet();
        }

        
    }    */

    ctrlInput controlInput = dataPool.getControlInputs();

    positionXY currentPosition = dataPool.getPacmanPosition();
    positionXY updatedPosition = move(controlInput, currentPosition);

    if (dataPool.isWallAt(updatedPosition))
    {
        return; // Do nothing else in this function
    }

    // update pacman's position
    dataPool.setPacmanPosition(updatedPosition);

    /*
    if (isPelletAt(updatedPosition)) {
        eatPellet();
    }
    */

    /*
    if (isSuperPelletAt(updatedPosition)) {
        eatPowerPellet();
    }
    */

    /*
    for (Ghost& ghost : ghosts)
        if (isGhostAt(ghost, updatedPosition)) {
            if(isGhostScared(ghost))
            {
                eatGhost(ghost);
            } else {
                die();
            }
        }
    */

    dataPool.runIntegrityChecks();
}

positionXY Pacman::move(ctrlInput input, positionXY currentPosition)
{
    positionXY newPosition = currentPosition;

    switch (input)
    {
    case ctrlInput::Up:
        newPosition.y--;
        break;
    case ctrlInput::Down:
        newPosition.y++;
        break;
    case ctrlInput::Left:
        newPosition.x--;
        break;
    case ctrlInput::Right:
        newPosition.x++;
        break;
    default:
        break; // Keine Bewegung
    }
    return newPosition;
}

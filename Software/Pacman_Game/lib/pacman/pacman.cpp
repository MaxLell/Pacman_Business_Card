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
    if (dataPool.isPelletAt(updatedPosition))
    {
        eatPellet(updatedPosition);
    }

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
        newPosition.y -= 1;
        if (newPosition.y < 0)
        {
            newPosition.y = NOF_COLUMNS - 1;
        }
        break;
    case ctrlInput::Down:
        newPosition.y += 1;
        if (newPosition.y >= NOF_COLUMNS)
        {
            newPosition.y = 0;
        }
        break;
    case ctrlInput::Left:
        newPosition.x -= 1;
        if (newPosition.x < 0)
        {
            newPosition.x = NOF_ROWS - 1;
        }
        break;
    case ctrlInput::Right:
        newPosition.x += 1;
        if (newPosition.x >= NOF_ROWS)
        {
            newPosition.x = 0;
        }
        break;
    default:
        // Invalid input, do nothing or handle error
        break;
    }

    return newPosition;
}

void Pacman::eatPellet(positionXY currentPosition)
{
    ASSERT(currentPosition.x >= 0 && currentPosition.x < NOF_ROWS);
    ASSERT(currentPosition.y >= 0 && currentPosition.y < NOF_COLUMNS);
    ASSERT(dataPool.isPelletAt(currentPosition));

    // Get the current score
    score_t currentScore = dataPool.getScore();

    // Increase the score by 1
    currentScore += 10;

    // Update the score in the DataPool
    dataPool.setScore(currentScore);

    // Remove the pellet from the DataPool
    pellets_t pellets = dataPool.getPellets();
    pellets[static_cast<std::size_t>(currentPosition.x)].set(static_cast<std::size_t>(currentPosition.y), false);
    dataPool.setPellets(pellets);

    ASSERT(!dataPool.isPelletAt(currentPosition));
}
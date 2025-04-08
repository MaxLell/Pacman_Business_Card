#pragma once

#include "custom_data_types.h"
#include "data_pool.h"

class Ghost {
public:
    Ghost(DataPool dp);
    virtual ~Ghost() = default;

    void update();

    virtual positionXY_t move(ctrlInput input, positionXY_t currentPosition) = 0;

    void gotEaten();

protected:
    DataPool& dataPool;

private:
    positionXY_t position;
    
};

// Blinky: Aggressiver Geist
class Blinky : public Ghost {
public:
    Blinky();
    void move(DataPool& dataPool) override;
};

// Pinky: Hinterhältiger Geist
class Pinky : public Ghost {
public:
    Pinky(positionXY_t startPosition);
    void move(DataPool& dataPool) override;
};

// Weitere Geister (Inky, Clyde, Sue) können ähnlich implementiert werden.
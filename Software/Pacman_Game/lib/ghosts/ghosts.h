#pragma once

#include "custom_data_types.h"
#include "data_pool.h"

class Ghost {
public:
    Ghost(DataPool dp);
    virtual ~Ghost() = default;

    void update();

private:
    positionXY_t position;
    DataPool& dataPool;
    
};
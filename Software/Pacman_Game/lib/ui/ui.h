#pragma once

#include "types.h"
#include "data_pool.h"

class UI
{
private:
    /* data */
public:
    UI(/* args */);
    ~UI();
    void generateOutputs(const DataPool &data_pool);
};

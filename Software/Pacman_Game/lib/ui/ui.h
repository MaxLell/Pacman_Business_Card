#pragma once

#include "types.h"
#include "environment.h"

class UI
{
private:
    /* data */
public:
    UI(/* args */);
    ~UI();
    void render(const Environment &env);
    bool isTerminated();
};

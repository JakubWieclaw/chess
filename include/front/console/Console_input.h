#pragma once

#include "Move.h"
#include "Input.h"

class Console_input: public Input
{
    public:
    Move get_move();
    private:
};
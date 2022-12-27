#pragma once

#include "engine/Board.h"
#include "Console_drawer.h"
#include "Console_input.h"
#include "File_input.h"

class Console_front
{
    public:
    void start_game(Board &board);
    private:
    Console_drawer drawer;
    Console_input input;
    File_input f_input;
};
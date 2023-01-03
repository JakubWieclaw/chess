#pragma once

#include "engine/Board.h"
#include "Console_drawer.h"
#include "Console_input.h"
#include "File_input.h"
#include "Input.h"

class Console_front
{
    public:
    Console_front(Input &input);
    void start_game(Board &board);
    private:
    Console_drawer drawer;
    Input &input;
    //File_input f_input;
};
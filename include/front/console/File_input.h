#pragma once

#include "Move.h"
#include "Input.h"

#include <fstream>

class File_input: public Input
{
    public:
    File_input(std::istream &f);
    Move get_move();
    private:
    std::istream &f;
};
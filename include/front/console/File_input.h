#pragma once

#include "Move.h"
#include "Input.h"

#include <fstream>

class File_input: public Input
{
    public:
    Move get_move(std::ifstream &f);
    private:
};
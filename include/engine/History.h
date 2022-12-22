#pragma once

#include "Move.h"
#include <vector>
#include <string>

class History
{
    public:
    History();
    void add_move(Move move);
    std::vector<Move> get_moves();
    int get_size();
    Move get_back_element();
    private:
    std::vector<Move> moves;
    std::string file_name;
};
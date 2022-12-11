#pragma once

#include "Move.h"
#include <vector>

class History
{
    public:
    void add_move(Move move);
    std::vector<Move> get_moves();
    int get_size();
    Move get_back_element();
    private:
    std::vector<Move> moves;

};
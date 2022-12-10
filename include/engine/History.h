#pragma once

#include "Move.h"
#include <vector>

class History
{
    public:
    void add_move(Move move);
    std::vector<Move> get_moves();
    int get_size();
    private:
    std::vector<Move> moves;

};
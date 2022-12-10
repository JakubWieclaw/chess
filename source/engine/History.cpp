#pragma once

#include "Move.h"
#include <vector>

class History
{
    public:
    void add_move(Move move);
    std::vector<Move> get_moves();
    private:
    std::vector<Move> moves;

};
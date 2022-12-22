#include "Move.h"
#include <vector>
#include "engine/History.h"


void History::add_move(Move move)
{
    moves.push_back(move);
}
std::vector<Move> History::get_moves()
{
    return moves;
}
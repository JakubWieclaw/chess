#pragma once

#include "Field_info.h"
#include <array>
#include "Move.h"
#include "Game_state.h"
#include "History.h"
#include <string>
#include <utility>

class Board
{
public:
    void start(std::string path);
    std::array<std::array<Field_info, 8>, 8> get_state();
    bool make_move(Move move); // + check if legal
    Game_state game_result();
    Colour colour_turn();
private:
    std::array<std::array<Field_info, 8>, 8> chessboard;
    History history;
    Field_info &get(Field f);
    Field_info &get(int row, int col);
    bool check_rook_move(Field from, Field to);
    bool check_knight_move(Field from, Field to);
    bool check_bishop_move(Field from, Field to);
    bool check_queen_move(Field from, Field to);
    std::tuple<bool, bool, Move> check_king_move(Field from, Field to);
    bool check_pawn_move(Field from, Field to);
    void move_piece(Move move);
    Game_state current_state;
};
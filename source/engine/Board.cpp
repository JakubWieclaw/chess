#include "engine/Board.h"
#include <fstream>

Colour Board::colour_turn() // Whose turn is it - dumb, don't you think?
{
    return history.get_size() % 2 == 0 ? Colour::White : Colour::Black;
}

void Board::start(std::string path)
{
    std::ifstream file(path);
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            chessboard[i][j].f.row = i;
            chessboard[i][j].f.col = j;
            chessboard[i][j].occupied = true;
            char c = file.get();
            if (c == '\n')
            {
                c = file.get();
            }
            chessboard[i][j].p.colour = i < 4 ? Colour::White : Colour::Black;
            switch (c)
            {
            case 'r':
                chessboard[i][j].p.type = Piece_type::Rook;
                break;
            case 'n':
                chessboard[i][j].p.type = Piece_type::Knight;
                break;
            case 'b':
                chessboard[i][j].p.type = Piece_type::Bishop;
                break;
            case 'q':
                chessboard[i][j].p.type = Piece_type::Queen;
                break;
            case 'k':
                chessboard[i][j].p.type = Piece_type::King;
                break;
            case 'p':
                chessboard[i][j].p.type = Piece_type::Pawn;
                break;
            default:
                chessboard[i][j].p.type = Piece_type::None;
                chessboard[i][j].occupied = false;
            }
        }
    }
    // chessboard[0][0].p.type = Piece_type::Rook;
    // chessboard[0][0].p.colour = Colour::White;
    // chessboard[0][0].occupied = true;
}

Field_info &Board::get(Field f)
{
    return chessboard[f.row][f.col];
}
Field_info &Board::get(int row, int col)
{
    return chessboard[row][col];
}
std::array<std::array<Field_info, 8>, 8> Board::get_state()
{
    return chessboard;
}
bool checkCoord(int i)
{
    return i >= 0 && i < 8;
}
bool Board::make_move(Move move) // + check if legal
{
    Field from = move.from;
    Field to = move.to;
    if (!(checkCoord(from.row) && checkCoord(from.col) && checkCoord(to.row) && checkCoord(to.col))) // Wrong coords
    {
        return false;
    }

    if (!get(from).occupied) // Starting field is empty
    {
        return false;
    }
    if (get(from).p.colour != colour_turn()) // Not ur turn
    {
        return false;
    }
    if (get(to).occupied && get(to).p.colour == get(from).p.colour) // Same colour
    {
        return false;
    }

    bool is_move_legal;
    switch (get(from).p.type)
    {
    case Piece_type::Rook:
        is_move_legal = check_rook_move(move.from, move.to);
        break;
    case Piece_type::Knight:
        is_move_legal = check_knight_move(move.from, move.to);
        break;
    case Piece_type::Bishop:
        is_move_legal = check_bishop_move(move.from, move.to);
        break;
    case Piece_type::Queen:
        is_move_legal = check_queen_move(move.from, move.to);
        break;
    case Piece_type::King:
        std::tuple<bool, bool, Move> kings_move = check_king_move(move.from,move.to);
        is_move_legal = std::get<0>(kings_move);
        break;
    case Piece_type::Pawn:
        is_move_legal = check_pawn_move(move.from,move.to);
        break;
    default:
        is_move_legal = false;
    }
    if (!is_move_legal) // Checked if move is legal
    {
        return false;
    }
    // Empty "From" field, replace piece in "To" field
    // Add move to moves, consider castling and pawn promotion (change piece type)
    // Check whether King was attacked, end game if yes

}
Game_state Board::game_result()
{
}

bool Board::check_rook_move(Field from, Field to)
{
    if (from.row == to.row)
    {
        for (int i = from.col + 1; i < to.col; i++)
        {
            if (get(from.row, i).occupied)
            {
                return false;
            }
        }
    }
    else if (from.col == to.col)
    {
        for (int i = from.row + 1; i < to.row; i++)
        {
            if (get(i, from.col).occupied)
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}

bool check_knight_move(Field from, Field to)
{
    int diff_row = abs(from.row - to.row);
    int diff_col = abs(from.col - to.col);

    if (diff_row == 2 && diff_col == 1)
    {
        return true;
    }
    else if (diff_row == 1 && diff_col == 2)
    {
        return true;
    }
    return false;
}

bool Board::check_bishop_move(Field from, Field to)
{
    int diff_row = abs(from.row - to.row);
    int diff_col = abs(from.col - to.col);
    if (!(diff_row == diff_col))
    {
        return false;
    }
    int delta_row = to.row - from.row > 0 ? 1 : -1; // Check diagonal to move on
    int delta_col = to.col - from.col > 0 ? 1 : -1;

    Field temp =
        {
            from.row + delta_row,
            from.col + delta_col,
        };
    while (temp.row != to.row)
    {
        if (get(temp).occupied)
        {
            return false;
        }
        temp.row += delta_row;
        temp.col += delta_col;
    }
    return true;
}

bool Board::check_queen_move(Field from, Field to)
{
    return check_bishop_move(from, to) || check_rook_move(from, to);
}

std::tuple<bool, bool, Move> Board::check_king_move(Field from, Field to) // 0 - correct move, 1 - castling, 2 - rook move
{
    int diff_row = abs(from.row - to.row);
    int diff_col = abs(from.col - to.col);
    if (diff_row <= 1 || diff_col <= 1) // Normal move
    {
        return {true, false, Move()};
    }
    if (diff_col > 2 || diff_row != 0) // castle
    {
        return {false, false, Move()};
    }
    int starting_row = colour_turn() == Colour::White ? 0 : 7; // Castling
    Field starting_king_field = {starting_row, 4};

    // for (auto x:history.get_moves()) // Check if king moved before
    // {
    //     if (x.from == starting_king_field)
    //     {
    //         return false;
    //     }
    // }
    int diff_col = from.col - to.col;
    // Field starting_rook_field = [starting_row, diff_col]() -> Field {
    //     if(diff_col > 0) {
    //         return Field{starting_row, 7};
    //     } else {
    //         return Field{starting_row, 0};
    //     }
    // }();
    Field starting_rook_field;
    int king_direction;
    if (diff_col > 0)
    {
        starting_rook_field = {starting_row, 0};
        king_direction = -1;
    }
    else
    {
        starting_rook_field = {starting_row, 7};
        king_direction = 1;
    }

    for (auto x : history.get_moves()) // Check if king or rook moved before
    {
        if (x.from == starting_king_field)
        {
            return {false, false, Move()};
        }
        if (x.from == starting_rook_field || x.to == starting_rook_field) // Nothing moved to or from this field
        {
            return {false, false, Move()};
        }
    }

    for (int i = from.col + king_direction; i != starting_rook_field.col; i += king_direction) // To be continued... or not, missing check if in check
    {
        if (get(starting_row, i).occupied)
        {
            return {false, false, Move()};
        }
    }

    return {true, true, {starting_rook_field, {from.row, from.col + king_direction}}};
}

bool Board::check_pawn_move(Field from, Field to)
{
    int base_move_increment;
    if (get(from).p.colour == Colour::White)
    {
        base_move_increment = 1;
    }
    else
    {
        base_move_increment = -1;
    }

    if (!get(to).occupied && to.row == from.row + base_move_increment)
    {
        return true;
    }
    if (get(to).occupied && to.row == from.row + base_move_increment && (to.col == (from.col + 1) || to.col == (from.col - 1)))
    {
        return true;
    }

    bool has_moved = false;
    for (auto x : history.get_moves()) // Check if pawn moved before
    {
        if (x.from == from || x.to == from) // Nothing moved to or from this field
        {
            has_moved = true;
            break;
        }
    }
    if (!has_moved && to.row == from.row + 2 * base_move_increment && to.col == from.col) // double move
    {
        return true;
    }
    if (history.get_size() == 0) // en passaint impossible
    {
        return false;
    }
    Move prev_move = history.get_back_element();
    Field prev_move_to = prev_move.to;
    Field prev_move_from = prev_move.from;
    if (get(prev_move_to).p.type == Piece_type::Pawn && prev_move_to.row == prev_move_from.row + (-2) * base_move_increment) // prev move was dobule move pawn
    {
        if (from.row == prev_move_to.row && abs(from.col - prev_move_to.col) == 1 && to.row == from.row + base_move_increment && to.col == prev_move_to.col) // en passaint capture
        {
            return true;
        }
    }
    // TODO: PROMOTION

    return false;
}
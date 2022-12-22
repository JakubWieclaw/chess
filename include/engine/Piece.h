#pragma once

#include "Piece_type.h"

enum class Colour
{
    White, 
    Black,
    Empty
};

struct Piece
{
    Piece_type type;
    Colour colour;
};
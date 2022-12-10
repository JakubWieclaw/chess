#pragma once

#include "Piece_type.h"

enum class Colour
{
    White, 
    Black
};

struct Piece
{
    Piece_type type;
    Colour colour;
};
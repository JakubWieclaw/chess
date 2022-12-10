#pragma once

#include "Field.h"
#include "Piece.h"

struct Field_info
{
    Field f;
    Piece p;
    bool occupied;
    // is attacked ?
};

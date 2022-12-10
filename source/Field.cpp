#include "Field.h"

bool Field::operator==(Field f) const 
{
    return row == f.row && col == f.row;
}
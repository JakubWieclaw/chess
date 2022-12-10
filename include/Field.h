#pragma once


struct Field
{   
    int row;
    int col;

    bool operator==(Field f) const;
};
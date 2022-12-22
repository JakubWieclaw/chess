#pragma once

#include <array>
#include "engine/Field_info.h"

class Console_drawer
{
    public:
    void draw_state(std::array<std::array<Field_info,8>,8> game_state);
    private:

};
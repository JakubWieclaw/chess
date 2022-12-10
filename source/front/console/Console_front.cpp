#include "front/console/Console_front.h"


class Console_front
{
    public:
    void start_game(Board &board);
    private:
    Console_drawer drawer;
    Console_input input;
};
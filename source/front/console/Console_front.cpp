#include "front/console/Console_front.h"
#include <iostream>


// class Console_front
// {
//     public:
//     void start_game(Board &board);
//     private:
//     Console_drawer drawer;
//     Console_input input;
// };

Console_front::Console_front(Input &input):input(input)
{

}

void Console_front::start_game(Board &board)
{
    while (board.game_result() == Game_state::in_progress)
    {
        drawer.draw_state(board.get_state(), board.colour_turn());
        do
        {
            Move move = input.get_move();
            if (board.make_move(move))
            {
                break;
            }
            std::cout << "Illegal move" << std::endl;
        } while (true);
        
    }
    std::cout << "Game finished" << std::endl;
}
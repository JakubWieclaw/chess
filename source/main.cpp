#include "engine\Board.h"
#include "front\console\Console_front.h"
#include <fstream>

int main()
{
    Board board;
    board.start("board.txt");
    Console_front front;
    front.start_game(board);

    return 0;
}

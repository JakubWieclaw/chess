#include "engine\Board.h"
#include "front\console\Console_front.h"
#include <fstream>
#include <iostream>

int main()
{
    Board board;
    board.start("board.txt");
    std::string test;
    std::cout << "Choose input type:\n0 - console\n1 - file\n";
    do
    {
        std::cin >> test;
        if (test != "0" && test != "1")
        {
            std::cout << "Wrong input, try again\n";
        }
    } while (test != "0" && test != "1");
    Console_input c;
    File_input f;
    if (test == "0")
    {
        Console_front front(c);
        front.start_game(board);
    }
    else
    {
        Console_front front(f);
        front.start_game(board);
    }


    return 0;
}

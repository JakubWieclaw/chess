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
    //std::unique_ptr<Input> input;
    //File_input f;
    if (test == "0")
    {
        //input = std::make_unique<Console_input>();
        Console_input c;
        Console_front front(c);
        front.start_game(board);
    }
    else
    {
        std::string filename;
        std::cout << "Input filepath: ";
        std::cin >> filename;
        std::ifstream file(filename);
        File_input file_input(file);
        Console_front front(file_input);
        front.start_game(board);
    }

    return 0;
}

#include "Move.h"
#include <vector>
#include "engine/History.h"
#include <fstream>
#include <ctime>
#include <iostream>
#include <iterator>
#include <locale>


std::string utcExample()
{
    //std::size("yyyy-mm-ddThh:mm:ssZ")
    // Example of the very popular RFC 3339 format UTC time
    std::time_t time = std::time({});
    char timeString[50];
    std::strftime(std::data(timeString), std::size(timeString), "%Y-%m-%d-%H-%M-%S", std::gmtime(&time));
    // std::cout << timeString << '\n';

    return timeString;
}

History::History()
{
    file_name = utcExample();
}
void History::add_move(Move move)
{
    std::ofstream f(file_name, std::ios_base::app);
    f << (char)(move.from.col + 'a') << move.from.row + 1 << " " << (char)(move.to.col + 'a') << move.to.row + 1 << std::endl;
    moves.push_back(move);
}
std::vector<Move> History::get_moves()
{
    return moves;
}

int History::get_size()
{
    return moves.size();
}
Move History::get_back_element()
{
    return moves.back();
}


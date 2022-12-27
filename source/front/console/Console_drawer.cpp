#include "front/console/Console_drawer.h"
#include <Windows.h>
#include <cassert>
#include <iostream>
#include <stdlib.h>

void Console_drawer::draw_state(std::array<std::array<Field_info,8>,8> game_state, Colour turn)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    system("CLS"); // Clear screen
    
    if (turn == Colour::Black)
    {
        SetConsoleTextAttribute(console, 12);
        std::cout << "Black move\n";
    }
    else
    {
        SetConsoleTextAttribute(console, 10);
        std::cout << "White move\n";
    }
    SetConsoleTextAttribute(console, 15); // 15 - white
    std::cout << "\n abcdefgh\n";
    for (int i = 7; i >= 0; i--)
    {
        SetConsoleTextAttribute(console, 15); // 15 - white
        std::cout << i+1;
        for (int j = 7; j >=0 ; j--)
        {
            char piece;
            int colour;
            if (!game_state[i][j].occupied)
            {
                piece = '-';
                colour = 15; // 15 - white
            }
            else
            {
                colour = game_state[i][j].p.colour == Colour::Black ? 12: 10; // 12 - red, 10 - green
                switch (game_state[i][j].p.type)
                {
                    case Piece_type::Rook:
                        piece = 'R';
                        break;
                    case Piece_type::Knight:
                        piece = 'N';
                        break;
                    case Piece_type::Bishop:
                        piece = 'B';
                        break;
                    case Piece_type::Queen:
                        piece = 'Q';
                        break;
                    case Piece_type::Pawn:
                        piece = 'p';
                        break;
                    case Piece_type::King:
                        piece = 'K';
                        break;
                    default:
                        assert(false);
                }
            }
            SetConsoleTextAttribute(console, colour);
            std::cout << piece;
        }
        std::cout << std::endl;
    }
    SetConsoleTextAttribute(console, 15); // 15 - white
}
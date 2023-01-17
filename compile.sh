#!/bin/bash
rm chess.exe
g++ -Iinclude -std=c++17 source/engine/Board.cpp source/engine/History.cpp source/front/console/Console_drawer.cpp source/front/console/Console_front.cpp source/front/console/Console_input.cpp source/front/console/File_input.cpp source/Field.cpp source/main.cpp -o console_chess.exe
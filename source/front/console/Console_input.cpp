#include "front/console/Console_input.h"
#include <iostream>
#include <string>

Field insert_move()
{
    Field from;
    bool is_correct;
    std::string from_text;
    do
    {
        std::cout << "Insert field: ";
        std::cin >> from_text;
        if (!(from_text.length() == 2))
        {
            std::cout << "Wrong string length - insert move again" << std::endl;
            is_correct = false;
        }
        else if (from_text[0] < 'a' || from_text[0] > 'h')
        {
            std::cout << "Lowercase letters from a to h only - insert move again" << std::endl;
            is_correct = false;
        }
        
        else
        {
            is_correct = true;
        }
    }
    while(!is_correct);
    from.col = from_text[0] - 'a';
    from.row = from_text[1] - '1';

    return from;
}

Move Console_input::get_move()
{
    Field m_from = insert_move(); // Defined by from but accurate for both
    Field m_to = insert_move();
    Move res;
    res.from = m_from;
    res.to = m_to;
    return res;
}


#include "front/console/Console_input.h"
#include <iostream>
#include <string>

Field insert_move(std::string ft)
{
    Field from;
    bool is_correct;
    std::string from_text;
    std::string temp;
    do
    {
        
        std::cout << ft;
        std::cin >> temp;
        if (temp.length() != 2)
        {
            std::cout << "Wrong string length - insert move again" << std::endl;
            is_correct = false;
        }
        else if (temp[0] < 'a' || temp[0] > 'h')
        {
            std::cout << "Lowercase letters from a to h only - insert move again" << std::endl;
            is_correct = false;
        }
        else if (temp[1] < '1' || temp[1] > '8')
        {
            //std::cout << "Lowercase letters from a to h only - insert move again" << std::endl;
            std::cout << "Digits from 1 to 8 only - insert move again" << std::endl;
            is_correct = false;
        }
        else
        {
            is_correct = true;
        }
    } while (!is_correct);
    from_text = temp;
    from.col = 7-(from_text[0] - 'a');
    from.row = from_text[1] - '1';

    return from;
}

Move Console_input::get_move()
{
    Field m_from = insert_move(f, "From: "); // Defined by from but accurate for both
    Field m_to = insert_move(f, "To: ");
    Move res;
    res.from = m_from;
    res.to = m_to;
    return res;
}

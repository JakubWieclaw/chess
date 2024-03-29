#include "front/console/File_input.h"
#include <string>
#include <iostream>
#include <stdexcept>

File_input::File_input(std::istream &f) : f(f)
{

}

Field insert_move(std::istream &f, std::string ft)
{
    Field from;
    bool is_correct;
    std::string from_text;
    std::string temp;
    do
    {
        //std::cout << ft;
        f >> temp;
        if (temp.length() != 2)
        {
            //std::cout << "Wrong string length - insert move again" << std::endl;
            is_correct = false;
            throw std::invalid_argument( "Wrong move length" );
            
        }
        else if (temp[0] < 'a' || temp[0] > 'h')
        {
            //std::cout << "Lowercase letters from a to h only - insert move again" << std::endl;
            is_correct = false;
            throw std::invalid_argument( "Wrong letter inserted" );
            
        }
        else if (temp[1] < '1' || temp[1] > '8')
        {
            //std::cout << "Lowercase letters from a to h only - insert move again" << std::endl;
            is_correct = false;
            throw std::invalid_argument( "Wrong digit inserted" );
            
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

Move File_input::get_move()
{
    Field m_from = insert_move(f, "From: "); // Defined by from but accurate for both
    Field m_to = insert_move(f, "To: ");
    Move res;
    res.from = m_from;
    res.to = m_to;
    return res;
}

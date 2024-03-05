#include <iostream>
#include <conio.h>



std::ostream& operator << (std::ostream& os, const char* base)
{
    std::string rus_base = "";
    for (int i = 0; base[i] != '\0'; i++)
    {
        if (base[i] >= 0)
            rus_base += base[i];
        else if (base[i] < -16)
            rus_base += int(base[i]) + 192;
        else
            rus_base += int(base[i]) + 240;
    }
    return os << rus_base;
}

std::istream& operator >> (std::istream& in, std::string& out)
{
    int finder = 0;
    std::string choice = "";
    while (true)
    {
        finder = _getch();
        if (finder == char(13))
            break;

        if (finder == 8)
        {
            if (choice.size() > 0)
            {
                std::cout << char(finder) << " " << char(8);
                choice.pop_back();
            }
        }
        else
        {
            std::cout << char(finder);
            choice += finder;
        }

    }
    out = choice;
    return in;
}
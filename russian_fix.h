#include <iostream>
#include <conio.h>

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
            if (finder >= 128 && finder <= 175)
                choice += finder - 192;
            else if (finder >= 224 && finder <= 241)
                choice += finder - 240;
            else
                choice += finder;
        }

    }
    out = choice;
    return in;
}


std::ostream& operator << (std::ostream& os, const char* base)
{
    std::string rus_base = "";
    if (&os == &std::cout)
    {

        for (int i = 0; base[i] != '\0'; i++)
        {
            if (base[i] >= 0)
                os << char(base[i]);
            else if (base[i] < -16)
                os << char(int(base[i]) + 192);
            else
                os << char(int(base[i]) + 240);
        }
        return os << '\0';
    }
    else
    {
        for (int i = 0; base[i] != '\0'; i++)
        {
            if (base[i] >= 0)
                os << char(base[i]);
            else if (base[i] < -32)
                os << char(int(base[i]) + 320);
            else
                os << char(int(base[i]) + 272);
        }
        return os << '\0';
    }
}

std::ostream& operator << (std::ostream& os, std::string base)
{
    if (&os == &std::cout)
    {
        bool was_in_fn = false;
        for (int t = 0; t < base.size() && !was_in_fn; t++)
            was_in_fn = base[t] < -82;
        for (int i = 0; base[i] != '\0'; i++)
        {
            if (base[i] >= 0)
                os << base[i];
            else if (base[i] < -82 or was_in_fn)
                os << char(int(base[i]) + 256);
            else if (base[i] >= -16)
                os << char(int(base[i]) + 240);
            else
                os << char(int(base[i]) + 192);
        }
        return os << '\0';
    }
    else
    {
        for (int i = 0; base[i] != '\0'; i++)
        {
            if (base[i] >= 0)
                os << char(base[i]);
            else if (base[i])
                os << char(int(base[i]) + 256);
        }
        return os << '\0';
    }
}
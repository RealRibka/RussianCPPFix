#include <iostream>

std::string r(const char* some_str)
{
    std::string rus_string = "";
    for (int i = 0; some_str[i] != '\0'; i++)
    {
        if (some_str[i] >= 0)
            rus_string += some_str[i];
        else if (some_str[i] < -16)
            rus_string += int(some_str[i]) + 192;
        else
            rus_string += int(some_str[i]) + 240;
    }

    return rus_string;
}

std::string r(std::string some_str)
{
    std::string rus_string = "";
    for (int i = 0; some_str[i] != '\0'; i++)
    {
        if (some_str[i] >= 0)
            rus_string += some_str[i];
        else if (some_str[i] < -16)
            rus_string += int(some_str[i]) + 192;
        else
            rus_string += int(some_str[i]) + 240;
    }

    return rus_string;
}

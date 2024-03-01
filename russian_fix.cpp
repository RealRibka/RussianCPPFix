#include <iostream>
#include "russian_fix.h"


int main()
{
    std::string test;

    std::cout << "Русские символы в консоли, товарищи!\nВведите текст в консоли: ";

    std::cin >> test;
    std::cout << "\n" << test;
    return 0;
}
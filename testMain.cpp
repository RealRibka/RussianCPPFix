#include <iostream>
#include "src/russian_fix.h"


int main()
{
    std::string test;

    std::cout << "–усские символы в консоли, товарищи!\n¬ведите текст в консоли: ";

    std::cin >> test;
    std::cout << "\n" << test;
    return 0;
}
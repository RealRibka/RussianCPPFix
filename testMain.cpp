#include <iostream>
#include <fstream>
#include "russian_fix.h"

int main()
{
    //string test = "�������� ����� ��� ������ � ����";
    std::string test2 = "�������� ����� �� ����� ����";
    
    std::cout << std::endl
        << test2 << std::endl;
    

    std::ofstream stream = std::ofstream();
    stream.open("test.txt");

    stream << std::endl
        << test2 << std::endl;

    stream.close();

    
    return 0;
}
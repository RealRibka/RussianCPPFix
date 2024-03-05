#include <iostream>
#include "customString.cpp"

/// <summary>
/// RU fix for std::cout
/// </summary>
std::ostream& operator << (std::ostream& os, const char* base);


/// <summary>
/// RU fix for std::cin
/// </summary>
std::istream& operator >> (std::istream& in, std::string& out);
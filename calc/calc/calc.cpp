

#include <iostream>
#include <windows.h>


int main()
{
    int a = 0;
    int b = 0;
    std::cout << std::boolalpha;
    SetConsoleOutputCP(CP_UTF8); //setlocale не сработал

    std::cout << "Число A:" << std::endl;
    std::cin >> a;
    std::cout << "Число B:\n";
    std::cin >> b;
    
    std::cout << "sizeof(a) = " << sizeof(a) << std::endl;
    std::cout << "sizeof(b) = " << sizeof(b) << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    std::cout << "a / b = " << a / b << std::endl;

    if (a > b)
    { std::cout << "A больше B\n";}
    if (a < b)
    {std::cout << "B больше A\n";}
    if (a == b)
    {std::cout << "A равно B\n";}
    if (a >= b)
    {std::cout << "A больше или равно B\n";}
    if (a <= b)
    {std::cout << "B больше или равно A\n";}
    //Не уверен, что именно нужно здесь, скорее всего второе, но оставлю и ифы
    std::cout << " a == b = " << (a == b) << std::endl;
    std::cout << " a != b = " << (a != b) << std::endl;
    std::cout << " a > b = " << (a > b) << std::endl;
    std::cout << " a < b = " << (a < b) << std::endl;
    std::cout << " a >= b = " << (a >= b) << std::endl;
    std::cout << " a <= b = " << (a <= b) << std::endl;

    std::cout << " a | b = " << (a | b) << std::endl;
    std::cout << " a & b = " << (a & b) << std::endl;
    std::cout << " a ^ b = " << (a ^ b) << std::endl;
    std::cout << " ~a = " << ~a << std::endl;
    std::cout << " a << 2 = " << (a << 2) << std::endl;
    std::cout << " b >> 1 = " << (b >> 1) << std::endl;

    return 0;
}
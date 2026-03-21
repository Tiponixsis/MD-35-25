
#include <iostream>
#include <windows.h>
#include <clocale>

//Знаю, что код вышел не лучшим, но какой получился. Comments are on Eng because I was to lazy changing keyboard layouts all the time.

int sum = 0;
int turn = 0;

int P1Loop()
{
    int P1Num;
    static bool ispositive = false;
    static bool FirstTurn = true;

    std::cout << "Введите число, Игрок 1: \n";
    std::cin >> P1Num;
    if ((P1Num >= -5) && (P1Num <= 5)) { // if in range of [-5; 5]
        if (P1Num >= 0) { //if positive then
            if (ispositive && !FirstTurn) { std::cout << "Ошибка, два положительных подряд. Введите ещё раз.\n"; return P1Loop(); } //check if the last num was positive (not on the 1st turn)
            ispositive = true;
        }
        else { //if negative then
            if (!ispositive && !FirstTurn) { std::cout << "Ошибка, два отрицательных подряд. Введите ещё раз.\n"; return P1Loop(); } //check if the last num was negative (not on the 1st turn)
            ispositive = false;
        }
        FirstTurn = false;
        sum += P1Num;
        ++turn;
        std::cout << "Текущая сумма: " << sum << "\n";
    }
    else { std::cout << "Ошибка, число вне диапазона. Введите ещё раз.\n"; return P1Loop(); }

    return 0;
}

int P2Loop()
{
    int P2Num;
    static bool ispositive = false;
    static bool FirstTurn = true;

    std::cout << "Введите число, Игрок 2: \n";
    std::cin >> P2Num;
    if ((P2Num >= -5) && (P2Num <= 5)) { // if in range of [-5; 5]
        if (P2Num >= 0) { //if positive then
            if (ispositive && !FirstTurn) { std::cout << "Ошибка, два положительных подряд. Введите ещё раз.\n"; return P2Loop(); } //check if the last num was positive (not on the 1st turn)
            ispositive = true;
        }
        else { //if negative then
            if (!ispositive && !FirstTurn) { std::cout << "Ошибка, два отрицательных подряд. Введите ещё раз.\n"; return P2Loop(); } //check if the last num was negative (not on the 1st turn)
            ispositive = false;
        }
        FirstTurn = false;
        sum += P2Num;
        ++turn;
        std::cout << "Текущая сумма: " << sum << "\n";
    }
    else { std::cout << "Ошибка, число вне диапазона. Введите ещё раз.\n"; return P2Loop(); }

    return 0;
}

int main()
{
    //SetConsoleOutputCP(CP_UTF8); - сейчас почему-то он не работает.
    setlocale(LC_ALL, "Rus");

    while (turn < 100) {
        P1Loop();
        if (sum >= 50) {
            std::cout << "Победил Игрок 1 за " << turn << " хода(ов)!\n";
            break;
        }       
        P2Loop();
        if (sum >= 50) {
            std::cout << "Победил Игрок 2 за " << turn << " хода(ов)!\n";
            break;
        }
    }

    if (sum < 50) { std::cout << "Ничья :(\n"; }

    return 0;
}
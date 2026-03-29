// TraficLights.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

enum class TrafficLight {
    UNKNOWN = -1,
    RED,
    YELLOW,
    GREEN,
};

int printLight(TrafficLight ColorInputNum)
{
    switch (ColorInputNum)
    {
    case TrafficLight::RED:
        std::cout << "RED\n";
        break;
    case TrafficLight::YELLOW:
        std::cout << "YELLOW\n";
        break;
    case TrafficLight::GREEN:
        std::cout << "GREEN\n";
        break;
    default:
        std::cout << "err\n";
    }
    return 0;
}

int main()
{
    TrafficLight ColorInputNum{ -1 };
    printLight(ColorInputNum);

    std::string ColorInputWord;
    std::cin >> ColorInputWord;

    if (ColorInputWord == "red") {
        ColorInputNum = TrafficLight::RED;
    }
    else if (ColorInputWord == "yellow") {
        ColorInputNum = TrafficLight::YELLOW;
    }
    else if (ColorInputWord == "green") {
        ColorInputNum = TrafficLight::GREEN;
    }
   
    printLight(ColorInputNum);
    return 0;
}
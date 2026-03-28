#include <cmath>
#include <stdexcept>
#include <iostream>

template<class Func>
void calculate(double a, double b, Func func) {
    try {
        auto resault = func(a, b);
        std::cout << "Resault " << resault << "\n";
    }
    catch (const std::exception& err) {
        std::cout << err.what() << "\n";
    }
}

class InvalidLogArgument : public std::exception {
public:
    const char* what() const noexcept override {
        return "Log must be positive";
    }
};
class InvalidRadiusArgument : public std::exception {
public:
    const char* what() const noexcept override {
        return "Radius must be positive";
    }
};

auto DevideLambda = [](double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Devided by zero");
    }
    else {
        return a / b;
    }
    };

auto SqrtLambda = [](double a, double b) {
    if (a < 0) {
        throw std::domain_error("Negative number");
    }
    else {
        return std::sqrt(a);
    }
    };

auto LogLambda = [](double a, double b) {
    if (a < 0) {
        throw InvalidLogArgument();
    }
    else {
        return std::log(a);
    }
    };

auto RadiusLambda = [](double a, double b) {
    if (a <= 0) {
        throw InvalidRadiusArgument();
    }
    else {
        return 3.14 * a * a;
    }
    };

int main()
{
    std::cout << "Hello World!\n";
    calculate(1, 2, DevideLambda);
    calculate(3, 4, SqrtLambda);
    calculate(5, 6, LogLambda);
    calculate(7, 8, RadiusLambda);

    calculate(1, 0, DevideLambda);
    calculate(-1, 4, SqrtLambda);
    calculate(-1, 6, LogLambda);
    calculate(-1, 8, RadiusLambda);
}


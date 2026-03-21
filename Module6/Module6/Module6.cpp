// Module6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#include <clocale>
#include <vector>

void consume(std::unique_ptr<int> p)
{
    std::cout << "Указатель равен " << *p << "\n";
    ++*p;
    std::cout << "Теперь указатель равен " << *p << "\n";
}

void CreateVector()
{
    std::vector<int> numbers2;
    int numv = 1;
    while (numv)
    {
        std::cout << "Добавьте число в вектор (0 - закончить): "; std::cin >> numv; std::cout << "\n";
        numbers2.push_back(numv);
    }
    int summ = 0;
    for (int i = 0; i < numbers2.size(); ++i)
    {
        summ = summ + numbers2.at(i);
    }
    std::cout << "Среднее арифметическое всех чисел вектора: " << summ / numbers2.size() << "\n\n";
}

void findMax(const int* arr, int size)
{
    int current_biggest = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > current_biggest)
        {
            current_biggest = arr[i];
        }
    }
    std::cout << "\nСамое большое число: " << current_biggest << "\n\n";
}

void swap(int* a, int* b)
{
    std::cout << "a = " << *a << ", b = " << *b << "\n";
    int c = *a;
    *a = *b;
    *b = c;
    std::cout << "a = " << *a << ", b = " << *b << "\n";
}

int getRandom(int min, int max)
{
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Hello World!\n";

    unsigned int num;
    std::cout << "Введите размер массива: "; std::cin >> num;
    int* numbers = new int[num];

    for (int i = 0; i < num; i++) {
        numbers[i] = i + 1;
        std::cout << numbers[i] << "\n";
    }

    findMax(numbers, num);
    int num2 = num + getRandom(0, num/2); //захотелось поиграться
    swap(&numbers[getRandom(0, num)], &num2);
    findMax(numbers, num);
    CreateVector();

    std::unique_ptr<int> ptr{ std::make_unique<int>(num2) };
    consume(std::move(ptr));

    delete[] numbers;
    numbers = nullptr;
}
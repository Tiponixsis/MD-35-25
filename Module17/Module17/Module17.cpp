#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <random>
#include <algorithm>

int sum;
int min;
int max;
std::mutex sync;

int getRandom(int min, int max)
{
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

int main()
{
    std::cout << "Hello World!\n";

    std::vector<int> nums(100);
    for (int& x : nums) {
        x = getRandom(0, 100);
    }

    {
        std::jthread thrdsum([](const std::vector<int>& _nums) {
            int temp = 0;
            for (int x : _nums) {
                temp += x;
            }
            std::lock_guard lock(sync);
            sum = temp;
            }, std::cref(nums));

        std::jthread thrdmin([](const std::vector<int>& _nums) {
            int temp = *std::min_element(_nums.begin(), _nums.end());
            std::lock_guard lock(sync);
            min = temp;
            }, std::cref(nums));

        std::jthread thrdmax([](const std::vector<int>& _nums) {
            int temp = *std::max_element(_nums.begin(), _nums.end());
            std::lock_guard lock(sync);
            max = temp;
            }, std::cref(nums));
    }

    std::cout << "sum = " << sum << "\n";
    std::cout << "min number = " << min << "\n";
    std::cout << "max number = " << max << "\n";
}

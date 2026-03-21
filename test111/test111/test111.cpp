//Vladislav
//
// Ввод: целое число.
// Вывод: количество битов, равных 1.

// 2. без использования bitset
//
//ready
#include <iostream>
#include <bitset>

int main() {
	int num;
	std::cin >> num;
	std::bitset<8> bits(num);
	std::cout << bits.count() << "\n";

	int one_count{ 0 };
	for (int i = 0; i < 8; ++i) {
		if ((num >> i) & 1) {
			++one_count;
		}
	}
	std::cout << one_count << "\n";
}
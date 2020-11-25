#include <iostream>
#include "Stringz.h"

int main() {
	setlocale(LC_ALL, "ru");
	auto change = [](Stringz& row) {
		int length = row.getLength();
		int half = length / 2;
		Stringz firstPart;
		Stringz secondPart;

		for (int i = 0; i < half; i++) {
			firstPart += row[i];
		}

		if (length % 2 == 1) {
			for (int i = half + 1; i < length; i++) {
				secondPart += row[i];
			}
			secondPart += row[half];
			row = secondPart + firstPart;
		}
		else {
			for (int i = half; i < length; i++) {
				secondPart += row[i];
			}
			firstPart += '*';
			row = firstPart + secondPart;
		}
	};

	Stringz row;
	std::cout << "Введите строку: ";
	std::cin >> row;

	change(row);
	std::cout << row << std::endl;

	return 0;
}
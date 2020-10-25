#include <iostream>
#include "Functions.h"
#include <Windows.h>
#define EXIT 0

using namespace std;

int menuState;

void displayMenu() {
	cout << "Выберите действие: " << endl;
	cout << "(1) Загрузить данные из файла " << endl;
	cout << "(2) Ввести Данные " << endl;
	cout << "(3) Добавление данных " << endl;
	cout << "(4) Сортировка базды данных по алфавиту(по фамилии) " << endl;
	cout << "(5) Сортировка базды данных по возрасту " << endl;
	cout << "(6) Вывод: список людей, родившихся в заданном месяце " << endl;
	cout << "(7) Вывод: фамилия самого старшего мужчины " << endl;
	cout << "(8) Вывод: все фамилии, начинающиеся с заданной буквы " << endl;
	cout << "(0) Выход из программы " << endl;
	cout << "Ваш выбор: ";
}

int main() {
	setlocale(LC_ALL, "ru");

	std::vector<Data> people;

	string fileName = "asd.txt";
	do {
		system("cls");
		displayMenu();
		cin >> menuState;

		switch (menuState) {
		case 0:
			exit(EXIT);
		case 1:
			dataLoad(people, fileName);
			break;
		case 2:
			dataInput(people, fileName);
			cout << "=======================" << endl;
			break;
		case 3:
			dataAppend(people, fileName);
			break;
		case 4:
			dataSortByLastName(people);
			break;
		case 5:
			dataSortByAge(people);
			break;
		case 6:
			int givenMonth;
			cout << "Введите месяц: ";
			cin >> givenMonth;
			outputPeopleWhoWasBornInGivenMonth(people, givenMonth);
			break;
		case 7:
			outputTheMostOlderMan(people);
			break;
		case 8:
			char givenLetter;
			cout << "Введите символ: ";
			cin >> givenLetter;
			outputAllLastsNamesWhichStartWithGivenLetter(people, givenLetter);
			break;
		default:
			cout << "Введите корректное число" << endl;
		}
	} while (menuState != EXIT);
	
}
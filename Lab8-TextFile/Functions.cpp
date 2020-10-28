#include "Functions.h"

void dataLoad(std::vector<Data>& people, const std::string fileName) {
	people.clear();
	std::ifstream fin(fileName);

	if (fin) {
		Initials initials;
		BirthDate date;
		std::string sex;

		std::string trash;
		while (!fin.eof()) {
			fin >> trash;
			fin >> initials.lastName >> initials.firstName >> initials.middleName;

			fin >> trash;
			fin >> date.day >> date.month >> date.year;

			fin >> trash;
			fin >> sex;
			people.push_back(Data(initials, date, sex));
		}

		std::cout << "Данные считаны " << std::endl;
	}
	else {
		std::cout << "Не удалось открыть файл " << fileName << std::endl;
	}

	fin.close();
}

void dataInput(std::vector<Data>& people) {
	if (people.size() != 0) {
		std::cout << "=======================" << std::endl;
		for (const auto& person : people) {
			std::cout << person;
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "Сначала нужно загрузить данные" << std::endl;
	}
}

void dataAppend(std::vector<Data>& people, const std::string fileName) {
	std::ofstream fout(fileName, std::ios_base::app);

	Initials initials;
	BirthDate date;
	std::string sex;

	std::string a = "-1";
	while (a != "0") {
		std::cout << "ФИО: ";
		std::cin >> initials.lastName >> initials.firstName >> initials.middleName;
		std::cout << "Дата рождения: ";
		std::cin >> date.day >> date.month >> date.year;
		std::cout << "Пол: ";
		std::cin >> sex;
		people.push_back(Data(initials, date, sex));

		std::cout << "================" << std::endl;
		std::cout << "Введите 0, если хотите закончить ввод (иначе любой символ)";
		std::cin >> a;
	}


	for (const auto& person : people) {
		fout << person;
	}

	fout.close();
}

void dataSortByLastName(std::vector<Data>& people) {
	if (people.size() > 0) {
		for (int i = 0; i < people.size() - 1; ++i) {
			for (int j = i + 1; j < people.size(); ++j) {
				std::string lastNameOfFirstPerson = people[i].getInitials().lastName;
				std::string lastNameOfSecondPerson = people[j].getInitials().lastName;
				if (lastNameOfSecondPerson < lastNameOfFirstPerson) {
					Data temp = people[i];
					people[i] = people[j];
					people[j] = temp;
				}
			}
		}
		std::cout << "База данных отсортирована" << std::endl;
	}
	else {
		std::cout << "База данных пуста" << std::endl;
	}
}

void dataSortByAge(std::vector<Data>& people) {
	auto swap = [&people](const int i, const int j) {
		Data temp = people[i];
		people[i] = people[j];
		people[j] = temp;
	};

	if (people.size() > 0) {
		for (int i = 0; i < people.size() - 1; ++i) {
			for (int j = i + 1; j < people.size(); ++j) {
				BirthDate dateOfFirstPerson = people[i].getBirthDate();
				BirthDate dateOfSecondPerson = people[j].getBirthDate();
				if (dateOfFirstPerson.year != dateOfSecondPerson.year) {
					if (dateOfFirstPerson.year > dateOfSecondPerson.year) {
						swap(i, j);
					}
				} else if (dateOfFirstPerson.month != dateOfSecondPerson.month) {
					if (dateOfFirstPerson.month > dateOfSecondPerson.month) {
						swap(i, j);
					}
				} else if (dateOfFirstPerson.day > dateOfSecondPerson.day) {
					swap(i, j);
				}
			}
		}
		std::cout << "База данных отсортирована" << std::endl;
	}
	else {
		std::cout << "База данных пуста" << std::endl;
	}
}

void outputPeopleWhoWasBornInGivenMonth(std::vector<Data>& people, const int givenMonth) {
	bool suchPersonHas = false;
	for (int i = 0; i < people.size(); ++i) {
		if (people[i].getBirthDate().month == givenMonth) {
			suchPersonHas = true;
			std::cout << people[i] << std::endl;
		}
	}

	if (!suchPersonHas) {
		std::cout << "Человека с заданным месяцем в базе данных нет" << std::endl;
	}
}

void outputTheMostOlderMan(std::vector<Data>& people) {
	auto getFirstManPerson = [&people]() mutable -> Data {
		for (int i = 0; i < people.size(); ++i) {
			if (people[i].getSex() == "man") {
				return people[i];
			}
		}
		Data people;
		return people;
	};
	Data man = getFirstManPerson();

	auto manExistsAtDataBase = [&man]() mutable -> bool {
		return man.getSex() == "man";
	};

	if (manExistsAtDataBase()) {
		for (int i = 1; i < people.size(); ++i) {
			BirthDate dateOfSecondPerson = people[i].getBirthDate();
			if (man.getBirthDate().year > dateOfSecondPerson.year && people[i].getSex() == "man") {
				man = people[i];
			} else if (man.getBirthDate().month > dateOfSecondPerson.month && people[i].getSex() == "man") {
				man = people[i];
			} else if (man.getBirthDate().day > dateOfSecondPerson.day && people[i].getSex() == "man") {
				man = people[i];
			}
		}
		std::cout << man << std::endl;

	}
	else {
		std::cout << "Мужчин в базе данных нет" << std::endl;
	}
}

void outputAllLastsNamesWhichStartWithGivenLetter(std::vector<Data>& people, char firstLetterOfLastsNames) {
	bool suchPersonsExists = false;
	for (int i = 0; i < people.size(); ++i) {
		if (people[i].getInitials().lastName[0] == firstLetterOfLastsNames) {
			suchPersonsExists = true;
			std::cout << people[i] << std::endl;
		}
	}

	if (!suchPersonsExists) {
		std::cout << "Людей с заднной первой буквой в фамилии нет" << std::endl;
	}
}
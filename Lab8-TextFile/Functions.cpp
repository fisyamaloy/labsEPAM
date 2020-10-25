#include "Functions.h"

void dataLoad(std::vector<Data>& people, const std::string fileName) {
	std::ifstream fin(fileName);

	if (fin) {
		Initials initials;
		BirthDate date;
		std::string sex;

		while (!fin.eof()) {
			fin >> initials.firstName >> initials.lastName >> initials.middleName;
			fin >> date.day >> date.month >> date.year;
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

void addDataToVectorAndFile(std::vector<Data>& people, std::ofstream& fout) {
	Initials initials;
	BirthDate date;
	std::string sex;

	std::string a = "-1";
	while (a != "0") {
		std::cout << "ФИО: ";
		std::cin >> initials.firstName >> initials.lastName >> initials.middleName;
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
}

void dataInput(std::vector<Data>& people, const std::string fileName) {
	people.clear();
	std::ofstream fout(fileName);
	addDataToVectorAndFile(people, fout);
	fout.close();
}

void dataAppend(std::vector<Data>& people, const std::string fileName) {
	std::ofstream fout(fileName, std::ios_base::app);
	addDataToVectorAndFile(people, fout);
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
				if (dateOfFirstPerson.year != dateOfFirstPerson.year) {
					if (dateOfFirstPerson.year > dateOfSecondPerson.year) {
						swap(i, j);
					}
				}
				else if (dateOfFirstPerson.month != dateOfFirstPerson.month) {
					if (dateOfFirstPerson.month > dateOfSecondPerson.month) {
						swap(i, j);
					}
				}
				else {
					if (dateOfFirstPerson.month > dateOfSecondPerson.month) {
						swap(i, j);
					}
				}
			}
		}
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
			std::cout << people[i];
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
			if (man.getBirthDate().year < dateOfSecondPerson.year && people[i].getSex() != "man") {
				man = people[i];
			} else if (man.getBirthDate().month < dateOfSecondPerson.month && people[i].getSex() != "man") {
				man = people[i];
			} else if (man.getBirthDate().day < dateOfSecondPerson.day && people[i].getSex() != "man") {
				man = people[i];
			}
		}
		std::cout << man;

	} else {
		std::cout << "Мужчин в базе данных нет" << std::endl;
	}
}

void outputAllLastsNamesWhichStartWithGivenLetter(std::vector<Data>& people, char firstLetterOfLastsNames) {
	bool suchPersonsExists = false;
	for (int i = 0; i < people.size(); ++i) {
		if (people[i].getInitials().lastName[0] == firstLetterOfLastsNames) {
			suchPersonsExists = true;
			std::cout << people[i];
		}
	}

	if (!suchPersonsExists) {
		std::cout << "Людей с заднной первой буквой в фамилии нет" << std::endl;
	}
}
#pragma once

#include <iostream>
#include <fstream>
#include <string>

struct Initials {
	std::string firstName;
	std::string lastName;
	std::string middleName;
 };

struct BirthDate {
	int day;
	int month;
	int year;
};

class Data {
private:
	Initials initials;
	BirthDate date;
	std::string sex;

public:
	Data();
	Data(Initials initials, BirthDate date, std::string sex);

	Initials getInitials() {
		return initials;
	}

	BirthDate getBirthDate() {
		return date;
	}
	
	std::string getSex() {
		return sex;
	}

	friend std::ostream& operator<<(std::ostream& os, const Data d);
	Data& operator=(Data d);
};



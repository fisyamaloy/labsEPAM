#include "Data.h"

Data::Data() {
	initials.firstName = "";
	initials.lastName = "";
	initials.middleName = "";

	date.day = -1;
	date.month = -1;
	date.year = -1;

	sex = "";
}

Data::Data(Initials initials, BirthDate date, std::string sex) {
	this->initials.firstName = initials.firstName;
	this->initials.lastName = initials.lastName;
	this->initials.middleName = initials.middleName;

	this->date.day = date.day;
	this->date.month = date.month;
	this->date.year = date.year;

	this->sex = sex;
}

std::ostream& operator<<(std::ostream& os, const Data d) {
	os << std::endl;
	os << "ФИО: " << d.initials.lastName << " " << d.initials.firstName << " " << d.initials.middleName << std::endl;
	os << "Дата: " << d.date.day << " " << d.date.month << " " << d.date.year << std::endl;
	os << "Пол: " << d.sex;
	return os;
}

Data& Data::operator=(Data d) {
	this->initials.firstName = d.initials.firstName;
	this->initials.lastName = d.initials.lastName;
	this->initials.middleName = d.initials.middleName;

	this->date.day = d.date.day;
	this->date.month = d.date.month;
	this->date.year = d.date.year;

	this->sex = d.sex;
	return *this;
}
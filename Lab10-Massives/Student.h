#pragma once
#include <string>

using std::string;

struct Student {
	string name;
	string lastName;
	string faculty;
	string group;
	string email;

	Student() {

	}

	Student(string name, string lastName, string faculty, string group, string email) {
		this->name = name;
		this->lastName = lastName;
		this->faculty = faculty;
		this->group = group;
		this->email = email;
	}
};
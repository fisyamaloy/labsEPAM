#include <iostream>
#include "Student.h"

using std::cout;
using std::endl;

Student*& getStudents(int n) {
	Student* students = new Student[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> students->name >> students->lastName >> students->faculty >> students->group >>
			students->email;
	}
	return students;
}

int main() {
	Student staticStudents[30];

	int n;
	std::cin >> n;
	Student* students = getStudents(n);

	Student firstStudent = *students;

	cout << "size of static massive = " << sizeof(staticStudents) / sizeof(staticStudents[0]) << endl;
	cout << "size of dynamic massive = " << n << endl;

	cout << "Students adresses structures: " << endl;
	for (int i = n - 1; i >= 0; --i) {
		cout << students + i << " ";
	}
	cout << endl << "Value of ukaz change on " << sizeof(students) << endl;

	cout << "Adresses of neighbour struct's fields" << endl;
}
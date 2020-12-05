#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include "Student.h"
#include <memory>

using namespace std;

int main() {
	auto showStudentsList = [](const list<Student>& students) {
		cout << "Show students: " << endl;
		for_each(students.cbegin(), students.cend(), [](const Student& student) {
			cout << student << endl;
		});
		cout << "===============================" << endl;
	};

	Student st1("Fisyuk Danil Sergeevich", "PM-21", 18, 2);
	Student st2("Plotko Anton Aleksandrovich", "MI-21", 17, 2);
	Student st3("Zavadich Maxim Sergeevich", "PM-21", 20, 2);
	Student st4("Glina Yaroslav Nikolaevich", "PM-21", 19, 2);
	Student st5("Nogach Maxim Genadievich", "PM-21", 18, 2);

	list<Student> students = { st1, st2,st3,st4,st5 };
	showStudentsList(students);

	students.sort(Student::CompareByFio());
	showStudentsList(students);

	auto showStudentsPointersVector = [](const vector<shared_ptr<Student>>& students) {
		cout << "Show students: " << endl;
		for_each(students.cbegin(), students.cend(), [](const shared_ptr<Student>& student) {
			cout << *student << endl;
			});
		cout << "===============================" << endl;
	};

	shared_ptr<Student> ptrSt1(new Student(st1));
	shared_ptr<Student> ptrSt2(new Student(st2));
	shared_ptr<Student> ptrSt3(new Student(st3));
	shared_ptr<Student> ptrSt4(new Student(st4));
	shared_ptr<Student> ptrSt5(new Student(st5));

	vector<shared_ptr<Student>> studentsPointers{ ptrSt1, ptrSt2, ptrSt3, ptrSt4, ptrSt5 };
	sort(studentsPointers.begin(), studentsPointers.end(), Student::CompareByAge());
	showStudentsPointersVector(studentsPointers);

	studentsPointers.clear();
}
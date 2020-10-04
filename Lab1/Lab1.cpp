

#include <iostream>
#define marksAmount 3

using namespace std;

struct Student {
	string lastName;
	string firstName;
	int marks[marksAmount];

	void displayInfo() {
		cout << lastName << ' ' << firstName << ' ';
		for (int i = 0; i < marksAmount; i++) {
			cout << marks[i] << ' ';
		}

		cout << endl;
	}
	bool operator < (const Student& other) 
	{
		return getMaxMark(marks) < getMaxMark(other.marks);
	}

private:
	int getMaxMark(const int* marks) {
		int maxMark = 0;
		for (int i = 0; i < marksAmount; i++) {
			if (maxMark < marks[i]) {
				maxMark = marks[i];
			}
		}
		return maxMark;
	}
};

void sort(Student*& student, const int size);

int main() {
	int size;
	cin >> size;
	Student* students = new Student[size];

	for (int i = 0; i < size; i++) {
		cout << "input first name: ";
		cin >> students[i].firstName;
		cout << "input last name: ";
		cin >> students[i].lastName;
		cout << "input marks: ";
		for (int& mark : students[i].marks) {
			cin >> mark;
		}

		students[i].displayInfo();
	}

	cout << "====================" << endl;

	for (int i = 0; i < size; i++) {
		students[i].displayInfo();
	}

	sort(students, size);

	for (int i = 0; i < size; i++) {
		students[i].displayInfo();
	}

	delete[] students;
}

void sort(Student*& students, const int size) {
	cout << "sort: " << endl;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (students[i] < students[j]) {
				Student tempStudent = students[i];
				students[i] = students[j];
				students[j] = tempStudent;
			}
		}
	}
}
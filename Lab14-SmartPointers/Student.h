#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<memory>

struct Student {	
	std::string fio;
	std::string group;
	int age;
	int course;

	Student(std::string _fio = "", std::string _group = "", int _age = -1, int _course = -1) 
		: fio(_fio), group(_group), age(_age), course(_course) {
		std::cout << "STUDENT consturctor" << std::endl;
	}

	~Student() {
		std::cout << "STUDENT DESTRUCTOR" << std::endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Student& student) {
		out << student.fio << ' ' << student.course << ' ' << student.group << ' ' << student.age;
		return out;
	}

	struct CompareByFio {
		bool operator()(const Student& first, const Student& second) const {
			return first.fio < second.fio;
		}

		bool operator()(const std::shared_ptr<Student>& first, const std::shared_ptr<Student>& second) const {
			return first->fio < second->fio;
		}
	};

	struct CompareByAge {
		bool operator()(const Student& first, const Student& second) const {
			return first.age < second.age;
		}
		
		bool operator()(const std::shared_ptr<Student>& first, const std::shared_ptr<Student>& second) const {
			return first->age < second->age;
		}
	};

	struct CompareByCourse {
		bool operator()(const Student& first, const Student& second) const {
			return first.course < second.course;
		}

		bool operator()(const std::shared_ptr<Student>& first, const std::shared_ptr<Student>& second) const {
			return first->course < second->course;
		}
	};

	struct CompareByGroup {
		bool operator()(const Student& first, const Student& second) const {
			return first.group < second.group;
		}

		bool operator()(const std::shared_ptr<Student>& first, const std::shared_ptr<Student>& second) const {
			return first->group < second->group;
		}
	};
};
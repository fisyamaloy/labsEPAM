#include "Stringz.h"

Stringz::Stringz(const char* row) noexcept {
	std::cout << "Constructor with char type parameter" << std::endl;
	int length = strlen(row);
	this->row = new char[length + 1]; // +1 для терменирующего ноля.

	for (int i = 0; i < length; i++) {
		this->row[i] = row[i];
	}

	this->row[length] = '\0';
}
Stringz::Stringz(const Stringz& other) noexcept {
	std::cout << "Constructor with constant reference on Stringz type parameter" << std::endl;
	int length = other.row != nullptr ? strlen(other.row) : 0;
	this->row = new char[length + 1]; // +1 для терменирующего ноля.

	for (int i = 0; i < length; i++) {
		this->row[i] = other.row[i];
	}
	this->row[length] = '\0';
}
Stringz::Stringz(Stringz&& other) noexcept {
	std::cout << "Constructor with Rvalue Stringz type parameter" << std::endl;
	int length = other.row != nullptr ? strlen(other.row) : 0;
	this->row = other.row;
	other.row = nullptr;
}

Stringz& Stringz::operator=(const Stringz& other) noexcept {
	if (this->row != nullptr) {
		delete[] row;
	}

	int length = strlen(other.row);
	this->row = new char[length + 1]; // +1 для терменирующего ноля.

	for (int i = 0; i < length; i++) {
		this->row[i] = other.row[i];
	}
	this->row[length] = '\0';

	return *this;
}
Stringz Stringz::operator+(const Stringz& other) noexcept {
	Stringz newStr;

	int thisLength = strlen(this->row);
	int otherLength = 0;
	if (other.row != nullptr) {
		otherLength = strlen(other.row);
	}
	int length = thisLength + otherLength;

	newStr.row = new char[length + 1]; // +1 для тeрменирующего ноля.

	int i = 0;
	for (; i < thisLength; i++) {
		newStr.row[i] = this->row[i];
	}

	for (int j = 0; j < otherLength; j++) {
		newStr.row[i + j] = other.row[j];
	}
	newStr.row[length] = '\0';

	return newStr;
}
void Stringz::operator+=(const Stringz& other) noexcept {
	Stringz newStr = *this;
	int thisLength = newStr.getLength();
	int otherlength = other.row != nullptr ? strlen(other.row) : 0;

	this->row = new char[thisLength + otherlength + 1];
	int i = 0;
	for (; i < thisLength; i++) {
		this->row[i] = newStr.row[i];
	}

	for (int j = 0; j < otherlength; j++) {
		this->row[i + j] = other.row[j];
	}

	this->row[thisLength + otherlength] = '\0';
}
void Stringz::operator+=(const char& symbol) noexcept {
	Stringz newStr = *this;
	int thisLength = newStr.getLength();
	int newLength = thisLength + 1;
	this->row = new char[newLength + 1];
	for (int i = 0; i < thisLength; i++) {
		this->row[i] = newStr.row[i];
	}

	this->row[newLength - 1] = symbol;
	this->row[newLength] = '\0';
}
std::istream& operator>>(std::istream& is, Stringz& str) noexcept {
	if (str.row == nullptr)
		str.row = new char[256];

	char* A = new char[256];
	is.getline(A, 256, '\n');
	str = A;

	return is;
}
std::ostream& operator<<(std::ostream& os, Stringz& str) noexcept {
	os << str.row;
	return os;
}
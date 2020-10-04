#include <iostream>
#include <cassert>

using namespace std;

class Stringz {
public:
	Stringz() {
		row = nullptr;
	}

	Stringz(const char* row) {
		int length = strlen(row);
		this->row = new char[length + 1]; // +1 для терменирующего ноля.

		for (int i = 0; i < length; i++) {
			this->row[i] = row[i];
		}

		this->row[length] = '\0';
	}

	~Stringz() {
		delete[] this->row;
	}

	Stringz& operator = (const Stringz& other) {
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

	// Конструктор копирования 
	Stringz(const Stringz& other) {

		int length;
		if (other.row != nullptr)
			length = strlen(other.row);
		else
			length = 0;

		this->row = new char[length + 1];

		for (int i = 0; i < length; i++) {
			this->row[i] = other.row[i];
		}

		this->row[length] = '\0';
	}

	Stringz operator + (const Stringz& other) {
		Stringz newStr;

		int thisLength = strlen(this->row);
		int otherLength = 0;
		if (other.row != nullptr) {
			otherLength = strlen(other.row);
		}
		int length = thisLength + otherLength;

		newStr.row = new char[length + 1]; // +1 для тэрменирующего ноля.

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

	void operator += (const Stringz& other) {
		Stringz newStr = *this;
		int thisLength = newStr.getLength();
		int otherlength;

		if (other.row != nullptr)
			otherlength = strlen(other.row);
		else
			otherlength = 0;

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

	void operator += (const char& symbol) {
		Stringz newStr = *this;
		int thisLength = newStr.getLength();
		int newLength = thisLength + 1;
		this->row = new char[newLength + 1];
		int i = 0;
		for (; i < thisLength; i++) {
			this->row[i] = newStr.row[i];
		}

		this->row[newLength - 1] = symbol;
		this->row[newLength] = '\0';
	}

	char& operator [] (int i) {
		assert(i >= 0 && i < getLength());
		return row[i];
	}

	int getLength() {
		if (this->row != nullptr)
			return strlen(this->row);

		return 0;
	}

	friend istream& operator>>(istream& is, Stringz& str);
	friend ostream& operator<<(ostream& os, Stringz& str);

private:
	char* row;
};

istream& operator>> (istream& is, Stringz& str) {
	if (str.row == nullptr)
		str.row = new char[256];

	char* A = new char[256];
	is.getline(A, 256, '\n');
	str = A;

	return is;
}

ostream& operator<< (ostream& os, Stringz& str) {
	os << str.row;
	return os;
}

void changeStringz(Stringz& str);

int main() {
	setlocale(LC_ALL, "ru");

	Stringz a;
	cout << "Введите строку: ";
	cin >> a;

	changeStringz(a);
	cout << a << endl;

	return 0;
}

void changeStringz(Stringz& str) {
	int length = str.getLength();
	int half = length / 2;
	Stringz firstPart;
	Stringz secondPart;

	for (int i = 0; i < half; i++) {
		firstPart += str[i];
	}

	if (length % 2 == 1) {
		for (int i = half + 1; i < length; i++) {
			secondPart += str[i];
		}
		secondPart += str[half];
		str = secondPart + firstPart;
	}
	else {
		for (int i = half; i < length; i++) {
			secondPart += str[i];
		}
		firstPart += '*';
		str = firstPart + secondPart;
	}
}

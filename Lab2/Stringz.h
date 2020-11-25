#pragma once
#include <iostream>
#include <cassert>

class Stringz {
public:
	Stringz() noexcept {
		std::cout << "default constructor" << std::endl;
		row = nullptr;
	}
	Stringz(const char* row) noexcept;
	Stringz(const Stringz& other) noexcept;
	Stringz(Stringz&& other) noexcept;
	~Stringz() noexcept {
		std::cout << "Destructor" << std::endl;
		delete[] this->row;
	}

	constexpr int getLength() const noexcept {
		if (this->row != nullptr)
			return strlen(this->row);

		return 0;
	}

	Stringz& operator=(const Stringz& other) noexcept;
	Stringz operator+(const Stringz& other) noexcept;
	void operator+=(const Stringz& other) noexcept;
	void operator+=(const char& symbol) noexcept;
	char& operator [] (int i) noexcept {
		assert(i >= 0 && i < getLength());
		return row[i];
	}

	friend std::istream& operator>>(std::istream& is, Stringz& str) noexcept;
	friend std::ostream& operator<<(std::ostream& os, Stringz& str) noexcept;
private:
	char* row;
};
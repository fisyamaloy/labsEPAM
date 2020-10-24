#pragma once
#include <string>
#include <list>
#include <cassert>

class Money {
public:
	Money(const std::string val = "");

	friend std::istream& operator>>(std::istream& is, Money& money);
	friend std::ostream& operator<<(std::ostream& os, const Money& money);
private:
	bool isDigit(char digit) {
		return (int)digit >= 48 && (int)digit <= 57;
	}

	std::list<char> value;
};

Money::Money(const std::string val) {
	for (int i = 0; i < val.length(); ++i) {
		assert(isDigit(val[i]) || val[i] == (int)'.');
		value.push_back(val[i]);
		if (val[i] == (int)'.') {
			value.push_back(val[i + 1]);
			value.push_back(val[i + 2]);
			break;
		}
	}
}

void changeIteratorAndPushAfter(const int length, std::list<char>::const_iterator& it, std::list<char>& val) {
	for (int i = 0; i < length; ++i) {
		if (it != val.cbegin()) {
			--it;
		}
	}

	if (it != val.cbegin()) {
		val.insert(it, ' ');
	}
}

bool listContainsPen(const std::list<char> val) {
	for (const char elem : val) {
		if (elem == '.') {
			return true;
		}
	}

	return false;
}

std::ostream& operator<<(std::ostream& os, const Money& money) {
	std::list<char> val = money.value;

	if (listContainsPen(val)) {
		auto it = val.cbegin();
		for (it; it != val.cend(); ++it) {
			if (*it == (int)'.') {
				changeIteratorAndPushAfter(3, it, val);
				break;
			}
		}
		while (it != val.cbegin()) {
			changeIteratorAndPushAfter(4, it, val);
		}
	}
	else {
		auto it = val.cend();
		changeIteratorAndPushAfter(3, it, val);
		while (it != val.cbegin()) {
			changeIteratorAndPushAfter(4, it, val);
		}
	}

	std::cout << "$";
	auto display = [&val, &os]() mutable {
		int inQuantity = 0;
		for (char digit : val) {
			os << digit;
		}
	};

	display();
	return os;
}

std::istream& operator>>(std::istream& is, Money& money){
	std::string val;
	std::getline(is, val);
	for (int i = 0; i < val.length(); ++i) {
		if (money.isDigit(val[i]) || val[i] == (int)'.');
			money.value.push_back(val[i]);
		if (val[i] == (int)'.') {
			money.value.push_back(val[i + 1]);
			money.value.push_back(val[i + 2]);
			break;
		}
	}
	return is;
}

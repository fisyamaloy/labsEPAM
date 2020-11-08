#pragma once
#include <exception>

class VectorException : public std::exception {
public:
	VectorException(int dataState = 0) {
		this->dataState = dataState;
	}

	const int getDataState() const {
		return dataState;
	}

	enum ErrorsCodes {
		OUT_OF_RANGE = -1,
		VECTOR_IS_EMPTY = 0,
	};

	const char* what() const override {
		switch (dataState) {
		case OUT_OF_RANGE:
			return "Out of range, man.\n";
		case VECTOR_IS_EMPTY:
			return "Vector is empty\n";
		default:
			return "I dont know what happends\n";
		}

	}

private:
	int dataState;
};
#pragma once
#include <exception>

class VectException : public std::exception {
public:
	VectException(const char* msg, int dataState) : exception(msg) {
		this->dataState = dataState;
	}

	int getDataState() {
		return dataState;
	}

	enum ErrorsCodes {
		OUT_OF_RANGE = -1,

	};

private:
	int dataState;
};
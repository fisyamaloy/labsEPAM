#pragma once
#include <exception>

class ContainersExceptions : public std::exception {
public:
	ContainersExceptions(int dataState) {
		this->dataState = dataState;
	}

	constexpr int getDataState() const {
		return dataState;
	}

	virtual const char* what() const = 0;

protected:
	int dataState;

	enum ErrorsCodes {
		OUT_OF_RANGE = -1,
		CONTAINER_IS_EMPTY = 0,
	};
};
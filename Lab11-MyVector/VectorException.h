#pragma once
#include "ContainersExceptions.h"

class VectorException : public ContainersExceptions {
public:
	VectorException(int dataState = 0) : ContainersExceptions(dataState) {
		
	}

	const char* what() const override {
		switch (dataState) {
		case OUT_OF_RANGE:
			return "Out of range, man.\n";
		case CONTAINER_IS_EMPTY:
			return "Vector is empty\n";
		default:
			return "I dont know what happend\n";
		}
	}
};
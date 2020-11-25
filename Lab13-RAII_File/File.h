#pragma once
#include <memory>
#include<iostream>

class File {
private:
	std::shared_ptr<FILE> f;
public:
	File(const char* fileName, const char* mode) {
		std::shared_ptr<FILE>temp(std::fopen(fileName, mode));
		f = temp;
		if (!f) {
			throw std::runtime_error("file open failure");
		}
	}

	void readFile() {
		
	}

	~File() {
		if (std::fclose(f.get()) != 0) {
			throw std::runtime_error("close file failure");
		}
	}
};
#pragma once
#include <iostream>
#include <memory>
#include <fstream>
#include <string>

class File {
private:
	std::unique_ptr<std::fstream> io;
public:
	File(const std::string path) {
		if (!(*(io = std::make_unique<std::fstream>(path, std::ios::in | std::ios::out | std::ios::app)))) {
			throw "File open failure";
		}
	}

	File(const File& f) = delete;

	std::string readLine() {
		std::string row;
		if (!(*io).eof()) {
			std::getline(*io, row);
		}

		return row; 
	}

	void write(const std::string row) {
		(*io) << row;
	}

	inline bool end() noexcept {
		return (*io).eof();
	}

	~File() noexcept {
		if (!(*io)) {
			(*io).close();
		}
	}
};
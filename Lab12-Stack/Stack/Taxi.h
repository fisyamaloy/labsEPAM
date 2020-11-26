#pragma once
#include<iostream>
#include<string>

class Taxi {
private:
	unsigned int taxiNumber;
	std::string FIO;
	std::string model;
	bool isBusy;
public:
	Taxi(std::string FIO, std::string model, bool isBusy = false) {
		static unsigned int number = 0;
		taxiNumber = number++;
		this->FIO = FIO;
		this->model = model;
		this->isBusy = isBusy;
	}

	constexpr unsigned int getNumber() const {
		return taxiNumber;
	}
	constexpr bool getBusy() const {
		return isBusy;
	}
	std::string getFIO() const {
		return FIO;
	}
	std::string getModel() const {
		return model;
	}
	void enableBusy() {
		isBusy = true;
		std::cout << "Taxi with number " << taxiNumber << " was called" << std::endl;
	}
	void disableBusy() {
		isBusy = false;
		std::cout << "Taxi with number " << taxiNumber << " was realesed" << std::endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Taxi& taxi) {
		out << "number: " << taxi.taxiNumber << ", model: " << taxi.model << (taxi.isBusy ? " is busy" : " is not busy!");
		return out;
	}
};
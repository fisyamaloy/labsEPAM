#include <iostream>
#include <ctime>

using namespace std;

class Перевозчик {
protected:
	virtual void showInfo() = 0;
};

class Пассажирский : Перевозчик {
public:
	Пассажирский(int* massive, const int length) {
		this->massive = massive;
		this->length = length;
	}

	~Пассажирский() {
		delete[] massive;
	}

protected:
	int length;
	int* massive;
	virtual double getAveragePassangersAmount() = 0;
};

class Грузовой : Перевозчик{
public:
	Грузовой(int* massive, const int length) {
		this->massive = massive;
		this->length = length;
	}

	~Грузовой() {
		delete[] massive;
	}

protected:
	int length;
	int* massive;
	virtual double getTotalFreightCost() = 0;
};

class Автобус : Пассажирский {
public:
	Автобус(int* massive, const int length) : Пассажирский(massive, length) {

	}

	double getAveragePassangersAmount() override {
		int sum = 0;
		for (int i = 0; i < length; i++) {
			sum += massive[i];
		}

		return (double)sum / length;
	}

	void showInfo() override {
		cout << "Автобус пассажирского типа со средним числом пассажиров равным " << getAveragePassangersAmount() << endl;
	}
};

class Самолет : Пассажирский {
public:
	Самолет(int* massive, const int length) : Пассажирский(massive, length) {
		
	}
 
	double getAveragePassangersAmount() override {
		int sum = 0;
		for (int i = 0; i < length; i++) {
			sum += massive[i];
		}

		return (double)sum / length;
	}

	void showInfo() override {
		cout << "Самолет пассажирского типа со средним числом пассажиров равным " << getAveragePassangersAmount() << endl;
	}
};

class Поезд : Грузовой {
public:
	Поезд(int* massive, const int length) : Грузовой(massive, length) {

	}

	double getTotalFreightCost() override {
		int sum = 0;
		for (int i = 0; i < length; i++) {
			sum += massive[i];
		}

		return sum * 0.5;
	}

	void showInfo() override {
		cout << "Поезд грузового типа с общей стоимостью грузопреревозки равной " << getTotalFreightCost() << "$" << endl;
	}
};

class Автомобиль : Грузовой {
public:
	Автомобиль(int* massive, const int length) : Грузовой(massive, length) {

	};

	double getTotalFreightCost() override {
		int sum = 0;
		for (int i = 0; i < length; i++) {
			sum += massive[i];
		}

		return sum * 0.7;
	}

	void showInfo() override {
		cout << "Автомобиль грузового типа с общей стоимостью грузопреревозки равной " << getTotalFreightCost() << "$" << endl;
	}
};

int*& getRandomMassiveAndSetHisSize(int& size);

int main() {
	setlocale(LC_ALL, "ru");

	int size;
	int* massive = getRandomMassiveAndSetHisSize(size);
	Поезд поезд(massive, size);
	поезд.showInfo();

	int* massive2 = getRandomMassiveAndSetHisSize(size);
	Самолет самолет(massive2, size);
	самолет.showInfo();
}

int*& getRandomMassiveAndSetHisSize(int& n) {
	srand(time(0));
	n = rand() % 10 + 1;
	int* massive = new int[n];
	for (int i = 0; i < n; i++) {
		massive[i] = rand() % 15;
	}

	return massive;
}

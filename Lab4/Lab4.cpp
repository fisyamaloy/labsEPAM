#include <iostream>
#include <ctime>

using namespace std;

class Грузоперевозчик {

public:
	Грузоперевозчик(string const name, int const speed, int*& груз) {
		this->name = name;
		this->speed = speed;
		length = sizeof(грузы) / sizeof(грузы[0]);
		грузы = new int[length];
		for (int i = 0; i < length; i++) {
			this->грузы[i] = груз[i];
		}
	}

	~Грузоперевозчик() {
		delete[] грузы;
	}

	virtual void showInfo() = 0;

	int getКилограммыГрузаВОбщем() {
		int килограммыГрузаВОбщем = 0;
		for (int i = 0; i < length; i++) {
			килограммыГрузаВОбщем += грузы[i];
		}
		
		return килограммыГрузаВОбщем;
	}

	virtual void показатьОбщуюСтоимостьГрузоперевозки() = 0;

protected:
	string name;
	int speed;
	int* грузы;
private:
	int length;
};

class Поезд : public Грузоперевозчик {

public:
	Поезд(string const name, int const speed, int*& груз, int const количествоВагонов) : Грузоперевозчик(name, speed, груз)  {
		this->количествоВагонов = количествоВагонов;
	}

	void показатьОбщуюСтоимостьГрузоперевозки() override {
		int sum = getКилограммыГрузаВОбщем();
		if (sum > 100) {
			cout << "Общая стоимость грузоперевозки = " << 2*sum << " долларов" << endl;
		} else if (sum > 70) {
			cout << "Общая стоимость грузоперевозки = " << 1.5*sum << " долларов" << endl;
		} else if (sum > 40) {
			cout << "Общая стоимость грузоперевозки = " << 0.7*sum << " долларов" << endl;
		} else {
			cout << "Общая стоимость грузоперевозки = " << 0 << " долларов" << endl;
		}
	}

	void showInfo() override {
		cout << "Название: " << name << ", скорость: " << speed << ", количество вагонов: " << количествоВагонов << endl;
	}

private:
	int количествоВагонов;
};

class Автомобиль : public Грузоперевозчик {

public:
	Автомобиль(const string name, const int speed, int*& груз, const int количествоЛитровБензина) : Грузоперевозчик(name, speed, груз) {
		this->количествоЛитровБензина = количествоЛитровБензина;
	}

	void показатьОбщуюСтоимостьГрузоперевозки() override {
		int sum = getКилограммыГрузаВОбщем();
		if (sum > 100) {
			cout << "Общая стоимость грузоперевозки = " << 3*sum << " долларов" << endl;
		} else if (sum > 70) {
			cout << "Общая стоимость грузоперевозки = " <<  1.1*sum << " долларов" << endl;
		} else if (sum > 40) {
			cout << "Общая стоимость грузоперевозки = " << 0.5*sum << " долларов" << endl;
		} else {
			cout << "Общая стоимость грузоперевозки = " << 0 << " долларов" << endl;
		}
	}

	void showInfo() override {
		cout << "Название: " << name << ", скорость: " << speed << ", количество бензина(в литрах): " << количествоЛитровБензина << endl;
	}

private:
	int количествоЛитровБензина;
};

class Самолет : public Грузоперевозчик {

public:
	Самолет(const string name, const int speed, int*& груз, const int количествоСтюардесс) : Грузоперевозчик(name, speed, груз) {
		this->количествоСтюардесс = количествоСтюардесс;
	}

	void показатьОбщуюСтоимостьГрузоперевозки() override {
		int sum = getКилограммыГрузаВОбщем();
		if (sum > 300) {
			cout << "Общая стоимость грузоперевозки = " << 4 * sum << " долларов" << endl;
		}
		else if (sum > 150) {
			cout << "Общая стоимость грузоперевозки = " << 2.5 * sum << " долларов" << endl;
		}
		else if (sum >> 100) {
			cout << "Общая стоимость грузоперевозки = " << 2 * sum << " долларов" << endl;
		}
		else if (sum > 70) {
			cout << "Общая стоимость грузоперевозки = " << 1.1 * sum << " долларов" << endl;
		}
		else if (sum > 40) {
			cout << "Общая стоимость грузоперевозки = " << 0.5 * sum << " долларов" << endl;
		}
		else {
			cout << "Общая стоимость грузоперевозки = " << 0 << " долларов" << endl;
		}
	}

	void showInfo() override {
		cout << "Название: " << name << ", скорость: " << speed << ", количество стюардесс на самолете: " << количествоСтюардесс << endl;
	}

private:
	int количествоСтюардесс;
};

int*& getRandomMassive();

int main() {
	setlocale(LC_ALL, "ru");

	int* грузы = getRandomMassive();
	Самолет самолет("Машина", 400, грузы, 4);
	самолет.показатьОбщуюСтоимостьГрузоперевозки();
	самолет.showInfo();
}

int*& getRandomMassive() {
	srand(time(0));
	int n = rand() % 10 + 1;
	int* грузы = new int[n];
	for (int i = 0; i < n; i++) {
		грузы[i] = rand() % 15;
	}

	return грузы;
}

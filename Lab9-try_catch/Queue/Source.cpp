#include <iostream>
#include "Queue.cpp"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	try {
		Queue<string> q;
		cout << q.isEmpty() << endl;
		q.push("asdasdasd");
		q.push("afbcxv");
		q.push("gf");
		cout << q.front() << " ";
		cout << q.back() << endl;
		q.pop();
		q.pop();
		q.pop();
		try {
			q.front();
		}
		catch (const QueueException& ex) {
			cerr << ex.what() << " " << ex.getDataState() << endl;
		}
		/*
		catch (const exception& ex) {
			cerr << ex.what();
		}*/
	} catch (...) {
		cerr << "В мэйне произошло что-то непонятное. " 
		<< "Это исключение было обработано, чтобы не вызывалась функция terminate" << endl;
	}

	return 0;
}
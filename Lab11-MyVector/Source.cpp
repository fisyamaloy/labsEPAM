#include <iostream>
#include "Vector.h"
#include <vector>
#include <algorithm>
#include "Timer.h"

using namespace std;

template <class T>
void showVector(const Vector<T>& v) {
	for (size_t i = 0; i < v.getSize(); ++i) {
		cout << v[i] << ' ';
	}
	cout << endl;
}

int main() {
	const size_t length = 300;
	Vector<int> v1(length);
	for (size_t i = 0; i < length; ++i) {
		v1[i] = pow((-1), i) * (i + 5);
	}

	vector<int>v2(length);
	for (size_t i = 0; i < length; ++i) {
		v2[i] = pow((-1), i) * (i + 5);
	}

	Timer t;
	v1.sort();
	cout << t.elapsed() << endl;

	t.reset();
	sort(v2.begin(), v2.end());
	cout << t.elapsed() << endl;

	t.reset();
	v1.find(324);
	cout << t.elapsed() << endl;

	t.reset();
	find(v2.begin(), v2.end(), 324);
	cout << t.elapsed() << endl;
}
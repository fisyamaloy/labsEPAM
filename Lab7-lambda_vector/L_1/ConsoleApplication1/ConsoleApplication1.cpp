#include <iostream>
#include <vector>

using namespace std;

void showVector(const vector<int>& v) {
	for (int num : v) {
		cout << num << " ";
	}
	cout << endl;
}

int main() {
	vector<int> vec;
	auto ex1 = [&vec](int n) {
		for (int i = 0; i < n; i++) {
			vec.push_back(i);
		}
	};

	int n;
	cout << "input size of vector: " << endl;
	cin >> n;
	ex1(n);
	showVector(vec);

	auto ex2 = [n](int k) {
		if (k <= n) {
			vector<int> newVector;
			int i;
			for (i = k; i < n; i++) {
				newVector.push_back(i);
			}
			for (i; i < n + k; i++) {
				newVector.push_back(i);
			}

			return newVector;
		} else {
			cout << "k must be less then size of vector" << endl;
		}
	};

	cout << "input k elems: " << endl;
	int k;
	cin >> k;
	vector<int> v = ex2(k);
	showVector(v);
}

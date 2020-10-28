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

	auto ex2 = [n, &vec](int k) {
		int i = 0;
		if (k <= n) {
			int size = vec.size();
			vec.erase(vec.begin(), vec.begin() + k);

			for (int j = size; j < size + k; ++j) {
				vec.push_back(j);
			}
		}
		else {
			cout << "k must be less then size of vector" << endl;
		}

	};

	cout << "input k elems: " << endl;
	int k;
	cin >> k;
	ex2(k);
	showVector(vec);
}

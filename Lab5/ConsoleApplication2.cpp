#include <iostream>
#include <ctime>
#include <assert.h>
#include <vector>
#include <string>
#define epsilon 0.00001

using namespace std;

template<class T>
void inputMassive(T*& arr, int& length) {
    srand(time(0));
    length = rand() % 10 + 2;
    arr = new int[length];
    for (int i = 0; i < length; i++) {
        arr[i] = 0.1 * (rand() % 1000 - 500);
    }
}

template<class T>
constexpr void showMassive(T*& arr, const unsigned int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<class T>
constexpr T getMax(T firstValue, T secondValue) {
    return firstValue - secondValue > epsilon ? firstValue : secondValue;
}

template<class T>
constexpr T getMax(T*& A, int length) {
    assert(length > 0);
    int max = A[0];
    for (int i = 1; i < length; i++) {
        if (max - A[i] < epsilon)
            max = A[i];
    }

    return max;
}


string getMax(const vector<string> rows, const int length) {
    assert(length > 0);
    int maxElemIndex = 0;
    for (int i = 1; i < length; i++) {
        if (rows[maxElemIndex] < rows[i])
            maxElemIndex = i;
    }

    return rows[maxElemIndex];
}


int main() {
    setlocale(LC_ALL, "ru");

    double a;
    double b;
    cin >> a;
    cin >> b;

    cout << "max number is " << getMax(a, b) << endl;

    int length;
    int* arr;
    inputMassive(arr, length);
    showMassive(arr, length);
    cout << "max number is " << getMax(arr, length) << endl;

    const int rowsAmount = 5;
    vector<string> rows;
    for (int i = 0; i < rowsAmount; i++) {
        string row;
        getline(cin,row);
        rows.push_back(row);
    }

    cout << "Строка максимальной длины: " << endl;
    cout << getMax(rows, rowsAmount) << endl;
}
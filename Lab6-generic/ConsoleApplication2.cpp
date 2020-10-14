#include <iostream>
#include <ctime>
#include <assert.h>
#include <vector>
#include <string>
#include "Array.h"
#define epsilon 0.00001

using namespace std;

template<class T>
void fillMassive(T*& arr, int& length) {
    srand(time(0));
    length = rand() % 10 + 2;
    arr = new T[length];
    for (int i = 0; i < length; i++) {
        arr[i] = 0.1 * (rand() % 100 - 50);
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
    double max = A[0];
    for (int i = 1; i < length; i++) {
        if (max - A[i] < epsilon)
            max = A[i];
    }

    return max;
}


string getMax(string* rows, const int length) {
    assert(length > 0);
    string maxRow = rows[0];
    for (int i = 1; i < length; i++) {
        if (maxRow.length() < rows[i].length()) {
            maxRow = rows[i];
        }
    }

    return maxRow;
}

int main() {
    setlocale(LC_ALL, "ru");

    double a;
    double b;
    cin >> a >> b;

    cout << "max number is " << getMax(a, b) << endl;

    int length;
    int* arr;
    fillMassive(arr, length);
    showMassive(arr, length);
    cout << "max number is " << getMax(arr, length) << endl;

    const int rowsAmount = 5;
    string* rows = new string[rowsAmount];
    cin.ignore();
    for (int i = 0; i < rowsAmount; i++) {
        getline(cin,rows[i]);
    }

    cout << "Строка максимальной длины: " << endl;
    cout << getMax(rows, rowsAmount) << endl;

    cout << "====================" << endl;

    
    Array<int> A(arr, length);
    showMassive(arr, length);
    cout << A.getAverageValue() << endl;

    double* B;
    int count;
    fillMassive(B, count);
    showMassive(B, count);
    Array<double> massive(B, count);
    cout << massive.getAverageValue() << endl;
}
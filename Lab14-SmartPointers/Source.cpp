#include <iostream>
#include "Unique.h"
#include <string>
#include <memory>

using namespace std;

int main() {
    int* value = new int{ -97 };
    int* val = new int{ 325 };
    Unique<int> a(value);
    Unique<int> b(std::move(a));

    a.swap(b);
 
    unique_ptr<int> c;
}
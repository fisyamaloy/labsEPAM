#include <iostream>
#include"Stack.h"

int main() {
    Stack<int> a;
    a.push(3);
    a.push(10);
    a.push(-5);

    for (int i = 0; i < 3; i++) {
        std::cout << a.top() << std::endl;
        a.pop();
    }
}
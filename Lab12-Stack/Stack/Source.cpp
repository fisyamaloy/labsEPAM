#include <iostream>
#include"Stack.h"

int main() {
    Stack<int> s;
    std::cout << s.empty() << std::endl;
    s.push(3);
    s.push(5);
    s.push(10);
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    s.push(100);
    s.push(10123);
    s.push(1034645634);
    std::cout << s.peek(0);
}
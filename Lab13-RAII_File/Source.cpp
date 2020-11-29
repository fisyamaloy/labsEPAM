#include <iostream>
#include "File.h"
#include <string>

using namespace std;

int main() {
    File f2("2.txt");
    f2.write("1asdasd\n");
    f2.readLine();

    File f1("1.txt");
    std::string text;
    while (!f1.end()) {
        text += f1.readLine() + "\n";
    }
    std::cout << text << std::endl;

    return 0;
}
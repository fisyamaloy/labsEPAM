#include <iostream>
#include <vector>
#include "IShapes.h"
#include "Rectangle.h"
#include "Circle.h"
#include "AreaCalculator.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	std::vector<IShape*> shapes{ new Rectangle(2, 3), new Circle(3) };
	AreaCalculator AC{std::move(shapes)};
	
	AreaCalculatorOutputter outputSum(AC);
	outputSum.console();
	outputSum.file("AreaSum.txt");
}

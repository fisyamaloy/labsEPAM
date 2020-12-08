#include <iostream>
#include <vector>
#include "ShapesI.h"
#include "Rectangle.h"
#include "Circle.h"
#include "AreaCalculator.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	std::vector<ShapeI*> shapes{ new Rectangle(2, 3), new Circle(2) };
	
	AreaCalculator AC{std::move(shapes)};
	
	SumCalculatorOutputter outputSum(AC);
	outputSum.console();
	outputSum.file("AreaSum.txt");

}

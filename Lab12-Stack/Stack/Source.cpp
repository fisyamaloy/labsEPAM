#include <iostream>
#include "Stack.h"
#include <vector>
#include "Taxi.h"
#include "TaxiFunctions.h"

void dataInput(std::vector<Taxi>& taxies) {
	taxies.push_back(Taxi("Fisyuk D.S", "BMW"));
	taxies.push_back(Taxi("Zavadich M.S", "VAZ-2201"));
	taxies.push_back(Taxi("Nogach M.N", "GAZ-53"));
	taxies.push_back(Taxi("Holopov A.H", "Bugatti Chiron"));
}

int main() {
	Stack<int> a;
	a.push(3);
	a.push(10);
	a.push(-5);

	std::vector<Taxi> taxies;
	dataInput(taxies);	
	TF::showAllTaxies(taxies);
	std::cout << "===================================" << std::endl;
	
	TF::pushTaxiToStart(taxies, Taxi("Plotko A.V","kopeika"));
	TF::showAllTaxies(taxies);
	std::cout << "===================================" << std::endl;

	TF::insertTaxi(taxies, Taxi("Alekseichyk L.V", "supercar"), 2);
	TF::showAllTaxies(taxies);
	std::cout << "===================================" << std::endl;

	TF::deleteTaxi(taxies, 1);
	TF::showAllTaxies(taxies);
	std::cout << "===================================" << std::endl;

	TF::callTaxi(taxies, 1);
	TF::callTaxi(taxies, 2);
	TF::callTaxi(taxies, 4);
	std::cout << "===================================" << std::endl;

	TF::releaseTaxi(taxies, 1);
	std::cout << "===================================" << std::endl;

	TF::showAllBusyTaxies(taxies);
	std::cout << "===================================" << std::endl;

	TF::showAllFreeTaxies(taxies);
	std::cout << "===================================" << std::endl;
}
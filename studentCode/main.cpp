#include "Car.h"
#include "ServiceRecord.h"
#include <iostream>

// Changed the iterator and inventory to memory addresses to pass by reference instead of value
// Also changed parameters to be model and year instead of ID. This is because the car in inventory is a copy, causing the IDs to be mismatched.
void findInInventory(std::vector<Car>::iterator& it, std::vector<Car>& inventory, std::string model, int year){
	while(it != inventory.end()){
		if(it->getModel() == model && it->getYear() == year){
			break;
		}
		++it;
	}
}

// Changed these all to memory addresses so we can pass by reference instead of value
void makeTrade(std::vector<Car>& inventory, Car& tradein, Car& tradeout){
	ServiceRecord outInspection("Sale inspection.", 0.0);
	tradeout.addRecord(outInspection);

	ServiceRecord inInspection("Presale inspection.", 19.95);
	tradein.addRecord(inInspection);

	auto it=inventory.begin();
	// Changed this to find by model and year instead of id
	findInInventory(it, inventory, tradeout.getModel(), tradeout.getYear());
	if(it != inventory.end()){
		inventory.erase(it);
	}
	inventory.push_back(tradein);
}

int main(int argc, char** argv){
	Car a(1985, "Toyota Hilux");
	ServiceRecord first("Oil change.", 9.95f);
	a.addRecord(first);

	Car b(a);
	first = ServiceRecord("Radiator flush.", 19.95);
	b.addRecord(first);

	std::vector<Car> inventory;
	inventory.push_back(a);
	inventory.push_back(b);

	Car c(b);
	c.setModel("Ford F150");

	std::cout << "Customer wants to trade in " << c << std::endl;
	std::cout << "They want to get " << a << std::endl;
	makeTrade(inventory, c, a);

	std::cout << "After trade, inventory is: " << std::endl;
	std::cout << "===========================" << std::endl;
	for(auto it = inventory.begin(); it != inventory.end(); ++it){
		std::cout << *it << std::endl;
	}

	Car A1(1985, "Toyota Hilux");
	A1.addRecord(ServiceRecord("Oil change", 9.95f));

	Car B1(2010, "Honda Civic");
	B1.addRecord(ServiceRecord("Brake replacement", 150.00f));
	B1.addRecord(ServiceRecord("Tire rotation", 25.00f));

	Car C1(2018, "Ford F150");
	C1.addRecord(ServiceRecord("Battery replacement", 120.00f));

	Car D1(2005, "Chevy Silverado");
	D1.addRecord(ServiceRecord("Transmission repair", 800.00f));

	Car E1(2020, "Tesla Model 3");
	E1.addRecord(ServiceRecord("Software update", 5.00f));

	std::vector<Car> cars = { A1, B1, C1, D1, E1 };

	std::cout << "=== Before sorting ===" << std::endl;
	for (const auto& car : cars)
		std::cout << car << std::endl;

	std::sort(cars.begin(), cars.end());

	std::cout << "=== After sorting (by total service cost) ===" << std::endl;
	for (const auto& car : cars)
		std::cout << car << std::endl;

	return 0;
}

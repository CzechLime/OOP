#include "TaxiCompany.h"

TaxiCompany::TaxiCompany (int maxCars, int maxDrivers, int maxDispatchers, int maxOrders, int maxCustomers) {
	this->carsNum = 0;
	this->maxCars = maxCars;
	this->taxiCars = new TaxiCar* [maxCars];
	this->driversNum = 0;
	this->maxDrivers = maxDrivers;
	this->drivers = new Driver* [maxDrivers];
	this->dispatchersNum = 0;
	this->maxDispatchers = maxDispatchers;
	this->dispatchers = new Dispatcher* [maxDispatchers];
	this->ordersNum = 0;
	this->maxOrders = maxOrders;
	this->orders = new Order* [maxOrders];
	this->customersNum = 0;
	this->maxCustomers = maxCustomers;
	this->customers = new Customer* [maxCustomers];
}

TaxiCompany::~TaxiCompany () {
	for (int i = 0; i < this->carsNum; i++) {
		delete this->taxiCars [i];
	}
	delete [] this->taxiCars;

	for (int i = 0; i < this->driversNum; i++) {
		delete this->drivers [i];
	}
	delete [] this->drivers;

	for (int i = 0; i < this->dispatchersNum; i++) {
		delete this->dispatchers [i];
	}
	delete [] this->dispatchers;

	for (int i = 0; i < this->ordersNum; i++) {
		delete this->orders [i];
	}
	delete [] this->orders;

	for (int i = 0; i < this->customersNum; i++) {
		delete this->customers [i];
	}
	delete [] this->customers;
}

void TaxiCompany::AddTaxiCar (int id, string brand, string numberPlate, double pricePerKm) {
	if (this->carsNum == this->maxCars) return;
	this->taxiCars [this->carsNum++] = new PassengerCar (id, brand, numberPlate, pricePerKm);
}

void TaxiCompany::AddTaxiCar (int id, string brand, string numberPlate, int capacity, double pricePerKm) {
	if (this->carsNum == this->maxCars) return;
	this->taxiCars [this->carsNum++] = new Minibus (id, brand, numberPlate, capacity, pricePerKm);
}

void TaxiCompany::AddDriver (int id, string firstName, string surname, int driverLicenseNum) {
	if (this->driversNum == this->maxDrivers) return;
	this->drivers [this->driversNum++] = new Driver (id, firstName, surname, driverLicenseNum);
}

void TaxiCompany::AddDispatcher (int id, string name, string surname, string area, int maxTaxis) {
	if (this->dispatchersNum == this->maxDispatchers) return;
	this->dispatchers [this->dispatchersNum++] = new Dispatcher (id, name, surname, area, maxTaxis);
}

void TaxiCompany::AddOrder (Order* order) {
	if (this->ordersNum == this->maxOrders) return;
	this->orders [this->ordersNum++] = order;
}

void TaxiCompany::AddCustomer (int id, string firstName, string surname, string location) {
	if (this->customersNum == this->maxCustomers) return;
	this->customers [this->customersNum++] = new Customer (id, firstName, surname, location);
}

Dispatcher* TaxiCompany::FindDispatcher (int id) {
	for (int i = 0; i < this->dispatchersNum; i++) {
		if (this->dispatchers [i]->GetId () == id) {
			return this->dispatchers [i];
		}
	}
	return nullptr;
}

Driver* TaxiCompany::FindDriver (int id) {
	for (int i = 0; i < this->driversNum; i++) {
		if (this->drivers[i]->GetId() == id) {
			return this->drivers[i];
		}
	}
	return nullptr;
}

Customer* TaxiCompany::FindCustomer (int id) {
	for (int i = 0; i < this->customersNum; i++) {
		if (this->customers[i]->GetId() == id) {
			return this->customers[i];
		}
	}
	return nullptr;
}

TaxiCar* TaxiCompany::FindTaxicar (int id) {
	for (int i = 0; i < this->carsNum; i++) {
		if (this->taxiCars [i]->GetId() == id) {
			return this->taxiCars [i];
		}
	}
	return nullptr;
}

Order* TaxiCompany::FindOrder (int id) {
	for (int i = 0; i < this->ordersNum; i++) {
		if (this->orders[i]->GetId() == id) {
			return this->orders[i];
		}
	}
	return nullptr;
}

void TaxiCompany::RemoveTaxiCar (int id) {
	for (int i = 0; i < this->carsNum; i++) {
		if (this->taxiCars [i]->GetId () == id) {
			delete taxiCars [i];
			taxiCars [i] = taxiCars [this->carsNum - 1];
			taxiCars [this->carsNum - 1] = nullptr;
			this->carsNum--;
			return;
		}
	}
}

void TaxiCompany::RemoveDriver (int id) {
	for (int i = 0; i < this->driversNum; i++) {
		if (this->drivers [i]->GetId () == id) {
			delete drivers [i];
			drivers [i] = drivers [this->driversNum - 1];
			drivers [this->driversNum - 1] = nullptr;
			this->driversNum--;
			return;
		}
	}
}

void TaxiCompany::RemoveDispatcher (int id) {
	for (int i = 0; i < this->dispatchersNum; i++) {
		if (this->dispatchers [i]->GetId () == id) {
			delete dispatchers [i];
			dispatchers [i] = dispatchers [this->dispatchersNum - 1];
			dispatchers [this->dispatchersNum - 1] = nullptr;
			this->dispatchersNum--;
			return;
		}
	}
}

void TaxiCompany::RemoveOrder (int id) {
	for (int i = 0; i < this->ordersNum; i++) {
		if (this->orders [i]->GetId () == id) {
			delete orders [i];
			orders [i] = orders [this->ordersNum - 1];
			orders [this->ordersNum - 1] = nullptr;
			this->ordersNum--;
			return;
		}
	}
}

void TaxiCompany::RemoveCustomer (int id) {
	for (int i = 0; i < this->customersNum; i++) {
		if (this->customers [i]->GetId () == id) {
			delete customers [i];
			customers [i] = customers [this->customersNum - 1];
			customers [this->customersNum - 1] = nullptr;
			this->customersNum--;
			return;
		}
	}
}

string TaxiCompany::printInfo () { // výpis informací o taxislužbì
	string output;

	output += "Number of dispatchers: " + std::to_string (this->dispatchersNum) + "\n";
	output += "Number of drivers: " + std::to_string (this->driversNum) + "\n";
	output += "Number of cars: " + std::to_string (this->carsNum) + "\n";
	output += "Number of customers: " + std::to_string (this->customersNum) + "\n";
	output += "\n";

	for (int i = 0; i < this->dispatchersNum; i++) {
		Dispatcher* thisDispatcher = this->dispatchers [i];
		output += "Dispatcher " + std::to_string (thisDispatcher->GetId ()) + ":\n";
		output += "Name: " + thisDispatcher->GetFirstName () + " " + thisDispatcher->GetSurname () + ", Area: " + thisDispatcher->GetArea() + "\n";
	}
	output += "\n";

	for (int i = 0; i < this->driversNum; i++) {
		Driver* thisDriver = this->drivers [i];
		output += "Driver " + std::to_string (thisDriver->GetId()) + ":\n";
		output += "Name: " + thisDriver->GetFirstName () + " " + thisDriver->GetSurname() + ", Driver's License Number: " + std::to_string (thisDriver->GetLicenseNum ()) + "\n";
	}
	output += "\n";

	for (int i = 0; i < this->carsNum; i++) {
		TaxiCar* thisTaxi = this->taxiCars [i];
		output += "Taxi " + std::to_string (thisTaxi->GetId()) + ":\n";
		output += "Brand: " + thisTaxi->GetBrand () + ", Number Plate: " + thisTaxi->GetNumberPlate () + "\n";
	}
	output += "\n";

	for (int i = 0; i < this->customersNum; i++) {
		Customer* thisCustomer = this->customers [i];
		output += "Dispatcher " + std::to_string (thisCustomer->GetId ()) + ":\n";
		output += "Name: " + thisCustomer->GetFirstName () + " " + thisCustomer->GetSurname() + ", Location: " + thisCustomer->GetLocation () + "\n";
	}
	output += "\n";

	for (int i = 0; i < this->ordersNum; i++) {
		Order* thisOrder = this->orders [i];
		output += "Order " + std::to_string (thisOrder->GetId ()) + ":\n";
		output += "Price: " + std::to_string (thisOrder->GetPrice()) + "\n";
	}

	return output;
}
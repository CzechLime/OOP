#pragma once

#include "TaxiCar.h"
#include "Order.h"
#include "AbstractPerson.h"

using std::string;

class Dispatcher : public AbstractPerson {
private:
	int id;
	string name;
	string surname;
	string area;
	int assignedTaxisNum;
	int maxTaxis;
	TaxiCar** taxiCars;

public:
	Dispatcher (int id, string name, string surname, string area, int maxTaxis);
	~Dispatcher ();

	int GetId () override;
	string GetFirstName () override;
	string GetSurname () override;
	string GetArea ();
	int GetAssignedTaxisNum ();
	int GetMaxTaxis ();

	void AssignTaxiCar (TaxiCar* taxiCar);
	Order* CreateOrder (int id, Customer* customer, string startingAddress, string endingAddress);
};
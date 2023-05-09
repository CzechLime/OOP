#pragma once

#include "TaxiCar.h"
	#include "PassengerCar.h"
	#include "Minibus.h"
#include "Dispatcher.h"
#include "Driver.h"
#include "Customer.h"
#include "Order.h"

using std::string;

class TaxiCompany {
private:
	int carsNum;
	int maxCars;
	TaxiCar** taxiCars;
	int driversNum;
	int maxDrivers;
	Driver** drivers;
	int dispatchersNum;
	int maxDispatchers;
	Dispatcher** dispatchers;
	int ordersNum;
	int maxOrders;
	Order** orders;
	int customersNum;
	int maxCustomers;
	Customer** customers;

public:
	TaxiCompany (int maxCars, int maxDrivers, int maxDispatchers, int maxOrders, int maxCustomers);
	~TaxiCompany ();

	void AddTaxiCar (int id, string brand, string numberPlate, double pricePerKm); // passengerCar
	void AddTaxiCar (int id, string brand, string numberPlate, int capacity, double pricePerKm); // minibus
	void AddDriver (int id, string firstName, string surname, int driverLicenseNum);
	void AddDispatcher (int id, string name, string surname, string area, int maxTaxis);
	void AddOrder (Order* order);
	void AddCustomer (int id, string firstName, string surname, string location);

	Dispatcher* FindDispatcher(int id);
	Driver* FindDriver(int id);
	Customer* FindCustomer(int id);
	TaxiCar* FindTaxicar(int id);
	Order* FindOrder(int id);

	void RemoveTaxiCar (int id);
	void RemoveDriver (int id);
	void RemoveDispatcher (int id);
	void RemoveOrder (int id);
	void RemoveCustomer (int id);

	string printInfo ();
};


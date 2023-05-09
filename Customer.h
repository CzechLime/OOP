#pragma once
#include <string>
#include "Order.h"
#include "AbstractPerson.h"

using std::string;

class Customer : public AbstractPerson {
private:
	int id;
	string firstName;
	string surname;
	string location;
	string destination;

public:
	Customer (int id, string firstName, string surname, string location);
	~Customer ();

	int GetId () override;
	string GetFirstName () override;
	string GetSurname () override;
	string GetLocation ();
	string GetDestination ();

	void setDestination (string destination);
};


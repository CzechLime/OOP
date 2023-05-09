#include "Customer.h"

int customersNum = 0;

Customer::Customer (int id, string firstName, string surname, string location) {
	customersNum++;
	this->id = id;
	this->firstName = firstName;
	this->surname = surname;
	this->location = location;
	this->destination = "empty"; // destinace (zatím) nebyla zvolena
}

Customer::~Customer () {
	customersNum--;
}

int Customer::GetId () {
	return this->id;
}

string Customer::GetFirstName () {
	return this->firstName;
}

string Customer::GetSurname () {
	return this->surname;
}

string Customer::GetLocation () {
	return this->location;
}

string Customer::GetDestination () {
	return this->destination;
}

void Customer::setDestination (string destination) {
	this->destination = destination;
}

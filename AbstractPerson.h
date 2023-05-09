#pragma once
#include <string>

using std::string;

class AbstractPerson {
public:
	virtual int GetId () = 0;
	virtual string GetFirstName () = 0;
	virtual string GetSurname () = 0;
};


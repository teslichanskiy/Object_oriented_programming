#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>


using namespace std;


struct Captain{
	string capname;
	string capsurname;

}; 

class Database
{
private:
	string shipname, country, type;
	int year;
	Captain captain;
public:
	Database();
	Database(string shipnam, int yea, string countr, string typ, Captain cap);
	~Database();

	void Dataout();
	void Datain(string shipnam, int yea, string countr, string typ, Captain cap);

	Database& operator=(const Database d);
	friend bool operator==(const Database& d1, const Database& d2);
	friend bool operator>(const Database &d1, const Database& d2);
	friend bool operator<(const Database &d1, const Database& d2);
	friend bool operator>=(const Database &d1, const Database& d2);
	friend bool operator<=(const Database &d1, const Database& d2);

	string get_shipname() const { return shipname; };
	int get_year() const { return year; };
	string get_country() const { return country; };
	string get_type() const { return type; };
    Captain get_captain() const { return captain; };

};


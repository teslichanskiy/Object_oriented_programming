#include "Class.h"

Database::Database() {

	shipname = "";
	year = 0;
	country = "";
	type = "";
	captain.capname = "";
	captain.capsurname = "";

}

Database::Database(string shipnam, int yea, string countr, string typ, Captain cap) {
 
	shipname = shipnam;
	year = yea;
	country = countr;
	type = typ;
	captain.capname = cap.capname;
	captain.capsurname = cap.capsurname;
}

Database::~Database() {};

void Database::Dataout() {
	cout << "Shipname: " << shipname << endl;
	cout << "Year: " << year << endl;
	cout << "Country: " << country << endl;
	cout << "Type: " << type << endl;
	cout << "Captain: " << captain.capname << " " << captain.capsurname << endl;
}

void Database::Datain(string shipnam, int yea, string countr, string typ, Captain cap) {
	shipname = shipnam;
	year = yea;
	country = countr;
	type = typ;
	captain.capname = cap.capname;
	captain.capsurname = cap.capsurname;
}

Database & Database::operator=(const Database d) {
	this->shipname = d.shipname;
	this->year = d.year;
	this->country = d.country;
	this->type = d.type;
	this->captain.capname = d.captain.capname;
	this->captain.capsurname = d.captain.capsurname;
	return *this;
}
bool operator==(const Database& d1, const Database& d2) {
	return (d1.shipname == d2.shipname) && (d1.type == d2.type);
}
bool operator>(const Database& d1, const Database& d2) {
	return (d1.shipname > d2.shipname) || ((d1.shipname == d2.shipname) && (d1.type > d2.type));
}
bool operator<(const Database& d1, const Database& d2) {
	return (d1.shipname < d2.shipname) || ((d1.shipname == d2.shipname) && (d1.type < d2.type));
}
bool operator>=(const Database& d1, const Database& d2) {
	return (d1 > d2) || (d1 == d2);
}
bool operator<=(const Database& d1, const Database& d2) {
	return (d1 < d2) || (d1 == d2);
}

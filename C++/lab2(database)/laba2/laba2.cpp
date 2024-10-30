#include "Header.h"

int main() {

	int size = 0;
	Database* d = new Database[size];

	Dataread(d, size);
	//Dataprint(d, size);
	//Datasort1(d, size);
	Datasort2(d, size);
	//Dataprint(d, size);
	Datatofile(d, size);

	return 0;
}
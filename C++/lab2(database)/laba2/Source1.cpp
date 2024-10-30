#include "Header.h"

void Dataread(Database* (&d), int(&n)) {


	ifstream read("C:\\Users\\Данила\\Desktop\\Datebase.txt");       // поток для чтения

	if (read) {

		string shipname, country, type;
		int year;
		Captain captain;

		read >> n;

		d = new Database[n];

		for (int i = 0; i < n; i++) {

			read >> shipname;
			read >> year;
			read >> country;
			read >> type;
			read >> captain.capname >> captain.capsurname;

			d[i].Datain(shipname, year, country, type, captain);
		}
	}
	else
		cout << "Ошибка открытия файла" << endl;

	read.close();
}

void Dataprint(Database *d, int n) {
	for (int i = 0; i < n; i++) {
		d[i].Dataout();
		cout << "" << endl;
	}
}

float Datasort1(Database* d, int n) {
	unsigned int start_time = clock();
	Database key;
	int i = 0;
	for (int j = 1;j < n;j++) {
		key = d[j];
		i = j - 1;
		while (i >= 0 && d[i] > key) {
			d[i + 1] = d[i];
			i--;
			d[i + 1] = key;
		}
	}
	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time; // искомое время
	cout << "Time of sort:" << (float)search_time / CLOCKS_PER_SEC << endl;
	return (float)search_time / CLOCKS_PER_SEC;
}

void pyramid(Database* d, int n, int root)
{
	Database* tmp = new Database[1];
	int largest = root; 
	int l = 2 * root + 1; 
	int r = 2 * root + 2; 

	if (l < n && d[l] > d[largest])
		largest = l;

	if (r < n && d[r] > d[largest])
		largest = r;

	if (largest != root)
	{
		memcpy(tmp, &d[root], sizeof(Database));
		memcpy(&d[root], &d[largest], sizeof(Database));
		memcpy(&d[largest], tmp, sizeof(Database));

		pyramid(d, n, largest);
	}
}


float Datasort2(Database* d, int n)
{
	unsigned int start_time = clock();

	Database* tmp = new Database[1];
	for (int i = n / 2 - 1; i >= 0; i--)
		pyramid(d, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		memcpy(tmp, &d[0], sizeof(Database));
		memcpy(&d[0], &d[i], sizeof(Database));
		memcpy(&d[i], tmp, sizeof(Database));

		pyramid(d, i, 0);
	}
	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time; // искомое время
	cout << "Time of sort: " << (float)search_time / CLOCKS_PER_SEC << endl;
	return (float)search_time / CLOCKS_PER_SEC;
}

void Datatofile(Database* d, int n) {


	ofstream write("SortedBase.txt");       // поток для записи

	if (write) {

		 write << n << endl;

		for (int i = 0; i < n; i++) {

			write << d[i].get_shipname() << endl;
			write << d[i].get_year() << endl;
			write << d[i].get_country() << endl;
			write << d[i].get_type() << endl;
			write << d[i].get_captain().capname << " " << d[i].get_captain().capsurname << endl;
		}
	}
	else
		cout << "Ошибка открытия файла" << endl;

	write.close();
}
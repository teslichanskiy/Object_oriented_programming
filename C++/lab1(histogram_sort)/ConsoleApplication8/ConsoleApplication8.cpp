#define _CRT_SECURE_NO_WARNINGS
#include "histogram.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;


void AddBar(Histogram& historgam, const char* strName);
bool AppendBar(Histogram& historgam, const char* strName);



void AddBlock(Histogram& historgam, const char* strName) {
	if (!AppendBar(historgam, strName)) {
		AddBar(historgam, strName);
	}
}


void PrintHistogram(const Histogram& historgam) {
	for (int i = 0; i < historgam.nBarsSize; i++) {
		cout << historgam.BarNames[i] << '|';
		//cout.setf
		cout << setfill(historgam.chBlock) << setw(10 * historgam.Bars[i] / historgam.nMaxBar) << "" << /*ends <<*/ endl;
	}
}

bool AppendBar(Histogram& historgam, const char* strName) {
	for (int i = 0; i < historgam.nBarsSize; i++) {
		if (strcmp(historgam.BarNames[i], strName) == 0) {
			historgam.nMaxBar = max(historgam.nMaxBar, ++historgam.Bars[i]);
			return true;
		}
	}
	return false;
}


void AddBar(Histogram& historgam, const char* strName) {
	char** newNames = new char* [historgam.nBarsSize + 1];
	int* newBars = new int[historgam.nBarsSize + 1];
	if (historgam.nBarsSize > 0) {
		for (int i = 0; i < historgam.nBarsSize; i++) {
			newNames[i] = historgam.BarNames[i];
			newBars[i] = historgam.Bars[i];
		}
		delete[] historgam.BarNames;
		delete[] historgam.Bars;
	}

	newNames[historgam.nBarsSize] = new char[strlen(strName) + 1];
	strcpy(newNames[historgam.nBarsSize], strName);
	newBars[historgam.nBarsSize] = 1;

	historgam.nBarsSize++;
	historgam.BarNames = newNames;
	historgam.Bars = newBars;
}

void Enterstr(Histogram& historgam) {

	string str;
	char* strtmp, ch;
	int i, j = 0, k = 0;
	std::getline(std::cin, str);
	for (int i = 0; i < str.length(); i++) {

		if (str[i] != ' ') {

			if (j == 0)
				strtmp = new char[str.length()];
			strtmp[j] = str[i];
			j++;
		}

		if (j > 0 && (str[i] == ' ' || i == str.length() - 1)) {

			while (k < j) {
				ch = strtmp[k];
				strtmp[k] = (char)tolower(ch);
				k++;
			}
			strtmp[j] = '\0';
			AddBlock(historgam, strtmp);
			delete[] strtmp;
			j = 0;
			k = 0;
		}
	}
}

void PrintHistogramnew(const Histogram& historgam) {

	cout << "Выровненная гистограмма" << endl;
	int maxlen = 0;

	for (int i = 0; i < historgam.nBarsSize; i++)
		maxlen = (maxlen <= strlen(historgam.BarNames[i])) ? strlen(historgam.BarNames[i]) : maxlen;

	for (int i = 0; i < historgam.nBarsSize; i++) {

		cout << historgam.BarNames[i];
		cout << setfill(' ') << setw(maxlen - (int)strlen(historgam.BarNames[i] + 1)) << "|";
		cout.setf(ios::right);
		cout << setfill(historgam.chBlock) << setw(10 * historgam.Bars[i] / historgam.nMaxBar) << "" << /*ends <<*/ endl;
	}
}

void Sortbyname(Histogram& historgam) {

	char* min, * max;
	int i, ind = 0, k = 0;

	if (historgam.bAscending == true) {

		while (historgam.BarNames[k]) {

			min = historgam.BarNames[ind];
			for (i = k; i < historgam.nBarsSize; i++) {

				if (strcmp(min, historgam.BarNames[i]) > 0) {

					min = historgam.BarNames[i];
					ind = i;
				}
			}
			swap(historgam.BarNames[k], historgam.BarNames[ind]);
			swap(historgam.Bars[k], historgam.Bars[ind]);
			k++;
			ind = k;
		}
	}

	if (historgam.bAscending == false) {

		while (historgam.BarNames[k]) {

			max = historgam.BarNames[ind];
			for (i = k; i < historgam.nBarsSize; i++) {

				if (strcmp(max, historgam.BarNames[i]) < 0) {

					max = historgam.BarNames[i];
					ind = i;
				}
			}
			swap(historgam.BarNames[k], historgam.BarNames[ind]);
			swap(historgam.Bars[k], historgam.Bars[ind]);
			k++;
			ind = k;
		}
	}
}

int main() {

	const char* const strProgramName = "Histogramer 1.0";

	std::cout << std::setfill('*') << std::setw(strlen(strProgramName) + 4) << "" << std::endl;
	std::cout << '*' << std::setfill(' ') << std::setw(strlen(strProgramName) + 3) << '*' << std::endl;
	std::cout << "* " << strProgramName << " *" << std::endl;
	std::cout << '*' << std::setfill(' ') << std::setw(strlen(strProgramName) + 3) << '*' << std::endl;
	std::cout << std::setfill('*') << std::setw(strlen(strProgramName) + 4) << "" << std::endl << std::endl;

	Histogram Mybarchart;

	InitHistogram(Mybarchart);
	Enterstr(Mybarchart);
	//PrintHistogram(Mybarchart);
	Sortbyname(Mybarchart);
	PrintHistogramnew(Mybarchart);
	DestroyHistogram(Mybarchart);

	return 0;
}
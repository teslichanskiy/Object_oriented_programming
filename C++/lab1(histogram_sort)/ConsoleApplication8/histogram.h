#pragma once

typedef struct {
	char** BarNames;
	int* Bars;
	int nBarsSize;
	char chBlock;
	int nMaxBar;
	bool bAscending;
} Histogram;



void PrintHistogram(const Histogram& historgam);
void AddBlock(Histogram& historgam, const char* strName);
void StrToHist(Histogram& historgam);
void PrintHistogramnew(const Histogram& historgam);

# include "histogram.inl"

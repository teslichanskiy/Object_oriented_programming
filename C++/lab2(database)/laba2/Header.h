#pragma once
  
#include "Class.h"

void Dataread(Database* (&d), int(&n));
void Dataprint(Database* d, int n);
float Datasort1(Database* d, int n);
void pyramid(Database* d, int n, int root);
float Datasort2(Database* d, int n);
void Datatofile(Database* d, int n);
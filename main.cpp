#include <iostream>
#include <omp.h>
#include <math.h>
#include <time.h>

#include "hDef.h"
#include "hSeri.h"
#include "hParalel.h"

using namespace std;

int main() {
	printf("\nA = %d", N);
	printf("\nthread sayisi: %d", NTHREADS);
	fSeri();
	fParalel();
	getchar();
	return 0;
}



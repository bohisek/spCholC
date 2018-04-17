//============================================================================
// Name        : spChol.cpp
// Author      : Honzik
// Version     :
// Copyright   :
// Description : spChol in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <math.h>

#include "spChol.h"

using namespace std;

#define Np 4  // N/p
#define nDV 16

int main() {

    // any stupid 5 diagonal symmetric positive definite matrix given in DIAG format
	// diagonals extended for ghost cells
	// declared on stack
	float ecc[nDV+2*Np] = {0,0,0,0,49,38,40,40,59,40,30,40,66,24,40,40,83,40,40,40,0,0,0,0};
	float eww[nDV+1]    = {0,-2,-2,-5,0,-3,-2,-2,0,-7,-2,-2,0,-6,-2,-2,0};
	float ess[nDV+Np]   = {0,0,0,0,-9,-2,-2,-10,-2,-2,-11,-2,-2,-2,-2,-2,0,0,0,0};

	float L[nDV * (Np+1)] = {};

	spChol(L,ecc,eww,ess,Np,nDV);
    printChol(L,Np,nDV);

	return 0;
}

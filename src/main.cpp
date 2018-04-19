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
	float rhs[nDV+2*Np] = {0,0,0,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,0,0,0,0};

	/*float ecc[nDV+2*Np] = {0,0,154,112,179,144,0,0};
	float eww[nDV+1]    = {0,-4,0,-4,0};
	float ess[nDV+Np]   = {0,0,-4,-13,0,0};
	float rhs[nDV+2*Np] = {0,0,1,2,3,4,0,0};*/

	float L[nDV * (Np+1)] = {};
    float x[nDV+2*Np] = {};

	spChol(L,ecc,eww,ess,Np,nDV);
    solve(x,L,rhs,Np,nDV); // direct solve
    //printChol(L,Np,nDV);
    //printX(x,Np,nDV);

	return 0;
}

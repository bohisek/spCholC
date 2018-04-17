/*
 * spChol.cpp
 *
 *  Created on: Apr 17, 2018
 *      Author: jbohacek
 */

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

#include "spChol.h"

#define min(a,b) a<b ? a : b
#define max(a,b) a>b ? a : b

void spChol(float *L,const float *ecc,const float *eww,const float *ess,const int Np,const int nDV)
{
	float sumL2jk, sumLikLjk;

	for (int i=0; i<nDV; i++)
		{
			int ixm = min(Np,i);
			sumL2jk = 0.;                      // reset sum of squares of Ljk for forthcoming Lj,j calculation

			for (int j=0; j<ixm; j++)
			{
				int jr = int(max(i-Np, 0)) + j;
				int jy = ixm - j;
				int idL = jr + nDV * jy;
				sumLikLjk = 0.;                // reset sum of squares of Lik*Ljk

				 for (int k=j-1; k>=0; k--)
				 {
					 int jrk = jr - k - 1;   // for Lik as well as Ljk
					 int jyi = jy + k + 1;     // Lik
					 int jyj =    + k + 1;     // Ljk
					 sumLikLjk += L[jrk+nDV*jyi] * L[jrk+nDV*jyj];
				 }
				 switch(jy)
				 {
				 case 1:
					 L[idL] = 1/L[jr]  * (eww[jr+1] - sumLikLjk);
					 break;
				 case 4:
					 L[idL] = 1/L[jr]  * (ess[jr+Np] - sumLikLjk);
					 break;
				 default:
					 L[idL] = 1/L[jr]  * (            - sumLikLjk);

				 }
				 sumL2jk = sumL2jk + L[idL]*L[idL];
			}
			L[i] = sqrt(ecc[i+Np] - sumL2jk);
		}
}

void printChol(const float *L,const int Np,const int nDV)
{
	for (int i=0; i<nDV; i++)
	{
		for (int j=0; j<Np+1; j++)
		{
			int idL = i + nDV * j;
			cout << setprecision(5) << fixed << L[idL] << ", ";
		}
		cout << endl;
	}
}



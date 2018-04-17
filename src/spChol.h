/*
 * spChol.h
 *
 *  Created on: Apr 17, 2018
 *      Author: jbohacek
 */

#ifndef SPCHOL_H_
#define SPCHOL_H_

void spChol(float *L,const float *ecc,const float *eww,const float *ess,const int Np,const int nDV);
void printChol(const float *L,const int Np,const int nDV);

#endif /* SPCHOL_H_ */

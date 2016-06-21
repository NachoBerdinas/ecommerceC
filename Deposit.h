//
// Created by Diego Baldassare on 23/05/2016.
//

#ifndef DEPOSIT_H
#define DEPOSIT_H

typedef struct Deposit{
	int depositNumber;
	int paymentID;
	double amount;
} Deposit;

Deposit* deposit(int depositNumber, int paymentID, double amount);
void destroyDeposit(Deposit *deposit);

#endif //DEPOSIT_H
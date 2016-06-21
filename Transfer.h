//
// Created by Diego Baldassare on 23/05/2016.
//

#ifndef TRANSFER_H
#define TRANSFER_H

typedef struct Transfer{
	int transferNumber;
	int paymentID;
	double amount;
} Transfer;

Transfer* transfer(int transferNumber, int paymentID, double amount);
void destroyTransfer(Transfer *transfer);

#endif //TRANSFER_H
//
// Created by Diego Baldassare on 23/05/2016.
//

#ifndef CREDITCARD_H
#define CREDITCARD_H

typedef struct CreditCard{
	int cardNumber;
	int paymentID;
	double amount;
} CreditCard;

CreditCard* creditCard(int cardNumber, int paymentID, double amount);
void destroyCreditCard(CreditCard *creditCard);

#endif //CREDITCARD_H
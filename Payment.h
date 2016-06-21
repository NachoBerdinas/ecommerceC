#ifndef PAYMENT_H
#define PAYMENT_H

#include "Bill.h"
#include "CreditCard.h"
#include "Transfer.h"
#include "Deposit.h"

typedef struct Payment{
	Bill* bill;
	int paymentID;
	CreditCard* creditCard;
	Transfer* transfer;
	Deposit* deposit;
} Payment;

Payment *pay(Bill *bill, int paymentId,double creditCardAmount, double transferAmount,double depositAmount);
void destroyPayment(Payment *payment);

#endif //PAYMENT_H

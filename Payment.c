//
// Created by Diego Baldassare on 23/05/2016.
//

#include <stdio.h>
#include <stdlib.h>
#include "Payment.h"


Payment* pay(Bill *bill, int paymentId,double creditCardAmount, double transferAmount,double depositAmount) {
    Payment* payment = malloc(sizeof(Payment));
    payment->bill = bill;
    bill->paymentID = paymentId;
    payment->paymentID = paymentId;

	if (creditCardAmount > 0){
	    int cardNumber;
        printf("\nInsert credit card number: ");
	    scanf("%d", &cardNumber);
	    payment->creditCard = creditCard(cardNumber, payment->paymentID, creditCardAmount);
    }    

    if (transferAmount > 0){
	    int transferNumber;
        printf("Insert account number for transfer: ");
	    scanf("%d", &transferNumber);
	    payment->transfer = transfer(transferNumber, payment->paymentID, transferAmount);
    }   

    if (depositAmount > 0){
	    int depositNumber;
        printf("Insert account number for deposit: ");
	    scanf("%d", &depositNumber);
	    payment->deposit = deposit(depositNumber, payment->paymentID, depositAmount);
    }

    if((depositAmount+creditCardAmount+transferAmount) == bill->amount){
        return payment;
    } else{
        bill->paymentID = -1;
        destroyPayment(payment);
        return NULL;
    }


}

void destroyPayment(Payment *payment) {
    free(payment->creditCard);
    free(payment->transfer);
    free(payment->deposit);
    free(payment);
}

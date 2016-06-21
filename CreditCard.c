//
// Created by Diego Baldassare on 23/05/2016.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CreditCard.h"

CreditCard* creditCard(int cardNumber, int paymentID, double amount) {
    CreditCard* creditCard = malloc(sizeof(CreditCard));
    creditCard->cardNumber = cardNumber;
    creditCard->paymentID = paymentID;
    creditCard->amount = amount;
    return creditCard;
}

void destroyCreditCard(CreditCard *creditCard) {
    free(creditCard);
}
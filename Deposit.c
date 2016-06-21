//
// Created by Diego Baldassare on 23/05/2016.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Deposit.h"

Deposit* deposit(int depositNumber, int paymentID, double amount) {
    Deposit* deposit = malloc(sizeof(Deposit));
    deposit->depositNumber = depositNumber;
    deposit->paymentID = paymentID;
    deposit->amount = amount;
    return deposit;
}

void destroyDeposit(Deposit *deposit) {
    free(deposit);
}
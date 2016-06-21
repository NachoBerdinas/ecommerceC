//
// Created by Diego Baldassare on 23/05/2016.
//

#include <stdio.h>
#include <stdlib.h>
#include "Transfer.h"

Transfer* transfer(int transferNumber, int paymentID, double amount) {
    Transfer* transfer = malloc(sizeof(Transfer));
    transfer->transferNumber = transferNumber;
    transfer->paymentID = paymentID;
    transfer->amount = amount;
    return transfer;
}

void destroyTransfer(Transfer *transfer) {
    free(transfer);
}
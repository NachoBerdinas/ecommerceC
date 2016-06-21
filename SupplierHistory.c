
#include <stdio.h>
#include <stdlib.h>
#include "SupplierHistory.h"


SupplierHistory* createSupplierHistory(int id) {
    SupplierHistory* supplierHistory;
    supplierHistory = (SupplierHistory*)malloc(sizeof(SupplierHistory));
    supplierHistory->maxReceipts = 5;
    supplierHistory->currentReceipts = 0;
    supplierHistory->receipts = malloc(sizeof(PaymentReceipt*)*5);
    supplierHistory->id = id;

    return supplierHistory;
}

void addReceipt(PaymentReceipt* receipt, SupplierHistory* supplierHistory) {
    if(supplierHistory->currentReceipts == supplierHistory->maxReceipts){
        supplierHistory->maxReceipts += supplierHistory->maxReceipts;
        supplierHistory->receipts = realloc(supplierHistory->receipts, sizeof(Product*)*supplierHistory->maxReceipts);
    }
    supplierHistory->receipts[supplierHistory->currentReceipts] = receipt;
    supplierHistory->currentReceipts++;
}

int getSupplierHistoryID(SupplierHistory* supplier) {
    return supplier->id;
}


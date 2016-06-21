//
// Created by Tomi on 12/05/2016.
//

#ifndef ECOMERCE_TRANSACTIONHISTORY_H
#define ECOMERCE_TRANSACTIONHISTORY_H

#include "Bill.h"

typedef struct TransactionHistory{

    int historyID;
    int userID;
    Bill** bills;
    int billAmount;
    int maxBills;

} TransactionHistory;

TransactionHistory* createTransactionHistory(int userID,int historyID);
void addBill(TransactionHistory* transactions, Bill* bill);
Bill** getUnpaidBills(TransactionHistory* transactions);
int getUnpaidBillsCount(TransactionHistory *transactions);
void printTransactionHistory(TransactionHistory* transactions);
void destroyTransactionHistory(TransactionHistory* transactions);


#endif //ECOMERCE_TRANSACTIONHISTORY_H

#include "TransactionHistory.h"
#include <stdlib.h>
#include <stdio.h>

TransactionHistory* createTransactionHistory(int userID,int historyID) {
    TransactionHistory* transactions = malloc(sizeof(TransactionHistory));
    transactions->historyID = historyID;
    transactions->userID = userID;
    transactions->billAmount = 0;
    transactions->maxBills = 10;
    transactions->bills = malloc(sizeof(Bill*)*transactions->maxBills);
    return transactions;
}

void printTransactionHistory(TransactionHistory *transactions) {
    int i;
    printf("Printing transaction history %d:",transactions->historyID);
    for(i = 0;i<transactions->billAmount;i++){
        printBill(transactions->bills[i]);
        printf("\n");
    }
}

Bill** getUnpaidBills(TransactionHistory *transactions) {
    int i = 0,j = 0;
    int unpayed = getUnpaidBillsCount(transactions);
    Bill** ret = malloc(unpayed * sizeof(Bill*));
    for(i = 0;i<transactions->billAmount;i++){
        if(isBillPayed(transactions->bills[i]) == 0){
            ret[j] = transactions->bills[i];
            j++;
        }
    }
    return ret;
}

int getUnpaidBillsCount(TransactionHistory *transactions) {
    int i;
    int unpayed = 0;
    for(i = 0;i<transactions->billAmount;i++){
        if(isBillPayed(transactions->bills[i]) == 0){
            unpayed++;
        }
    }
    return unpayed;
}

void addBill(TransactionHistory *transactions, Bill *bill) {
    if(transactions->maxBills == transactions->billAmount){
        transactions->maxBills += transactions->maxBills;
        transactions->bills = realloc(transactions->bills,sizeof(Bill*)*transactions->maxBills);
    }
    transactions->bills[transactions->billAmount] = bill;
    transactions->billAmount++;
}

void destroyTransactionHistory(TransactionHistory *transactions) {
    int i;
    for(i = 0;i<transactions->billAmount;i++){
        destroyBill(transactions->bills[i]);
    }
    free(transactions->bills);
    free(transactions);
}

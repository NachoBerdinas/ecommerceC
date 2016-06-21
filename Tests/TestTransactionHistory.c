
#include <stdio.h>
#include <stdlib.h>
#include "../Bill.h"
#include "../Payment.h"
#include "../TransactionHistory.h"

int main(int argc, char** argv) {

    Shipping* myShipping = createShipping(100,"Cargas SA",0.15,"Florida 9600",1);
    Bill* myBill1 = createBill(100,"15/5/1995",0.20,1);
    Bill* myBill2 = createShippingBill(500,"15/6/1997",0.50,myShipping,2);
    Bill* myBill3 = createBill(1750,"15/6/1993",0.70,4);

    printf("\nTESTING: TransactionHistory\n");

    printf("\n->Transaction_History_newTransactionHistory");
    TransactionHistory* history = createTransactionHistory(1,1);
    printTransactionHistory(history);

    printf("\n->Transaction_History_addTransaction (3 Times)");
    addBill(history,myBill1);
    addBill(history,myBill2);
    addBill(history,myBill3);


    printf("\n->Transaction_History_getUnpaidBills ");
    printf("Unpaid bills %d",getUnpaidBillsCount(history));


    pay(myBill1,2,40,30,30);

    printf("\n->Transaction_History_getUnpaidBills ");
    printf("Unpaid bills %d",getUnpaidBillsCount(history));


    return (EXIT_SUCCESS);
}
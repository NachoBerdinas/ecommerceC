#include "Bill.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

Bill *createBill(double amount, char *date, double tax, int billID,ShoppingCart* cart) {
    Bill* bill = malloc(sizeof(Bill));
    bill->billID = billID;
    bill->tax = tax;
    bill->amount = amount;
    bill->date = strdup(date);
    bill->paymentID = -1;
    bill->shipping = NULL;
    bill->shoppingCart = cart;
    return bill;
}

Bill *createShippingBill(double amount, char *date, double tax, Shipping *shipping, int billID,ShoppingCart* cart) {
    Bill* bill = createBill(amount, date, tax, billID,cart);
    bill->shipping = malloc(sizeof(Shipping));
    bill->shipping = shipping;
    return bill;
}

int hasShipping(Bill *bill) {
    if(bill->shipping == NULL){
        return 0;
    }else{
        return 1;
    }
}

int isBillPayed(Bill *bill) {
    if(bill->paymentID == -1){
        return 0;
    }else{
        return 1;
    }
}

void printBill(Bill *bill) {
    printf("Bill ID: %d\n", bill->billID);
    printf("Amount: %lf\n", bill->amount);
    printf("Tax: %lf\n", bill->tax);
    printf("Date: %s\n", bill->date);
    if(hasShipping(bill) > 0){
        printShipping(bill->shipping);
    }
    if(isBillPayed(bill) > 0){
        printf("Payment ID: %d", bill->paymentID);
    }
}

void destroyBill(Bill *bill) {
    free(bill->date);
    if (hasShipping(bill) > 0){
        destroyShipping(bill->shipping);
    }
    free(bill);
}

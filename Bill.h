#ifndef ECOMERCE_BILL_H
#define ECOMERCE_BILL_H

#include "Shipping.h"
#include "ShoppingCart.h"

typedef struct Bill{
    int billID;
    double amount;
    double tax;
    char* date;
    int paymentID;
    Shipping* shipping;
    ShoppingCart* shoppingCart;
} Bill;

Bill *createBill(double amount, char *date, double tax, int billID,ShoppingCart* cart);
Bill* createShippingBill(double amount, char* date, double tax, Shipping* shipping, int billID,ShoppingCart* cart);
int hasShipping(Bill* bill);
int isBillPayed(Bill* bill);
void printBill(Bill* bill);
void destroyBill(Bill* bill);

#endif //ECOMERCE_BILL_H

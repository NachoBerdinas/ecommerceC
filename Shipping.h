//
// Created by Tomi on 12/05/2016.
//

#ifndef ECOMERCE_SHIPPING_H
#define ECOMERCE_SHIPPING_H

typedef struct Shipping{
    int shippingID;
    char* businessName;
    double shippingCost;
    char* adress;
    double taxPercentage;
    char* shippingState;
} Shipping;

Shipping* createShipping(double shippingCost, char* businessName, double taxPercentage, char* adress, int shippingID);
void printShipping(Shipping* shipping);
void destroyShipping(Shipping* shipping);

#endif //ECOMERCE_SHIPPING_H

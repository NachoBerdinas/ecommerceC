

#include "Shipping.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Shipping* createShipping(double shippingCost, char* businessName, double taxPercentage, char* adress, int shippingID) {
    Shipping* shipping;
    shipping = malloc(sizeof(Shipping));
    shipping->shippingID = shippingID;
    shipping->shippingCost = shippingCost;
    shipping->businessName = businessName;
    shipping->adress = adress;
    shipping->shippingState = "Shipping proccesing";
    shipping->taxPercentage = taxPercentage;
    return shipping;
}

void printShipping(Shipping* shipping) {
    printf("Shipping ID: %d\n", shipping->shippingID);
    printf("Cost: %lf\n", shipping->shippingCost);
    printf("Tax Percentage: %lf\n", shipping->taxPercentage);
    printf("Business: %s\n", shipping->businessName);
    printf("Address: %s\n", shipping->adress);
}

void destroyShipping(Shipping* shipping) {
    free(shipping->businessName);
    free(shipping->adress);
    free(shipping);
}


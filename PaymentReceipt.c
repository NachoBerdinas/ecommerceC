
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "PaymentReceipt.h"

PaymentReceipt* createPaymentReceipt(Product** products, int ID,  char* date,int productCount){
    PaymentReceipt* paymentReceipt = malloc(sizeof(PaymentReceipt));
    if(paymentReceipt){
        paymentReceipt->products = malloc(productCount*2* sizeof(Product*));
        paymentReceipt->productMax = productCount*2;
        paymentReceipt->productCount = productCount;
        paymentReceipt->price = 0;

        for(int i=0;i<paymentReceipt->productCount;i++){
            paymentReceipt-> price += products[i]->price;
            paymentReceipt->products[i] = products[i];
        }

        paymentReceipt->ID = ID;

        paymentReceipt->date = strdup(date);
    }
    return paymentReceipt;
}

void destroyPaymentReceipt(PaymentReceipt *paymentReceipt){
    free(paymentReceipt);
}

void addProduct(Product* product, PaymentReceipt* paymentReceipt){
    if(paymentReceipt->productCount== paymentReceipt->productMax){
        paymentReceipt->productMax *= 2;
        paymentReceipt->products = realloc(paymentReceipt->products,paymentReceipt->productMax* sizeof(Product*));
    }
    paymentReceipt->products[paymentReceipt->productCount] = product;
    paymentReceipt->price += product->price;
}

double getAmount(PaymentReceipt *paymentReceipt){
    return paymentReceipt->price;
}

int getPaymentReceiptID(PaymentReceipt *paymentReceipt){
    return paymentReceipt->ID;
}

void printPaymentReceipt(PaymentReceipt* receipt){
    printf("\n\tReceipt: %d",receipt->ID);
    for(int i=0;i<receipt->productCount;i++){
        printProduct(receipt->products[i]);
    }
}

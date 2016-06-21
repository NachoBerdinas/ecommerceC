
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "PaymentReceipt.h"

PaymentReceipt* createPaymentReceipt(int id,  char* date){
    PaymentReceipt* paymentReceipt = malloc(sizeof(PaymentReceipt));
    if(paymentReceipt){
        paymentReceipt->products = malloc(10* sizeof(Product*));
        paymentReceipt->productMax = 10;
        paymentReceipt->productCount = 0;
        paymentReceipt->price = 0;
        paymentReceipt->id = id;
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
    paymentReceipt->productCount++;
}

double getAmount(PaymentReceipt *paymentReceipt){
    return paymentReceipt->price;
}

int getPaymentReceiptID(PaymentReceipt *paymentReceipt){
    return paymentReceipt->id;
}

void printPaymentReceipt(PaymentReceipt* receipt){
    printf("\n\tReceipt: %d",receipt->id);
    for(int i=0;i<receipt->productCount;i++){
        printProduct(receipt->products[i]);
    }
}

#ifndef AYED_PAYMENTRECEIPT_H
#define AYED_PAYMENTRECEIPT_H

#include "Product.h"

typedef struct PaymentReceipt{
    Product** products;
    int productCount;
    int productMax;
    int id;
    double price;
    char* date;
} PaymentReceipt;

PaymentReceipt* createPaymentReceipt(int id,  char* date);
void destroyPaymentReceipt(PaymentReceipt *paymentReceipt);
void addProduct(Product *product, PaymentReceipt *paymentReceipt);
double getAmount(PaymentReceipt *paymentReceipt);
int getPaymentReceiptID(PaymentReceipt *paymentReceipt);
void printPaymentReceipt(PaymentReceipt* receipt);

#endif //AYED_PAYMENTRECEIPT_H

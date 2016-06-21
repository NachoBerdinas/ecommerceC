
#include <printf.h>
#include <stdlib.h>
#include "../Product.h"
#include "../PaymentReceipt.h"


int main(int argc, char** argv) {

    Product*  myProduct1 = createProduct(20001, "Nexus 6P", 5000, 300, "Smartphone", 450, 100);
    Product*  myProduct2 = createProduct(20002, "Xiaomi Mi 4", 3700, 350, "Smartphone", 374, 120);
    Product*  myProduct3 = createProduct(20003, "iPad Pro", 6540, 500, "Tablet", 786, 322);
    Product*  myProduct4 = createProduct(20004, "iPad", 6540, 500, "Tablet", 786, 322);;

    Product** products = malloc(sizeof(Product*)*4);
    products[0] = myProduct1;
    products[1] = myProduct2;
    products[2] = myProduct3;


    printf("\nTESTING: PaymentReceipt\n");

    printf("\n->createPaymentReceipt");
    PaymentReceipt* myReceipt = createPaymentReceipt(products,1,"15/06/2016",3);
    printPaymentReceipt(myReceipt);

    printf("\n->addProduct");
    addProduct(myProduct4,myReceipt);
    printPaymentReceipt(myReceipt);




    return (EXIT_SUCCESS);
}

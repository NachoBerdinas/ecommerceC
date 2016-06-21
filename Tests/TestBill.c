
#include <stdio.h>
#include <stdlib.h>
#include "../Bill.h"
#include "../Payment.h"

int main(int argc, char** argv) {

    Shipping* myShipping = createShipping(100,"Cargas SA",0.15,"Florida 9600",1);


    printf("\nTESTING: Bill\n");

    printf("\n->Bill_newBill (without Shipping)");
    Bill* myBill1 = createBill(100,"15/5/1995",0.20,1);
    printBill(myBill1);

    printf("\n->Bill_newBill (with Shipping)");
    Bill* myBill2 = createShippingBill(500,"15/6/1997",0.50,myShipping,2);
    printBill(myBill2);

    printf("\n->Bill_hasShipping: Bill 1 %d", hasShipping(myBill1));
    printf("\n->Bill_hasShipping: Bill 2 %d", hasShipping(myBill2));

    printf("\n\n->Bill_isBillPayed: Bill 1 %d",isBillPayed(myBill1));
    printf("\n->Bill paying with wrong price... %d",isBillPayed(myBill1));
    printf("\nThe total price you have to pay is %lf",myBill1->amount);
    Payment* payment = pay(myBill1,1,30,30,30);
    printf("\n->Bill_isBillPayed: Bill %d",isBillPayed(myBill1));

    printf("\n\n->Bill paying with right price... %d",isBillPayed(myBill1));
    printf("\nThe total price you have to pay is %lf ",myBill1->amount);
    Payment* payment2 = pay(myBill1,2,40,30,30);
    printf("\n->Bill_isBillPayed: Bill 1 %d \n\n\n",isBillPayed(myBill1));






    return (EXIT_SUCCESS);
}
//
// Created by Nikla on 5/23/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "../ShoppingCart.h"

int main(int argc, char** argv) {

    Product*  myProduct1 = createProduct(20001, "Nexus 6P", 5000, 300, "Smartphone", 450, 100);
    Product*  myProduct2 = createProduct(20002, "Xiaomi Mi 4", 3700, 350, "Smartphone", 374, 120);
    Product*  myProduct3 = createProduct(20003, "iPad Pro", 6540, 500, "Tablet", 786, 322);
    Product*  myProduct4 = createProduct(20004, "iPad", 6540, 500, "Tablet", 786, 322);

    printf("\nTESTING: ShoppingCart\n");

    printf("\n->createShoppingCart");
    ShoppingCart* myShoppingCart = createShoppingCart(30010, 40100);
    printf("\n\tshoppingCart->cartID: %d; shoppingCart->userID: %d", myShoppingCart->cartID, myShoppingCart->userID);

    printf("\n\n->shoppingCartIsEmpty: %d", shoppingCartIsEmpty(myShoppingCart));

    printf("\n\n->addProductToCart 3 times");
    addProductToCart(myShoppingCart, myProduct1);
    addProductToCart(myShoppingCart, myProduct2);
    addProductToCart(myShoppingCart, myProduct3);

    int productCount = myShoppingCart->productCount;
    printf("\n\n->getNumberOfProducts: %d", productCount);

    printf("\n\n->printCart");
    printShoppingCart(myShoppingCart);

    printf("\n\n->getTotalCost: %f", myShoppingCart->total);
    printf("\n\n->shoppingCartIsEmpty: %d", shoppingCartIsEmpty(myShoppingCart));

    printf("\n\n->removeProductFromCart 'un-added product': %d", removeProductFromCart(myShoppingCart, myProduct4));
    printf("\n\n->removeProductFromCart Xiaomi Mi 4: %d", removeProductFromCart(myShoppingCart, myProduct1));

    printf("\n\n->printCart");
    printShoppingCart(myShoppingCart);

    printf("\n\n->emptyShoppingCart");
    emptyShoppingCart(myShoppingCart);
    printf("\n\n->shoppingCartIsEmpty: %d", shoppingCartIsEmpty(myShoppingCart));

    printf("\n\n->addProductToCart 2 times");
    addProductToCart(myShoppingCart, myProduct4);
    addProductToCart(myShoppingCart, myProduct3);

    printf("\n\n->shoppingCartIsEmpty: %d", shoppingCartIsEmpty(myShoppingCart));
    printf("\n\n->getNumberOfProducts: %d", myShoppingCart->productCount);

    printf("\n\n->printCart");
    printShoppingCart(myShoppingCart);

    printf("\n\n->destroyShoppingCart");
    destroyShoppingCart(&myShoppingCart);
    printf("\n%p", myShoppingCart);

    return (EXIT_SUCCESS);
}

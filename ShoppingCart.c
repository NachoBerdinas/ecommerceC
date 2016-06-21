#include <stdio.h>
#include <stdlib.h>
#include "ShoppingCart.h"

ShoppingCart * createShoppingCart(int cartID, int userID) {
    ShoppingCart * newCart;
    newCart = malloc(sizeof(ShoppingCart));
    newCart->cartID = cartID;
    newCart->userID = userID;
    newCart->capacity = 10;
    newCart->productCount = 0;
    newCart->total = 0;
    newCart->cart = malloc(sizeof(Product*) * newCart->capacity);
    return newCart;
}

void addProductToCart(ShoppingCart *myShoppingCart, Product *p) {
    if (p != NULL){
        int capacity = myShoppingCart->capacity;
        if (myShoppingCart->productCount == capacity) {
            myShoppingCart->capacity *= 2;
            myShoppingCart->cart = realloc(myShoppingCart->cart, sizeof(Product) * (myShoppingCart->capacity));
        }

        myShoppingCart->cart[myShoppingCart->productCount] = p;
        myShoppingCart->total += p->price;
        ++myShoppingCart->productCount;
    }
}

// Returns 1 if deleted, 0 if it was not found
int removeProductFromCart(ShoppingCart *myShoppingCart, Product *p) {
    if(p!=NULL) {
        for (int i = 0; i < myShoppingCart->productCount; i++) {
            if (myShoppingCart->cart[i]->ID == p->ID) {
                myShoppingCart->total -= myShoppingCart->cart[i]->price;
                myShoppingCart->cart[i] = myShoppingCart->cart[myShoppingCart->productCount - 1];
                --myShoppingCart->productCount;
                return 1;
            }
        }
    }
    return 0;
}

void emptyShoppingCart(ShoppingCart *myShoppingCart) {
    myShoppingCart->productCount = 0;
}

int shoppingCartIsEmpty(ShoppingCart *myShoppingCart){
    if (myShoppingCart->productCount == 0) return 1;
    else return 0;
}

void printShoppingCart(ShoppingCart *myShoppingCart) {
    for (int i = 0; i < myShoppingCart->productCount; i++) {
        printf("\n%s", myShoppingCart->cart[i]->name);
    }
}

void destroyShoppingCart(ShoppingCart **myShoppingCart) {
    free(((*myShoppingCart)->cart));
    (*myShoppingCart)->cart = NULL;
    free(*myShoppingCart);
    *myShoppingCart = NULL;
}

ShoppingCart* cloneCart(ShoppingCart* cart){
    ShoppingCart * newCart;
    newCart = malloc(sizeof(ShoppingCart));
    newCart->cartID = cart->cartID;
    newCart->userID = cart->userID;
    newCart->capacity = cart->capacity;
    newCart->productCount = cart->productCount;
    newCart->total = cart->total;
    newCart->cart = malloc(sizeof(Product*) * newCart->capacity);

    for(int i = 0; i<cart->productCount;i++){
        newCart->cart[i] = cart->cart[i];
    }
    return newCart;
}

#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include "Product.h"

typedef struct ShoppingCart{
    int cartID;
    int userID;
    int capacity;
    int productCount;
    float total;
    Product **cart;
} ShoppingCart;

ShoppingCart * createShoppingCart(int cartID, int userID);
void addProductToCart(ShoppingCart *myShoppingCart, Product *p);
int removeProductFromCart(ShoppingCart *myShoppingCart, Product *p);
void emptyShoppingCart(ShoppingCart *myShoppingCart);
int shoppingCartIsEmpty(ShoppingCart *myShoppingCart);
void printShoppingCart(ShoppingCart *myShoppingCart);
void destroyShoppingCart(ShoppingCart **myShoppingCart);
ShoppingCart* cloneCart(ShoppingCart* cart);

#endif

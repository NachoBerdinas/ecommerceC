//
// Created by Tomi on 12/05/2016.
//

#include "User.h"
#include "ShoppingCart.h"
#include <stdlib.h>
#include <stdio.h>


User *createUser(Person *person, ShoppingCart* shoppingCart, int userID) {
    User* user;
    user = malloc(sizeof(user));
    user->person = person;
    user->shoppingCart = shoppingCart;
    user->id = userID;
    user->transactions = malloc(sizeof(TransactionHistory));
    return user;
}


void printUser(User *user) {
    printf("User ID: %d", user->id);
    //printf("Product ID: %d", user->);
    //printf("Cart ID: %d", user->shoppingCart);
}

void destroyUser(User *user) {
    // destroyPerson(user->person);)
    // destroyShoppingCart(user->shoppingCart);
    destroyTransactionHistory(user->transactions);
    free(user);
}

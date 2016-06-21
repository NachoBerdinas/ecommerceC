//
// Created by Tomi on 12/05/2016.
//

#ifndef ECOMERCE_USER_H
#define ECOMERCE_USER_H

#include "TransactionHistory.h"
#include "ShoppingCart.h"
#include "Address.h"

typedef struct Person Person;

typedef struct User{
    Person* person;
    int id;
    ShoppingCart* shoppingCart;
    TransactionHistory* transactions;
} User;

User* createUser(Person* person, ShoppingCart* shoppingCart, int userID);
void printUser(User* user);
void destroyUser(User* user);



#endif //ECOMERCE_USER_H

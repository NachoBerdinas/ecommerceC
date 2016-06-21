#include "User.h"
#include "ShoppingCart.h"
#include <stdlib.h>
#include <stdio.h>


User *createUser(Person *person, ShoppingCart* shoppingCart, int userID) {
    User* user = malloc(sizeof(User));
    user->person = person;
    user->shoppingCart = shoppingCart;
    user->id = userID;
    user->transactions = createTransactionHistory(userID,rand()%200);
    return user;
}


void printUser(User *user) {
    printf("User ID: %d", user->id);
}

void destroyUser(User *user) {
    destroyTransactionHistory(user->transactions);
    free(user);
}

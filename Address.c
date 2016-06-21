#include "Address.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Address* createAddress(int streetNumber, int zipCode, char *country, char *state, char *street, char *userName){
    Address* myAddress = malloc(sizeof(Address));
    if(myAddress != NULL){
        myAddress->streetNumber = streetNumber;
        myAddress->zipCode = zipCode;
        myAddress->country = malloc(sizeof(country));
        myAddress->state = malloc(sizeof(state));
        myAddress->street = malloc(sizeof(street));
        myAddress->userName = malloc(sizeof(userName));
        strcpy(myAddress->country, country);
        strcpy(myAddress->state, state);
        strcpy(myAddress->street, street);
        strcpy(myAddress->userName, userName);
    }
    return myAddress;
}


void destroyAddress(Address *myAddress){
    free(myAddress ->country);
    free(myAddress ->state);
    free(myAddress ->street);
    free(myAddress ->userName);
    free(myAddress);
}

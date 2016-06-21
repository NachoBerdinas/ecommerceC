//
// Created by Ignacio Berdiñas on 6/19/16.
//

#include <stdlib.h>
#include <memory.h>
#include <printf.h>
#include "Contract.h"

Contract* createContract(int id, char* description,int amount, int quantityOfProducts, char* creationDate){
    Contract* aux = malloc(sizeof(Contract));
    aux->id = id;
    aux->description = strdup(description);
    aux->creationDate = strdup(creationDate);
    aux->quantityOfProducts = quantityOfProducts;
    aux->amount = amount;
    return aux;
}

void printContract(Contract* contract){
    printf("Contract ID: %d for %d products at %d price",contract->id,contract->quantityOfProducts,contract->amount);
}

void destroyContract(Contract* contract){
    free(contract->creationDate);
    free(contract->description);
    free(contract);
}
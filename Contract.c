#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "Contract.h"

Contract* createContract(int id, char* description,int amount,  char* creationDate){
    Contract* aux = malloc(sizeof(Contract));
    aux->id = id;
    aux->description = strdup(description);
    aux->creationDate = strdup(creationDate);
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
//
// Created by Ignacio Berdiñas on 6/19/16.
//

#ifndef IMPLEMENTACIONES_CONTRACT_H
#define IMPLEMENTACIONES_CONTRACT_H


typedef struct Contract{
    int id;
    char* description;
    int quantityOfProducts;
    char* creationDate;
    int amount;
}Contract;

Contract* createContract(int id, char* description,int amount, int quantityOfProducts, char* creationDate);
void destroyContract(Contract* contract);
void printContract(Contract* contract);
#endif //IMPLEMENTACIONES_CONTRACT_H

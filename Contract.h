#ifndef IMPLEMENTACIONES_CONTRACT_H
#define IMPLEMENTACIONES_CONTRACT_H


typedef struct Contract{
    int id;
    char* description;
    int quantityOfProducts;
    char* creationDate;
    int amount;
}Contract;

Contract* createContract(int id, char* description,int amount, char* creationDate);
void destroyContract(Contract* contract);
void printContract(Contract* contract);
#endif //IMPLEMENTACIONES_CONTRACT_H

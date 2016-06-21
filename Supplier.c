
#include <stdio.h>
#include <stdlib.h>
#include "Supplier.h"

Supplier* createSupplier(int aSupplierID, Person *aPerson, int aRifNumber) {
    Supplier* supplier = (Supplier*)malloc(sizeof(Supplier));

    if (supplier != NULL) {
        supplier->supplierID = aSupplierID;
        supplier->person = aPerson;
        supplier->history = createSupplierHistory(aSupplierID);
        supplier->rifNumber = aRifNumber;
        supplier->currentProducts = 0;
        supplier->products = (Product **)malloc(10 * sizeof(Product*));
        supplier->maxProducts = 10;
        supplier->currentContracts = 0;
        supplier->maxContracts = 10;
        supplier->contracts = (Contract**)malloc(10* sizeof(Contract*));
    }
    return supplier;
}

int getSupplierID (Supplier* s){
    return s->supplierID;
}
char* getPersonID(Supplier *s){
    return s->person->ID;
}
int getRIF(Supplier *s){
    return s->rifNumber;
}

void destroySupplier(Supplier *s) {
    free(s->products);
    free(s);
}

void addProductToList(Supplier *supplier, Product *s) {
    if(supplier->currentProducts == supplier->maxProducts){
        supplier->maxProducts += supplier->maxProducts;
        supplier->products = realloc(supplier->products, sizeof(Product*)*supplier->maxProducts);
    }

    supplier->products[supplier->currentProducts] = s;
    supplier->currentProducts++;
}


void addContractToList(Supplier *supplier, Contract *c){
    if(supplier->currentContracts == supplier->maxContracts){
        supplier->maxContracts += supplier->maxContracts;
        supplier->contracts = realloc(supplier->contracts, sizeof(Contract*)*supplier->maxContracts);
    }

    supplier->contracts[supplier->currentContracts] = c;
    supplier->currentContracts++;
}


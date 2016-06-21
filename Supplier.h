#include <stdlib.h>
#include "Product.h"
#include "Person.h"
#include "SupplierHistory.h"
#include "Contract.h"

//
// Created by matias on 5/11/16.
//
typedef struct Supplier {
    int supplierID;
    Person* person;
    int rifNumber;
    Product** products;
    SupplierHistory* history;
    Contract** contracts;
    int currentContracts;
    int maxContracts;
    int currentProducts;
    int maxProducts;
} Supplier;

Supplier* createSupplier(int aSupplierID, Person *person, int aRifNumber);
void destroySupplier(Supplier* s);
int getSupplierID(Supplier* s);
char* getPersonID(Supplier* s);
void addContractToList(Supplier *supplier, Contract *c);
void addProductToList(Supplier *supplier, Product *s);
int getRIF(Supplier* s);


#ifndef TPCUATRIMESTRAL_SUPPLIER_H
#define TPCUATRIMESTRAL_SUPPLIER_H

#endif //TPCUATRIMESTRAL_SUPPLIER_H

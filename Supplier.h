#include <stdlib.h>
#include "Product.h"
#include "Person.h"
#include "SupplierHistory.h"
#include "Contract.h"

typedef struct Supplier {
    Person* person;
    Product** products;
    SupplierHistory* history;
    Contract** contracts;
    int supplierID;
    int rifNumber;
    int currentContracts;
    int maxContracts;
    int currentProducts;
    int maxProducts;
} Supplier;

Supplier* createSupplier(int id, Person *person, int aRifNumber);
void destroySupplier(Supplier* s);
int getSupplierID(Supplier* s);
char* getPersonID(Supplier* s);
void addContractToList(Supplier *supplier, Contract *c);
void addProductToList(Supplier *supplier, Product *s);
int getRIF(Supplier* s);


#ifndef TPCUATRIMESTRAL_SUPPLIER_H
#define TPCUATRIMESTRAL_SUPPLIER_H

#endif //TPCUATRIMESTRAL_SUPPLIER_H

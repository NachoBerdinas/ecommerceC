#ifndef PRODUCT_H
#define PRODUCT_H

typedef struct Supplier Supplier;


typedef struct Product{
    int ID;
    char *name;
    int initialQuantity;
    int actualQuantity;
    int weight;
    char *description;
    int price;
    int size;
    Supplier* supplier;
} Product;

Product* createProduct(Supplier* supplier,int ID, char *name, int initialQuantity, int weight, char *description, int price, int size);
void destroyProduct(Product *product);
void addStock(int quantityToAdd, Product *product);
void buy(int amountToBuy, Product *product);
void printProduct(Product* product);

#endif
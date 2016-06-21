#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "Product.h"

Product* createProduct(int ID, char *name, int initialQuantity, int weight, char *description, int price, int size){
    Product* product = malloc(sizeof(Product));
    if(product){
        product->ID = ID;
        product->name = strdup(name);
        product->initialQuantity = initialQuantity;
        product->weight = weight;
        product->description = strdup(description);
        product->price = price;
        product->size = size;
    }
    return product;
}

void destroyProduct(Product* product){
    free(product->name);
    free(product->description);
    free(product);
}

void addStock(int quantityToAdd, Product *product){
    if(quantityToAdd > 0){
        product->actualQuantity += quantityToAdd;
    } else{
        printf("The stock to add must be greater or equal to zero");
    }
}

void buy(int amountToBuy, Product *product){
    if(product->actualQuantity == 0) {
        printf("There is no stock available for this product: %s\n\n", product->name);
    } else if(product->actualQuantity < amountToBuy){
        printf("You can not buy that price of products.\nStock available for %s: %d", product->name, product->actualQuantity);
    }else{
        product->actualQuantity -= amountToBuy;
    }
}

void printProduct(Product* product){
    printf("\n\n Product %s  ID: %d",product->name,product->ID);
}
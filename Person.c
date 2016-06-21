
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"




Person* createPerson(char *name,char *ID, char *username,char* password, char *email, Address* address){
    Person *myPerson = malloc(sizeof(Person));
    if(myPerson != NULL){
        myPerson->name = malloc(sizeof(name));
        myPerson->ID = malloc(sizeof(ID));
        myPerson->username = malloc(sizeof(username));
        myPerson->email = malloc(sizeof(email));

        myPerson->password = strdup(password);
        strcpy(myPerson->name, name);
        strcpy(myPerson->ID, ID);
        strcpy(myPerson->username, username);
        strcpy(myPerson->email, email);
        myPerson->address = address;
    }
    return myPerson;
}


void destroyPerson(Person *person){
    destroyAddress(person->address);
    free(person->name);
    free(person->username);
    free(person->ID);
    free(person->email);
    free(person->phoneNumber);
    free(person);
}


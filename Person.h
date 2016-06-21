#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include "User.h"
#include "Person.h"
#include "Address.h"
#include <stdio.h>
#include <stdlib.h>

//username with only letters or numbers
//password with at least 6 characters
typedef struct Person{
    char *name;
    char *ID;
    char *username;
    char *password;
    char *email;
    char *phoneNumber;
    char *type;
    Address* address;
}Person;

Person* createPerson(char *name,char *ID, char *username,char* password, char *email, char *phoneNumber, char *type, Address* address);
void destroyPerson(Person *person);


#endif // PERSON_H_INCLUDED


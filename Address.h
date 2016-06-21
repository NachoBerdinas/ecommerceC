#ifndef ADDRESS_H_INCLUDED
#define ADDRESS_H_INCLUDED

typedef struct Address{
    int streetNumber;
    int zipCode;
    char *country;
    char *state;
    char *street;
    char *userName;
} Address;

Address* createAddress(int streetNumber, int zipCode, char *country, char *state, char *street, char *userName);
void destroyAddress(Address *myAddress);




#endif // ADDRESS_H_INCLUDED

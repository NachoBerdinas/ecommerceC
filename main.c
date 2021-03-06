#include <stdio.h>
#include <memory.h>
#include <time.h>
#include "Supplier.h"
#include "Payment.h"
#include "TechSupport.h"

typedef struct Data{
    Supplier** suppliers;
    User** users;
    TechSupport* techSupport;
    int numberOfSuppliers;
    int maxSuppliers;
    int numberOfUsers;
    int maxUsers;
}Data;

void login(Data* data);
int authenticate(char* user,char* password,Data* data);
void initData(Data* data);

void userMain(User* user,Data* data);
void supplierMain(Supplier* supplier,Data* data);
void supportMain(PersonTechSupport* personTechSupport, Data* data);

void showMenuUser();
void showMenuSupplier();
void showMenuSupport();

void addUser(Data* data,User* user);
void addSupplier(Data* data, Supplier* supplier);


User* getUser(char* username,Data* data);
Supplier* getSupplier(char* username,Data* data);
PersonTechSupport* getPersonTechSupport(char* username,Data* data);

Product* searchProduct(Data* data,int productId);

void showMenu(){
    printf("\n\n");
    printf("1.Log in\n");
    printf("2.Create person (Create first and then select the type of user)\n");
    printf("3.Create user\n");
    printf("4.Create tech support\n");
    printf("5.Create supplier\n");
}

int main() {
    Data* data = malloc(sizeof(Data));
    initData(data);
    int option;
    char username[50];
    char password[50];
    char id[50];
    char name[50];
    char email[50];
    Person* person;
    do{
        showMenu();
        scanf("%d",&option);
        switch (option){
            case 1:
                login(data);
                break;
            case 2:
                printf("\nCreating a person:\n");
                printf("Enter your username:\n");
                scanf("%s", username);
                printf("Enter your password:\n");
                scanf("%s", password);
                printf("Enter your ID:\n");
                scanf("%s",id);
                printf("Enter your name:\n");
                scanf("%s", name);
                printf("Enter your email:\n");
                scanf("%s", email);
                person = createPerson(name,id,username,password,email,NULL);
                break;
            case 3:
                addUser(data,createUser(person,createShoppingCart(rand()%1000,data->users[data->numberOfUsers-1]->id+1),data->users[data->numberOfUsers-1]->id+1));
                break;
            case 4:
                addSupplier(data,createSupplier(rand()%1000,person,rand()%1000));
                break;
            case 5:
                addPersonTechSupport(createPersonTechSupport(person,rand()%100),data->techSupport);
                break;


        }
    }while(option!=0);
    login(data);

}

void login(Data* data){
    char user[50];
    char password[50];

    do{
        printf("\e[1;1H\e[2J");
        printf("--------------Login--------------\n");
        printf("Enter your username:\n");
        scanf("%s", user);
        printf("Enter your password:\n");
        scanf("%s", password);
        printf("--------------------------------\n\n");

        switch (authenticate(user, password,data)) {
            case 1:
                printf("Logged in as user");
                userMain(getUser(user,data),data);
                break;
            case 2:
                printf("Logged in as supplier");
                supplierMain(getSupplier(user,data),data);
                break;
            case 3:
                printf("Logged in as support technician");
                supportMain(getPersonTechSupport(user,data),data);
                break;
            default:
                printf("\nIncorrect user or password, please try again\n");
        }
    }while (strcmp(user,"exit")!=0);
}

void createReceipts(int aux, const char *currentDate, const Bill *auxBill, const ShoppingCart *shoppingCartAux) {
    for(int j = 0; j < shoppingCartAux->productCount; j++){
        aux = shoppingCartAux->cart[j]->supplier->history->currentReceipts;
        if(aux==0){
            addReceipt(createPaymentReceipt(shoppingCartAux->cartID,strdup(currentDate)),shoppingCartAux->cart[j]->supplier->history);
            aux = shoppingCartAux->cart[j]->supplier->history->currentReceipts;
            addProduct(shoppingCartAux->cart[j],shoppingCartAux->cart[j]->supplier->history->receipts[aux-1]);
        }else if(auxBill->shoppingCart->cart[j]->supplier->history->receipts[aux-1]->id == auxBill->shoppingCart->cartID){
            addProduct(shoppingCartAux->cart[j],shoppingCartAux->cart[j]->supplier->history->receipts[aux-1]);
        }else{
            addReceipt(createPaymentReceipt(shoppingCartAux->cartID,strdup(currentDate)),shoppingCartAux->cart[j]->supplier->history);
            aux = shoppingCartAux->cart[j]->supplier->history->currentReceipts;
            addProduct(shoppingCartAux->cart[j],shoppingCartAux->cart[j]->supplier->history->receipts[aux-1]);
        }
    }
}

void userMain(User* user, Data* data){
    int option = 0;
    ShoppingCart* shoppingCart = user->shoppingCart;
    TransactionHistory* transactionHistory = user->transactions;
    int aux = 0,credit = 0,transfer = 0, deposit = 0;

    time_t t = time(NULL);
    struct tm tm;
    char string[200];
    char currentDate[200];
    tm = *localtime(&t);
    sprintf(currentDate,"%d/%d/%d",tm.tm_year+1900,tm.tm_mon + 1, tm.tm_mday);
    do{
        showMenuUser();
        printf("\n\nInsert your choice");
        scanf("%d",&option);
        switch(option){
            case 1:
                for(int i = 0; i<data->numberOfSuppliers;i++){
                    for(int j = 0;j < data->suppliers[i]->currentProducts;j++){
                        printProduct(data->suppliers[i]->products[j]);
                    }
                }
                break;
            case 2:
                aux = 0;
                for(int i = 0; i<shoppingCart->productCount;i++){
                    aux += shoppingCart->cart[i]->price;
                }
                printf("Shopping cart price %d",aux);
                printShoppingCart(shoppingCart);
                break;
            case 3:
                printf("\nEnter the id of the product to add");
                scanf("%d",&option);
                addProductToCart(shoppingCart,searchProduct(data,option));
                break;
            case 4:
                printf("\nEnter the id of the product to remove");
                scanf("%d",&option);
                removeProductFromCart(shoppingCart,searchProduct(data,option));
                break;
            case 5:
                emptyShoppingCart(shoppingCart);
                break;
            case 6:
                aux = 0;
                for(int i = 0; i<shoppingCart->productCount;i++){
                    aux += shoppingCart->cart[i]->price;
                    buy(1,shoppingCart->cart[i]);
                    addContractToList(shoppingCart->cart[i]->supplier,
                                      createContract(rand()%10000,
                                                     strdup(shoppingCart->cart[i]->description),
                                                     shoppingCart->cart[i]->price,
                                                     strdup(currentDate)));
                }
                addBill(transactionHistory,createBill(aux,strdup(currentDate),.21,rand()%1000,cloneCart(shoppingCart)));
                emptyShoppingCart(shoppingCart);
                break;
            case 7:
                printTransactionHistory(transactionHistory);
                break;
            case 8:
                printf("\nEnter the id of the bill to pay\n");
                scanf("%d",&option);
                for(int i = 0; i<transactionHistory->billAmount;i++){
                    if(option == transactionHistory->bills[i]->billID){
                        printf("\nEnter the amount you would like to pay with each way of payment.\n");
                        printf("\nTotal amount to pay is: %lf",transactionHistory->bills[i]->amount);
                        printf("\nEnter amount of credit");
                        scanf("%d",&credit);
                        printf("\nEnter amount of transfer");
                        scanf("%d",&transfer);
                        printf("\nEnter amount of deposit");
                        scanf("%d",&deposit);
                        pay(transactionHistory->bills[i],rand()%1000,credit,transfer,deposit);
                        printf("Insert an address to send the package");
                        scanf("%s",string);
                        transactionHistory->bills[i]->shipping = createShipping(100,"Fedex",0.1,strdup(string),option);

                        Bill* auxBill = transactionHistory->bills[i];
                        ShoppingCart* shoppingCartAux = auxBill->shoppingCart;
                        createReceipts(aux, currentDate, auxBill, shoppingCartAux);
                    }
                }
                break;
            case 9:
                printf("\nEnter the id of the bill to see the shipping\n");
                scanf("%d",&option);
                for(int i = 0; i<transactionHistory->billAmount;i++){
                    if(option == transactionHistory->bills[i]->billID){
                        printShipping(transactionHistory->bills[i]->shipping);
                    }
                }
                break;
            case 10:
                printf("\nEnter your question\n");
                getchar();
                scanf("%[^\n]",string);
                addQuestion(createQuestion(string, rand() % 1000, currentDate, user),data->techSupport);
                break;
            case 11:
                printf("\nMy questions\n");
                for(int i = 0; i<data->techSupport->questionsCurrent;i++){
                    if(data->techSupport->myQuestions[i]->asker->id == user->id){
                        printQuestion(data->techSupport->myQuestions[i]);
                    }
                }
        }

        printf("\n\n\nPress Any Key to Continue\n");
        getchar();
        getchar();
        printf("\e[1;1H\e[2J");
    }while(option!=0);
}

void supplierMain(Supplier* supplier,Data* data){
    printf("\e[1;1H\e[2J");
    int option = 0;
    int stock,price,aux;

    char string[50];
    do{
        showMenuSupplier();
        printf("\n\nInsert your choice");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("\nCreating new product to add");
                printf("\nEnter the name of the product");
                scanf("%s",string);
                printf("\nEnter the starting stock of the product");
                scanf("%d",&stock);
                printf("\nEnter the price of the product");
                scanf("%d",&price);
                addProductToList(supplier, createProduct(supplier,rand() % 100, strdup(string), stock, rand() % 1000, "This is a new product", rand() % 10, rand() % 10));
                break;
            case 2:
                printf("\nShowing contracts....\n");
                for(int i = 0; i<supplier->currentContracts;i++){
                    printContract(supplier->contracts[i]);
                }
                break;
            case 3:
                printf("\nShowing receipts....\n");
                for(int i = 0; i<supplier->history->currentReceipts;i++){
                    printPaymentReceipt(supplier->history->receipts[i]);
                }
                break;
            case 4:
                printf("\nShowing products....\n");
                for(int i = 0; i<supplier->currentProducts;i++){
                    printProduct(supplier->products[i]);
                }
                break;
            case 5:
                printf("\nEnter the id of the product");
                scanf("%d",&aux);
                printf("\nEnter the stock of the product");
                scanf("%d",&stock);
                addStock(stock,searchProduct(data,aux));
                break;
        }

        printf("\n\n\nPress Any Key to Continue\n");
        getchar();
        getchar();
        printf("\e[1;1H\e[2J");
    }while(option!=0);
}


void supportMain(PersonTechSupport* personTechSupport, Data* data){
    printf("\e[1;1H\e[2J");
    int option = 0;

    char string[200];
    do{
        showMenuSupport();
        printf("\n\nInsert your choice");
        scanf("%d",&option);
        switch(option){
            case 1:
                for(int i= 0; i<data->techSupport->questionsCurrent;i++){
                    printQuestion(data->techSupport->myQuestions[i]);
                }
                break;
            case 2:
                printf("\nInsert id of question tu answer....\n");
                scanf("%d",&option);
                printf("\nInsert response to question....\n");
                fseek(stdin,0,SEEK_END);
                scanf("%[^\n]",string);
                giveAnswer(data->techSupport,personTechSupport,option,string);
                break;
        }

        printf("\n\n\nPress Any Key to Continue\n");
        getchar();
        getchar();
        printf("\e[1;1H\e[2J");
    }while(option!=0);
}

Product* searchProduct(Data* data,int productId){
    for(int i = 0; i<data->numberOfSuppliers;i++){
        for(int j = 0;j < data->suppliers[i]->currentProducts;j++){
            if(data->suppliers[i]->products[j]->ID == productId){
                return data->suppliers[i]->products[j];
            }
        }
    }
    return NULL;
}

void showMenuUser() {
    printf("\n\n");
    printf("0.Log out\n");
    printf("1.Show list of products\n");
    printf("2.Show shopping cart\n");
    printf("3.Add product to shopping cart\n");
    printf("4.Remove product from shopping cart\n");
    printf("5.Empty Shopping cart\n");
    printf("6.Buy shopping cart\n");
    printf("7.Show bills and history\n");
    printf("8.Pay bill\n");
    printf("9.Show status of shipping\n");
    printf("10.Leave question to tech support\n");
    printf("11.Show my questions\n");
}

void showMenuSupplier() {
    printf("\n\n");
    printf("0.Log out\n");
    printf("1.Add new product\n");
    printf("2.View contracts\n");
    printf("3.View payment receipt\n");
    printf("4.View my products\n");
    printf("5.Add stock to product\n");
}

void showMenuSupport() {
    printf("\n\n");
    printf("0.Log out\n");
    printf("1.View Questions\n");
    printf("2.Answer question\n");
}



int authenticate(char* user,char* password,Data* data){
    for(int i = 0;i<data->numberOfUsers;i++){
        if(strcmp(data->users[i]->person->username,user) ==0 && strcmp(data->users[i]->person->password,password)==0){
            return 1;
        }
    }

    for(int i = 0;i<data->numberOfSuppliers;i++){
        if((strcmp(data->suppliers[i]->person->username,user)==0) && (strcmp(data->suppliers[i]->person->password,password)==0)){
            return 2;
        }
    }

    for(int i = 0;i<data->techSupport->personsCurrent;i++){
        if(strcmp(data->techSupport->myPersonTechSupp[i]->person->username,user) ==0 && strcmp(data->techSupport->myPersonTechSupp[i]->person->password,password)==0){
            return 3;
        }
    }

    return -1;
}

User* getUser(char* username,Data* data){
    for(int i = 0;i<data->numberOfUsers;i++){
        if(strcmp(data->users[i]->person->username,username) ==0 ){
            return data->users[i];
        }
    }
    return NULL;
}

Supplier* getSupplier(char* username,Data* data){
    for(int i = 0;i<data->numberOfSuppliers;i++){
        if(strcmp(data->suppliers[i]->person->username,username) ==0){
            return data->suppliers[i];
        }
    }
    return NULL;
}

PersonTechSupport* getPersonTechSupport(char* username,Data* data){
    for(int i = 0;i<data->techSupport->personsCurrent;i++){
        if(strcmp(data->techSupport->myPersonTechSupp[i]->person->username,username) ==0){
            return data->techSupport->myPersonTechSupp[i];
        }
    }
    return NULL;
}

void addUser(Data* data,User* user){
    if(data->numberOfUsers == data->maxUsers){
        data->maxUsers += data->maxUsers;
        data->users = realloc(data->users, sizeof(User*)*data->maxUsers);
    }

    data->users[data->numberOfUsers] = user;
    data->numberOfUsers++;
}

void addSupplier(Data* data, Supplier* supplier){
    if(data->numberOfSuppliers == data->maxSuppliers){
        data->maxSuppliers += data->maxSuppliers;
        data->suppliers = realloc(data->suppliers, sizeof(Supplier*)*data->maxSuppliers);
    }

    data->suppliers[data->numberOfSuppliers] = supplier;
    data->numberOfSuppliers++;
}

void initData(Data* data){
    data->techSupport = createTechSupport();
    data->numberOfSuppliers = 0;
    data->numberOfUsers = 0;
    data->maxUsers = 5;
    data->maxSuppliers = 5;
    data->suppliers = malloc(sizeof(Supplier*)*data->maxSuppliers);
    data->users = malloc(sizeof(User*)* data->maxUsers);

    Person* p1 = createPerson("Ignacio","39654315","nacho","asdasd1","nacho@n.com",NULL);
    Person* p2 = createPerson("Matias","33453455","mati","asdasd2","mati@n.com",NULL);
    Person* p3 = createPerson("Patricio","32323244","pato","asdasd3","pato@n.com",NULL);
    Person* p4 = createPerson("Bruno","3934234","bruno","asdasd4","bruno@n.com",NULL);
    Person* p5 = createPerson("Tomas","33434315","tomas","asdasd5","bruno@n.com",NULL);

    Supplier* supplier = createSupplier(1,p1,1);
    Supplier* supplier1 = createSupplier(2,p2,2);
    User* user1 = createUser(p3,createShoppingCart(rand()%1000,10),10);
    User* user2 = createUser(p4,createShoppingCart(rand()%1000,15),15);
    PersonTechSupport* support = createPersonTechSupport(p5,3);

    addUser(data,user1);
    addUser(data,user2);

    Product*  myProduct1 = createProduct(supplier,20001, "Nexus 6P", 5000, 300, "Smartphone", 450, 100);
    Product*  myProduct2 = createProduct(supplier,20002, "Xiaomi Mi 4", 3700, 350, "Smartphone", 374, 120);
    Product*  myProduct3 = createProduct(supplier1,20003, "iPad Pro", 6540, 500, "Tablet", 786, 322);
    Product*  myProduct4 = createProduct(supplier1,20004, "iPad", 6540, 500, "Tablet", 786, 322);

    addProductToList(supplier, myProduct1);
    addProductToList(supplier, myProduct2);
    addProductToList(supplier1, myProduct3);
    addProductToList(supplier1, myProduct4);

    addSupplier(data,supplier);
    addSupplier(data,supplier1);
    addPersonTechSupport(support,data->techSupport);

}
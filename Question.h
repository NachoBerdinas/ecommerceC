#ifndef TRABAJO_CUATRIMESTRAL_QUESTION_H
#define TRABAJO_CUATRIMESTRAL_QUESTION_H

#include "User.h"
#include "Product.h"

typedef struct {

    char* questionContent;
    User* asker;
    Product* topic;
    char* creationDate;
    char* answer;
    int questionID;
    int IDOfResponder;

}Question;

Question* createQuestion(char *questionContent, int questionID, char *date, User *myUser);
void printQuestion(Question* question);
void destroyQuestion(Question* question);

#endif //TRABAJO_CUATRIMESTRAL_QUESTION_H

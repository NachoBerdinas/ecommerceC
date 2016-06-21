//
// Created by Tomas Piaggio on 6/16/16.
//


#include <stdlib.h>
#include <memory.h>
#include <printf.h>
#include "Question.h"


Question* createQuestion(char *questionContent, int questionID, char *creationDate, User *myUser, Product *myProduct){
    Question* myQuestion = malloc(sizeof(Question));
    myQuestion->questionContent = strdup(questionContent);
    myQuestion->questionID = questionID;
    myQuestion->creationDate = strdup(creationDate);
    myQuestion->asker = myUser;
    myQuestion->topic = myProduct;

    return myQuestion;
}

/*
 * Returns a question with a null product (for non topic related subjects)
 */
Question* createQuestionNoTopic(char *questionContent, int questionID, char *creationDate, User *myUser){
    Question* myQuestion = malloc(sizeof(Question));
    myQuestion->questionContent = strdup(questionContent);
    myQuestion->questionID = questionID;
    myQuestion->creationDate = strdup(creationDate);
    myQuestion->asker = myUser;
    myQuestion->topic = NULL;

    return myQuestion;
}

void printQuestion(Question* question){
    printf("Question ID: %d", question->questionID);
    printf("Question Content: %s", question->questionContent);
}

void destroyQuestion(Question* question){
    free(question->questionContent);
    free(question);
}

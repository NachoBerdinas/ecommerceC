#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "Question.h"


Question* createQuestion(char *questionContent, int questionID, char *creationDate, User *myUser, Product *myProduct){
    Question* myQuestion = malloc(sizeof(Question));
    myQuestion->questionContent = strdup(questionContent);
    myQuestion->questionID = questionID;
    myQuestion->creationDate = strdup(creationDate);
    myQuestion->asker = myUser;
    myQuestion->topic = myProduct;
    myQuestion->answer = NULL;

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
    myQuestion->answer = NULL;

    return myQuestion;
}

void printQuestion(Question* question){
    printf("\nQuestion ID: %d", question->questionID);
    printf("\nQuestion Content: %s", question->questionContent);
    if(question->answer!=NULL){
        printf("\nQuestion Answer: %s", question->answer);
    }

}

void destroyQuestion(Question* question){
    free(question->questionContent);
    free(question);
}

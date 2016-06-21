
#include <stdlib.h>
#include "TechSupport.h"
#include "PersonTechSupport.h"

TechSupport* createTechSupport(){
    TechSupport* myTechSupp = malloc(sizeof(TechSupport));
    myTechSupp->personsCurrent = 0;
    myTechSupp->questionsCurrent = 0;
    myTechSupp->questionsMax = 10;
    myTechSupp->myQuestions = malloc(myTechSupp->questionsMax * sizeof(Question*));
    myTechSupp->personsMax = 10;
    myTechSupp->myPersonTechSupp = malloc(myTechSupp->personsMax * sizeof(Question*));
    return myTechSupp;
}

PersonTechSupport* searchPerTechSupp(TechSupport* myTechSupp, int perTechSuppID){
    for(int i = 0; i< myTechSupp->personsCurrent;i++){
        if(myTechSupp->myPersonTechSupp[i]->ID == perTechSuppID){
            return myTechSupp->myPersonTechSupp[i];
        }
    }
    return NULL;
}

Question* searchQuestion(TechSupport* myTechSupp, int questionID){
    for(int i = 0; i< myTechSupp->questionsCurrent;i++){
        if(myTechSupp->myQuestions[i]->questionID == questionID){
            return myTechSupp->myQuestions[i];
        }
    }
    return NULL;
}

void addQuestion(Question* myQuestion, TechSupport* myTechSupp){ //Adds another available product to the Supplier's list
    if(myTechSupp->questionsCurrent == myTechSupp->questionsMax){
        myTechSupp->questionsMax += myTechSupp->questionsMax;
        myTechSupp->myQuestions = realloc(myTechSupp->myQuestions, sizeof(Question*)*myTechSupp->questionsMax);
    }

    myTechSupp->myQuestions[myTechSupp->questionsCurrent] = myQuestion;
    myTechSupp->questionsCurrent++;
}

void addPersonTechSupport(PersonTechSupport* personTechSupport, TechSupport* myTechSupp){ //Adds another available product to the Supplier's list
    if(myTechSupp->personsCurrent == myTechSupp->personsMax){
        myTechSupp->personsMax += myTechSupp->personsMax;
        myTechSupp->myPersonTechSupp = realloc(myTechSupp->myPersonTechSupp, sizeof(PersonTechSupport*)*myTechSupp->personsMax);
    }

    myTechSupp->myPersonTechSupp[myTechSupp->personsCurrent] = personTechSupport;
    myTechSupp->personsCurrent++;
}

void giveAnswer(TechSupport* myTechSupp, PersonTechSupport* myPerTechSupp, int questionID, char* response){
    Question* myQuestion = searchQuestion(myTechSupp, questionID);
    answer(myPerTechSupp, myQuestion, response);
}

void destroyTechSupp(TechSupport* myTechSupp){
    int i;
    for(i = 0; i < myTechSupp->personsCurrent; i++){
        destroyPersTechSupp(myTechSupp->myPersonTechSupp[i]);
    }
    for(i = 0; i < myTechSupp->questionsCurrent; i++){
        destroyQuestion(myTechSupp->myQuestions[i]);
    }
    free(myTechSupp);

}
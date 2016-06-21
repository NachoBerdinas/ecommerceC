
#include <memory.h>
#include <stdlib.h>
#include "PersonTechSupport.h"
#include "Question.h"

PersonTechSupport* createPersonTechSupport(Person* myPerson, int ID){
    PersonTechSupport* myPerTechSupp = malloc(sizeof(PersonTechSupport));
    myPerTechSupp->person= myPerson;
    myPerTechSupp->ID = ID;
    return myPerTechSupp;
}

void answer(PersonTechSupport* myPerTechSupp, Question* myQuestion, char* answer){
    myQuestion->answer = strdup(answer);
    myQuestion->IDOfResponder = myPerTechSupp->ID;
}

void destroyPersTechSupp(PersonTechSupport* myPerTechSupp){
    free(myPerTechSupp->person);
    free(myPerTechSupp);
}

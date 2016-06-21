#ifndef TRABAJO_CUATRIMESTRAL_PERSONTECHSUPPORT_H
#define TRABAJO_CUATRIMESTRAL_PERSONTECHSUPPORT_H

#include "Question.h"
#include "Person.h"

typedef struct PersonTechSupport{
    Person* person;
    int ID;
}PersonTechSupport;

PersonTechSupport* createPersonTechSupport(Person* myPerson, int ID);
void answer(PersonTechSupport* myPerTechSupp, Question* myQuestion, char* answer);
void destroyPersTechSupp(PersonTechSupport* myPerTechSupp);

#endif //TRABAJO_CUATRIMESTRAL_PERSONTECHSUPPORT_H

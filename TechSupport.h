//
// Created by Tomas Piaggio on 5/26/16.
//

#ifndef TRABAJO_CUATRIMESTRAL_TECHSUPPORT_H
#define TRABAJO_CUATRIMESTRAL_TECHSUPPORT_H

#include "PersonTechSupport.h"
#include "Question.h"

typedef struct TechSupport{
    Question** myQuestions;
    PersonTechSupport** myPersonTechSupp;
    int personsMax;
    int personsCurrent;
    int questionsMax;
    int questionsCurrent;
}TechSupport;

TechSupport* createTechSupport();

PersonTechSupport* searchPerTechSupp(TechSupport* myTechSupp, int perTechSuppID);
void addQuestion(Question* myQuestion, TechSupport* myTechSupp);
void addPersonTechSupport(PersonTechSupport* personTechSupport, TechSupport* myTechSupp);
void giveAnswer(TechSupport* myTechSupp, PersonTechSupport* myPerTechSupp, int questionID, char* answer);
void destroyTechSupp(TechSupport* myTechSupp);

#endif //TRABAJO_CUATRIMESTRAL_TECHSUPPORT_H

/*
AI.cpp
Contains all code for the AI class.
Declarations are in AI.h
*/

#include "FEHRandom.h"
#include "AI.h"

void AI::setDifficulty(bool diff){
    difficulty = diff;
}

int rand = RandInt();
int easy_move = rand % 7;




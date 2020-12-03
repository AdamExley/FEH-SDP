/*
AI.cpp
Contains all code for the AI class.
Declarations are in AI.h
*/

#include "FEHRandom.h"
#include "AI.h"

int easy_move;

void AI::setDifficulty(bool diff){
    difficulty = diff;
}

int rand = RandInt();
easy_move = rand % 7;




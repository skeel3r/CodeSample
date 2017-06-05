#include "Banana.h"

Banana::Banana(void){

}

Banana::~Banana(void){

}

int Banana::getX(){

    return Banana::xPos;

}

int Banana::getY(){

    return Banana::yPos;

}

void Banana::setX(int x){

    Banana::xPos = x;

}

void Banana::setY(int y){

    Banana::yPos = y;

}

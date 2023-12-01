
#include "Note.h"

Note::Note(){
    
}

Note::Note(std::string m, int x, int y){

    this->posX = x;
    this->posY = y;
    this->message = m;

}

Note::~Note(){
    
}

int Note::GetX(){

	return this->posX;

}

int Note::GetY(){

	return this->posY;

}

void Note::SetX(int x){

	this->posX = x;

}

void Note::SetY(int y){

	this->posY = y;

}

std::string Note::GetMessage(){

    return this->message;

}

void Note::SetMessage(std::string s){

    this->message = s;

}

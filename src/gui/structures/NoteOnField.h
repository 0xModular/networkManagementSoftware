/*
 * NoteOnField.h
 * Created on: Nov 5, 2023
 *
 * Author: Ubljudok
 */

#pragma once
#include <string>

struct Note_ {

	std::string noteContents;

	//postitional info is saved to server. The note object in the backend also has int x and int y. Make sure
	//to update those too so that it gets saved

	//Positional Information
	int posX;
	int posY;

};

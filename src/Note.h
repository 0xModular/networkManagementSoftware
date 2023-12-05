/*
 * Note.cpp
 * Created on Oct 31, 2023
 *
 * Author: Layne
 */

#pragma once
#include <string>

class Note{

    public:
    
    //constructors and deconstructor
    Note();
    Note(std::string m, int x, int y); //USE CreateNewNote in network instead!
    ~Note();

    //getters
    int GetX();
	int GetY();
    std::string GetMessage();

    //setters
	void SetX(int x);
	void SetY(int y);
    void SetMessage(std::string s);


    private:

        //members
        std::string message;
        int posX;
        int posY;



};
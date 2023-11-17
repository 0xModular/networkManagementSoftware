/*
 * client_main.cpp
 * Created on: Nov 7, 2023
 *
 * Author: Layne
 */
#include <string>
#include <iostream>
#include "ThisDevice.h"
#include "ManagerCommunication.h"

int main(){



ThisDevice *d = new ThisDevice();

std::string input;

    while(true){

    	ManagerCommunication::ConnectToManager(d);

    }










}

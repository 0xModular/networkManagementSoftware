#!/bin/bash

g++ -g -I/usr/include/cppconn -o guitest.o *.cpp gui/*.cpp gui/subwindows/*.cpp gui/dialogs/*.cpp -L/usr/local/lib -lmysqlcppconn  `wx-config --cxxflags --libs std,aui`  2> err.log


#!/bin/bash

g++ -g -I/usr/include/cppconn -o test.o *.cpp gui/*.cpp gui/dialogs/*.cpp -I/usr/include/mysql -L/usr/local/lib -lmysqlcppconn  `wx-config --cxxflags --libs std,aui`

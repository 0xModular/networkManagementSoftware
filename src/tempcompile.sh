#!/bin/bash

g++ -g -I/usr/include/cppconn -o guitest.o *.cpp gui/*.cpp gui/dialogs/*.cpp -I/usr/include/mysql -L/usr/local/lib -lmysqlcppconn  `wx-config --cxxflags --libs std,aui`  2> err.log
cat err.log | grep error

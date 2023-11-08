#!/bin/bash

g++ *.cpp gui/*.cpp gui/subwindows/*.cpp gui/dialogs/*.cpp -lmysqlcppconn8 `wx-config --cxxflags --libs std,aui` -o guitest.o 2> err.log

#!/bin/bash

g++ GUI.cpp gui/*.cpp gui/subwindows/*.cpp gui/dialogs/*.cpp `wx-config --cxxflags --libs std,aui` -o guitest.o 

#!/bin/bash

rm test_SFML *.o

g++ -c main.cpp
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

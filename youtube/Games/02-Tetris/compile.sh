#!/bin/bash

app_name=Tetris
rm ${app_name} *.o

g++ -c main.cpp -I/usr/include/SFML -I/usr/include/SFML/Graphics
g++ main.o -o ${app_name} -L/usr/lib/x86_64-linux-gnu/ -lsfml-graphics -lsfml-window -lsfml-system

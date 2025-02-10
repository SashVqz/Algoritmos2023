#!/bin/bash

g++ BacktrakingLaberinto.cpp -o BacktrakingLaberinto

echo "
. . * * * * * * * *
* . . . * * * * * *
* . * . . . . * * *
* . * . * * . * * *
* . * * * * . * * *
* . * * . . . . * *
* . * T . * * * . *
* . * * * . . . . *
* . * * . . . . . *
. . * * * * * * * *
" > mapa1.txt

echo "
. . * * * * * * * *
* . * . . . . . . *
* . * . * * * * . *
* . * . * . . * . *
* . * . * T . * . *
* . * . * * . * . *
* . * . . . . * . *
* . * * * * * * . *
* . . . . . . . . *
* * * * * * * * * *
" > mapa2.txt

echo "
. . * * * * * * * *
* . * . . . . . . *
* . * . * * * * . *
* . * . * . . * . *
* . * . * T . * . *
* . * . * * . * . *
* . * . . . . * . *
* . * * * * * * . *
* . * . . . . . . *
* * * * * * * * * *
" > mapa3.txt

for mapa in mapa1.txt mapa2.txt mapa3.txt

do
  echo "Ejecutando el programa con el mapa $mapa"
  ./BacktrakingLaberinto < $mapa
done
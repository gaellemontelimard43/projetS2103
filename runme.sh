#!/bin/sh

//Création du dossier makefile
mkdir -p build

//deplacemnt dans le git
cd build

cmake ..

make
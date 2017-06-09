#!/bin/sh

cd cspec

make
sudo make install

echo "Cspec instalado"

cd .. 

sudo make all

echo "Tests compilados"

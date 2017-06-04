
#!/bin/sh

cd /../../so-funcion-hash/cspec

make
sudo make install

echo "Cspec instalado"

cd /../../so-funcion-hash/

sudo make all

echo "Tests compilados"

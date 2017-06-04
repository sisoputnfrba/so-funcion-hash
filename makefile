OBJ = ./*.c

all:
	make clean
	gcc -c src/funciones.c -o src/funciones.o
	gcc -c src/so-funcion-hash.c -o src/so-funcion-hash.o
	gcc -o "tests" ./src/funciones.o  ./src/so-funcion-hash.o  -lcommons -lcspecs
	rm -rf src/*.o

clean:
	rm -rf *.o
	rm -rf tests

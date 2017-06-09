OBJ = ./*.c

all:
	make clean
	gcc -c src/funciones.c -o src/funciones.o
	gcc -c src/hash_example.c -o src/hash_example.o
	gcc -o "tests" ./src/funciones.o  ./src/hash_example.o  -lcommons -lcspecs
	rm -rf src/*.o

clean:
	rm -rf *.o
	rm -rf tests

#include "funciones.h"


/* Función Hash */
unsigned int calcularPosicion(int pid, int num_pagina) {
	char str1[20];
	char str2[20];
	sprintf(str1, "%d", pid);
	sprintf(str2, "%d", num_pagina);
	strcat(str1, str2);
	unsigned int indice = atoi(str1) % CANTIDAD_DE_MARCOS;
	return indice;
}

/* Inicialización vector overflow. Cada posición tiene una lista enlazada que guarda números de frames.
 * Se llenará a medida que haya colisiones correspondientes a esa posición del vector. */
void inicializarOverflow(int cantidad_de_marcos) {
	overflow = malloc(sizeof(t_list*) * cantidad_de_marcos);
	int i;
	for (i = 0; i < CANTIDAD_DE_MARCOS; ++i) { /* Una lista por frame */
		overflow[i] = list_create();
	}
}

/* En caso de colisión, busca el siguiente frame en el vector de overflow.
 * Retorna el número de frame donde se encuentra la página. */
int buscarEnOverflow(int indice, int pid, int pagina) {
	int i = 0;
	for (i = 0; i < list_size(overflow[indice]); i++) {
		if (esPaginaCorrecta(list_get(overflow[indice], i), pid, pagina)) {
			return list_get(overflow[indice], i);
		}
	}
}

/* Agrega una entrada a la lista enlazada correspondiente a una posición del vector de overflow */
void agregarSiguienteEnOverflow(int pos_inicial, int nro_frame) {
	list_add(overflow[pos_inicial], nro_frame);
}

/* Elimina un frame de la lista enlazada correspondiente a una determinada posición del vector de overflow  */
void borrarDeOverflow(int posicion, int frame) {
	int i = 0;
	int index_frame;

	for (i = 0; i < list_size(overflow[posicion]); i++) {
		if (frame == (int) list_get(overflow[posicion], i)) {
			index_frame = i;
			i = list_size(overflow[posicion]);
		}
	}

	list_remove(overflow[posicion], index_frame);
}

/* A implementar por el alumno. Devuelve 1 a fin de cumplir con la condición requerida en la llamada a la función */
int esPaginaCorrecta(int pos_candidata, int pid, int pagina) {
	return 1;
}

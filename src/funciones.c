/*
 * funciones_hash.c
 *
 *  Created on: 4/6/2017
 *      Author: utnso
 */

#include "funciones.h"

unsigned int calcularPosicion(int pid, int num_pagina) {
	char str1[20];
	char str2[20];
	sprintf(str1, "%d", pid);
	sprintf(str2, "%d", num_pagina);
	strcat(str1, str2);
	unsigned int indice = atoi(str1) % CANTIDAD_DE_MARCOS;
	return indice;
}

//En caso de colision, busca el siguiente indice en el vector de overflow.
int buscarEnOverflow(int indice, int pid, int pagina) {
	int i = 0;
	for (i = 0; i < list_size(overflow[indice]); i++) {
		//Aca hay que evaluar una condicion para fijarse que en el indice que devuelve el vector de overflow
		//esta la pagina correcta
		if (true) {
			return list_get(overflow[indice], i);
		}
	}
}

void inicializarOverflow(int cantidadDeMarcos) {
	overflow = malloc(sizeof(t_list*) * cantidadDeMarcos);
	int i;
	for (i = 0; i < CANTIDAD_DE_MARCOS; ++i) {
		overflow[i] = list_create();
	}
}
void addSiguienteEnOverflow(int pos_inicial, int nro_frame) {
	list_add(overflow[pos_inicial], nro_frame);
}

void deleteEnOverflow(int pos_inicial, int frame) {
	int i = 0;
	int index_frame;

	//busco el indice del frame en la lista enlazada del overflow
	for (i = 0; i < list_size(overflow[pos_inicial]); i++) {
		if (frame == list_get(overflow[pos_inicial], i)) {
			index_frame = i;
			i = list_size(overflow[pos_inicial]);
		}
	}
	list_remove(overflow[pos_inicial], index_frame);
}

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <commons/collections/list.h>

t_list** overflow;
int CANTIDAD_DE_MARCOS;
unsigned int calcularPosicion(int pid, int num_pagina);
void inicializarOverflow(int cantidad_de_marcos);
void agregarSiguienteEnOverflow(int pos_inicial, int nro_frame);
int buscarEnOverflow(int indice, int pid, int pagina);
void borrarDeOverflow(int pos_inicial, int frame);

#endif /* FUNCIONES_H_ */

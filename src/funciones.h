/*
 * funciones.h
 *
 *  Created on: 4/6/2017
 *      Author: utnso
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <commons/collections/list.h>

t_list** overflow;
int CANTIDAD_DE_MARCOS;
unsigned int calcularPosicion( int pid,  int num_pagina);
void addSiguienteEnOverflow( int pos_inicial, int nro_frame);
int buscarEnOverflow( int indice,int pid,int pagina);
void deleteEnOverflow(int pos_inicial, int frame);
void inicializarOverflow(int cantidadDeMarcos);
#endif /* FUNCIONES_H_ */

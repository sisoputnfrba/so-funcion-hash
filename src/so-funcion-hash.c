/*
 ============================================================================
 Name        : so-funcion-hash.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <cspecs/cspec.h>
#include "funciones.h"

context(testsFunciones) {
	describe("Tests para la funcion calcularPosicion") {
		before {
			CANTIDAD_DE_MARCOS = 10;
			inicializarOverflow(CANTIDAD_DE_MARCOS);
		}end
		after {
			int i;
			for(i=0;i<CANTIDAD_DE_MARCOS;i++) {
				list_destroy(overflow[i]);
			}
			free(overflow);
		}end
		it("test calcularPosicion me da la posicion correcta"){
			int pid=5;
			int pagina=5;
			int posicion_candidata = calcularPosicion(pid,pagina);
			should_int(posicion_candidata ) be equal to (5);
		}end
	}end
}

#include <stdio.h>
#include <stdlib.h>
#include <cspecs/cspec.h>
#include "funciones.h"

context(example) {
	describe("Biblioteca hash") {
		before {
			CANTIDAD_DE_MARCOS = 10;
			inicializarOverflow(CANTIDAD_DE_MARCOS);
		}end
		after {
			int i;
			for(i = 0; i < CANTIDAD_DE_MARCOS; i++) {
				list_destroy(overflow[i]);
			}
			free(overflow);
		}end
		it("test-case: buscar pagina. La posicion calculada efectivamente contiene la pagina buscada") {
			int pid=5;
			int pagina=5;
			
			/* Obtengo el numero de frame candidato con la función hash. */
			int posicion_candidata = calcularPosicion(pid,pagina);
			
			should_int(posicion_candidata) be equal to (5);
			
			/* A desarrollar por el grupo: verificar que el frame efectivamente contiene la pagina buscada */
			
		}end
		it("test-case: cargar_pagina.  La posicion calculada ya contiene otra pagina") {
			int pid = 5;
			int pagina = 5;
			/* Obtengo el numero de frame candidato con la función hash. */
			int posicion_candidata = calcularPosicion(pid,pagina);
			
			// valor hardcodeado. Deberia provenir de una funcion tipo esta_libre_el_frame(posicion_candidata) a desarrollar por el alumno
			int esta_libre_el_frame = 0; 
			
			if(!esta_libre_el_frame) { 
				int frame_libre = 3; /* valor hardcodeado. Deberia provenir de alguna funcion tipo buscarFrameLibre(); */

				agregarSiguienteEnOverflow(posicion_candidata,frame_libre);
			}
			should_int(list_get(overflow[posicion_candidata],0)) be equal to(3);
		}end
		it("test-case:  buscar pagina. La posicion calculada no contiene la pagina que se esta buscando") {
			int pid = 10;
			int pagina = 2;

			int pos_candidata = calcularPosicion(pid,pagina);
			
			/* Asumimos que en pos_candidata habia otra pagina, y por lo tanto debe agregarse en la zona de overflow */
			agregarSiguienteEnOverflow(pos_candidata, 3); // se hardcodea la eleccion del frame 3
			
			/* Asumimos que al verificar el contenido del frame, la pagina ubicada en pos_candidata no es la deseada */
			int es_pagina_buscada = 0; /* valor hardcodeado. Deberia provenir de alguna funcion tipo es_pagina_buscada(pos_candidata, pid, pagina) a desarrollar por el grupo */
			
			// Inicio del caso de uso
			
			int pos_definitiva;
			
			if(es_pagina_buscada) {
				pos_definitiva = pos_candidata; /* Por esta rama entraría si la función hash devuelve la posición donde se encuentra la página.  */
			}
			else {
				pos_definitiva = buscarEnOverflow(pos_candidata,pid,pagina);
			}
			should_int(pos_definitiva) be equal to (3);
		}end
		it("test-case: liberar paginas al finalizar proceso") {
			// Asumimos que todas las paginas de un proceso colisionaron en el mismo frame nro 4
			int pos_candidata = 4; 
			agregarSiguienteEnOverflow(pos_candidata, 0);
			agregarSiguienteEnOverflow(pos_candidata, 1);
			agregarSiguienteEnOverflow(pos_candidata, 2);
                        int pid = 10;
		
			// Inicio del caso de uso
			
			int i;
			/* Se debe buscar en todas las entradas de la tabla de páginas. */
			int total_frames_memoria = 3;
			for(i = 0; i < total_frames_memoria; i++) {
				int frame_contiene_pagina_del_proceso = 1; // valor hardcodeado. A desarrollar por el grupo
				if(frame_contiene_pagina_del_proceso) {
					int frame = i;
					int nro_pagina_encontrado = 4; // valor hardcodeado. Se debe obtener de la estructura apropiada
					int seAgregoEnOverflow = frame != calcularPosicion(pid,nro_pagina_encontrado);
					if(seAgregoEnOverflow) {
						borrarDeOverflow(calcularPosicion(pid,nro_pagina_encontrado),frame);
					}
					/* Luego se debe liberar el frame. A desarrollar por el grupo */
				}
			}

			should_bool(list_is_empty(overflow[pos_candidata])) be truthy;
		}end
	}end
}

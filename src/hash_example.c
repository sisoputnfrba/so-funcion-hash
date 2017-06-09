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
		it("test al calcular posicion, devuelve la posicion correcta") {
			int pid=5;
			int pagina=5;
			/* Obtengo el numero de frame candidato con la función hash. */
			int posicion_candidata = calcularPosicion(pid,pagina);
			/* Se debe verificar que en esa posicion se encuentre la pagina buscada. */
			should_int(posicion_candidata) be equal to (5);
		}end
		it("test al calcular posicion genera una colision, entonces agrega al vector de overflow el frame donde se aloja la pagina") {
			int pid=5;
			int pagina=5;
			/* Obtengo el numero de frame candidato con la función hash. */
			int posicion_candidata = calcularPosicion(pid,pagina);
			int pid_colision=10;
			int pagina_colision=5;
			int posicion_candidata_colision = calcularPosicion(pid_colision,pagina_colision);
			/* Se debe verificar si la posicion tiene la página buscada. En este caso la posicion previamente fue ocupada por otra página. */
			if(posicion_candidata==posicion_candidata_colision) {
				/* Se busca un frame libre en la memoria. */
				int frame_libre=3;
				/* Al haber colisión, se actualiza el vector de overflow. */
				agregarSiguienteEnOverflow(posicion_candidata,frame_libre);
			}
			should_int(list_get(overflow[posicion_candidata],0)) be equal to(3);
		}end
		it("test al calcular posicion, si hay una colision, busca en el vector de overflow") {
			int pid=10;
			int pagina=2;
			int pos_candidata=calcularPosicion(pid,pagina);
			/* En pos_candidata estaba cargada otra página. 
			* Hay una colisión. Entonces se busca un frame libre y se agrega esa posición al vector de overflow. 
			*/
			agregarSiguienteEnOverflow(pos_candidata,3);
			
			/* pos_final es la posición donde se encuentra la página */
			int pos_final;
			
			/* En la condición del if se debe preguntar si en pos_candidata se encuentra la página buscada (pid 10, página 2).
			* Como de antemano sabemos que no se encuentra en esa posición, forzamos el false para que vaya a buscar en el vector de overflow.
			*/ 
			if(0) {
				pos_final = pos_candidata; /* Por esta rama entraría si la función hash devuelve la posición donde se encuentra la página.  */
			}
			else {
				pos_final = buscarEnOverflow(pos_colision,pid,pagina);
			}
			should_int(pos_final) be equal to (3);
		}end
		it("test al finalizar un programa, se deben borrar todas las entradas correspondientes al proceso del vector de overflow") {
			int pos_candidata = 4;
			agregarSiguienteEnOverflow(pos_candidata,0);
			agregarSiguienteEnOverflow(pos_candidata,1);
			agregarSiguienteEnOverflow(pos_candidata,2);

			int i;
			/* Se debe buscar en todas las entradas de la tabla de páginas. */
			for(i=0;i<3;i++) {
				/* En la condición del if se debe evaluar si la entrada tiene una página correspondiente al proceso que se desea finalizar. */
				if(true) {
					int frame=i;
					int seAgregoEnOverflow = frame!=calcularPosicion(10,4);
					if(seAgregoEnOverflow) {
						borrarDeOverflow(calcularPosicion(10,4),frame);
					}
					/* Luego se debe liberar el frame. */
				}
			}

			should_bool(list_is_empty(overflow[pos_candidata])) be truthy;
		}end
	}end
}

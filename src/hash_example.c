#include <stdio.h>
#include <stdlib.h>
#include <cspecs/cspec.h>
#include "funciones.h"

context(example) {
	describe("Tests biblioteca de Hash") {
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
		it("test calcularPosicion me da la posicion correcta") { //aca va cada test( o asercion)
			int pid=5;
			int pagina=5;
			//Obtengo el numero de frame candidato con la funcion hash
			int posicion_candidata = calcularPosicion(pid,pagina);
			should_int(posicion_candidata) be equal to (5);
		}end
		it("si ") {
			int pid=5;
			int pagina=5;
			//Obtengo el numero de frame candidato con la funcion hash
			int posicion_candidata = calcularPosicion(pid,pagina);
			int pid_colision=10;
			int pagina_colision=5;
			int posicion_candidata_colision = calcularPosicion(pid_colision,pagina_colision);
			if(posicion_candidata==posicion_candidata_colision) {
				//aca el alumno deberia buscar un frame libre(completar)
				int frame_libre=3;
				agregarSiguienteEnOverflow(posicion_candidata,frame_libre);
			}
			//list_get trabaja por indice
			should_int(list_get(overflow[posicion_candidata],0)) be equal to(3);
		}end
		it("test buscar en overflow") {
			//asumimos que la posicion candidata 2 ya estaba tomada
			int pos_candidata = 2;
			agregarSiguienteEnOverflow(pos_candidata,3);
			int pid=10;
			int pagina=2;
			//generamos la colision
			int pos_colision=calcularPosicion(pid,pagina);
			int pos_final;
			//Aca deberian preguntar si la posicion de colision es de verdad o no de colision, es decir, si es la pagina correcta
			//pero a fines de mostrar el ejemplo, forzamos el false para que busque en overflow.
			if(0) {
				pos_final=pos_candidata;
			}
			else {
				pos_final = buscarEnOverflow(pos_colision,pid,pagina);
			}
			should_int(pos_final) be equal to (3);
		}end
		it("test delete en overflow") {
			int pos_candidata = 4;
			agregarSiguienteEnOverflow(pos_candidata,0);
			agregarSiguienteEnOverflow(pos_candidata,1);
			agregarSiguienteEnOverflow(pos_candidata,2);

			int i;
			//no va 3
			for(i=0;i<3;i++) {
				//aca deberia tener el pid del proceso que quiero eliminar..
				if(true) {
					int frame=i;
					//aca necesito pid y pagina
					int seAgregoEnOverflow = frame!=calcularPosicion(10,4);
					if(seAgregoEnOverflow) {
						borrarDeOverflow(calcularPosicion(10,4),frame);
					}
					//Liberar frame
				}
			}

			should_bool(list_is_empty(overflow[pos_candidata])) be truthy;
		}end
	}end
}

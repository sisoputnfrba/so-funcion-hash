# Funcion Hash

Ejemplo de funcion hash para obtener el indice de la tabla de paginas invertidas correspondiente al TP1C2017 ESTheR

La finalidad de este ejemplo es proveer una aproximacion de como manejar la funcion hash junto con sus incumbencias en cuanto a colisiones.

## Notas

- Esta no es una biblioteca completa de hash, a diferencia de la biblioteca de commons, sino que se proveeran funciones escenciales para calcular hash y manejar colisiones con un vector de overflow.
- Este ejemplo utiliza CSpec para crear tests a fin de explicar cada funcion dada , para mas informacion sobre como implementar nuevos tests, consultar:  https://github.com/mumuki/cspec

## Guia de instalacion:

Tener **[so-commons-library]( https://github.com/sisoputnfrba/so-commons-library)** instaladas

- Clonar el repositorio desde git (no usar el link de **Download ZIP** que provee GitHub).

Compilar el proyecto, para eso existen dos maneras:

* Primera forma:
	* `. ./scriptCompilar.sh`
* Segunda forma:
	* `chmod +x scriptCompilar.sh`
	* `./scriptCompilar.sh` 

## Uso 

 `./tests` para correr los tests existentes.

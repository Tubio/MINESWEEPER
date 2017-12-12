#ifndef DISENIADOR_H_
#define DISENIADOR_H_

# include "constantes.h"

# include "EasyBMP.h"
# include "EasyBMP_BMP.h"
# include "EasyBMP_DataStructures.h"
# include "EasyBMP_VariousBMPutilities.h"

class Diseniador{

private:

	BMP disenio;
	unsigned int numeroDeImpresion;
	unsigned int cantidadFilas;
	unsigned int cantidadColumnas;


public:

	//constructor
	Diseniador();

	//post: crea un disenio todo blanco con las dimensiones que tenga de fila y columna
	void crearDisenioBase();

	//post: asigna la cantidad de filas al disenio
	void modificarCantidadDeFilas(uint filas);

	//post: asigna la cantidad de columnas al disenio
	void modificarCantidadDeColumnas(uint columnas);

	//post: retorna el disenio que tenga actualmente
	BMP obtenerDisenio();

	/* pre: fila y columna deben estar dentro del rango de las dimensiones de este
	 * disenio, valor debe ser = MINA - BANDERA - 1 2 3 4 5 6 7 8 9 - VACIO - DESMARCAR
	 * post:cambia una casilla del disenio
	 */
	void cambiarEnBMP(char valor, uint fila, uint columna);

	/* post: crea un archivo BMP en la computadora con el numero de archivo impreso
	 * al final, este numero se va modificando a medida que se llama a este metodo
	 */
	void escribirDisenio();

private:

	//post: cambia un caracter en el nombre del archivo
	void cambiarCaracterEnLaPosicion(char caracter,char nombre[8],uint posicion);

	//post: dibuja las casillas de juego, todas como bloqueadas
	void llenarMapaBloqueado();

	//esteticas

	//post: ubica las esquinas en el disenio
	void llenarEsquinas();

	//post: ubica los bordes en el disenio
	void llenarBordes();

	//internas a llenas esquinas
	void llenarEsquinaSuperiorDerecha();
	void llenarEsquinaSuperiorIzquierda();
	void llenarEsquinaInferiorDerecha();
	void llenarEsquinaInferiorIzquierda();

	//internas a llenas bordes
	void llenarBordeSuperior();
	void llenarBordeInferior();
	void llenarBordeIzquierdo();
	void llenarBordeDerecho();

	//utilizadas para calcular la cantidad de píxeles que va a ocupar el Disenio
	uint calcularAncho(unsigned int dimColumnas);
	uint calcularAlto(unsigned int dimFilas);

};

#endif /*DISENIADOR_H_*/

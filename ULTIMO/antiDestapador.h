#ifndef ANTIDESTAPADOR_H_
#define ANTIDESTAPADOR_H_

# include "mapa.h"
# include "jugador.h"
# include "constantes.h"
# include "mina.h"


class AntiDestapador{

private:
	Jugador* jugador;
	unsigned int fila;
	unsigned int columna;
	int puntaje;
	Mapa* mapa;

public:
	/*pre: recibe como parametro un puntero al mapa actual y un puntero a un jugador
	* post: se crea un antidestapador con fila, columna y puntaje = 0 y el puntero a mapa y jugador 
	* correspondiente.
	*/
	AntiDestapador(Mapa* mapaActual, Jugador* jugador);
	
	/*pre: recibe como parametro uint correspondientes a la fila y columna de la jugada a tapar
	* post: retorna el puntaje obtenido al tapar la casilla correspondiente a la fila y columna
	* recibidas.
	*/
	uint tapar(uint filaJugada,uint columnaJugada);
	
	/*pre: se ha actualizado los atributos con la informacion de la casilla a tapar antes de ser llamado
	* post: segun el valor de la casilla cuya informacion esta guardada en los atributos si esta vacia llama a tapar 
	* pandemia, si es una mina revive al jugador , elimina la casilla de casillas destapadas y retorna el puntaje 
	* de tapar la casilla 
	*/
	int puntajeAltapar();
	
	void crearListaCasillasYAsignarPuntero();
	
	/*pre: si han asignado los atributos correspondientes al antidestapador
	* post: retorna si  la fila y la columna guardada en los atributos es valida, es decir
	* corresponde a valores mayores a 0, y menores a dimensionFila y dimensionColumna respectivamente.
	*/
	bool validarUbicacion(uint fila, uint columna);

	/*pre:
	 * post: retorna puntaje 0 si la casilla no es una mina, si es mina retorna PERDIO_PARTIDA.
	 */
	uint taparCasillaNoVacia(char ValorCasilla);
	
	/*pre:
	 * post: llama al metodo del mapa de eliminarCasillasDestapadasDesde con los valores de fila y columna 
	 * guardados en los atributos.
	 */
	void taparPandemia();

};

#endif /* ANTIDESTAPADOR_H_ */

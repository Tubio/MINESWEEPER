#ifndef JUEZ_H_
#define JUEZ_H_

# include "mapa.h"
# include "jugador.h"
# include "constantes.h"
# include "listaCircularCursor.h"
# include <iostream>
# include <fstream>
# include "jugadaLight.h"
# include "antiDestapador.h"
# include "pseudoGrafo.h"
# include "pantalla.h"

class Juez{

	private:
		int cantidadDeJugadores;
		ListaCircularCursor<Jugador*>* jugadores;
		PseudoGrafo<JugadaLight*>* jugadas;
		Mapa* tableroDeJuego;
		int jugadoresQuePerdieron;
		uint casillasOcultas;
		uint minasPorDescubrir;

	public:
		/* Pre: Recibe una "cantidadDeJugadores" de tipo int, y un puntero a Mapa o "tableroDeJuego".
		* Post: Se crea un Juez con la cantidadDeJugadores y tableroDeJuego pasados por parámetros,
		* 	deja creada una lista con cantidadDeJugadores punteros a Jugador.*/
		Juez(unsigned int cantidadJugadores,Mapa* mapaRecibido);

		/* Post: inicia el juego. Esto es, pide jugadas a los jugadores por turnos, las jugadas se realizan,
		* 	se modifican los puntajes, se muestra el tablero, verifica si cada jugador ganó o perdió y se
		* 	muestran los mensajes correspondientes. */
		void inicializarJuego();



		/* Post: Libera los recursos asociados a Juez.*/
		~Juez();

	private:
		/* Pre: Se ha llamado a crearYAsignarListaDeJugadores()
		* Post: Crea a los jugadores y los agrega a la lista.*/
		void crearJugadores();

		/* Post: Crea una lista de jugadores.*/
		void crearYAsignarListaDeJugadores();

		/* Pre: Se ha llamado a crearYAsignarListaDeJugadores(). Recibe un puntero a un Jugador.
		* Post: Inserta "nuevo" a la lista de jugadores creada por crearYAsignarListaDeJugadores().*/

		void crearYAsignarGrafoDeJugadas();

		void insertarJugador(Jugador* nuevo);

		/* Post: avanza hasta el jugador más próximo que siga jugando.*/
		void avanzarJugador();

		//void mostrarJugador(); /* A esto si lo quieren usar para algo, hay que cambiarlo (es corito, pero no sé qué quieren mostrar)*/


		/* Pre: Recibe un puntero al jugadorActual, una variable de tipo int que indica la cantidad de jugadores que perdieron,
		* 	un puntero a Mapa, y una variable de tipo unsigned int que indica la cantidad de minas que quedan por descubrir
		* 	en el tablero.
		* Post: da su turno al jugadorActual y muestra el tablero de juego.*/
		void sigueJugando(Jugador* jugadorActual,Mapa* tableroDeJuego);
		 /* pre: 
		 * post: crea un archivo de texto con los puntajes de los jugadores.
		 */
		void crearArchivoConPuntajes();
		/* pre: la lista de jugadores ya ha sido creada
		* post: calcula con los puntajes quien fue el jugador que mas puntaje tuvo he imprime por 
		* pantalla la respectiva felicitacion segun hubo ganador o un empate.
		*/
		void encontrarJugadorQueGanoPorPuntaje();
		/*pre:
		*post: devuelve la cantidad de banderas(marcas) que se ubicaron correctamente, es decir donde 
		* efectivamente habia una mina.
		*/
		uint buscarBanderasCorrectas();
		/*pre: recibe por parametro una bandera y una lista de minas ya inicializada. 
		* post: devuelve si la bandera actual coincide con una mina, es decir estan en la misma ubicacion.
		*/
		bool banderaEsCorrecta(Bandera actual,Lista<Mina>* minas);
		/*pre: se llama cuando el jugador quiere realizar la jugada de deshacer o rehacer.
		* post: mientras que el jugador diga que quiere seguir haciendo cambios y se le permita
		* va a pedir al usuario que opcion elige y realiza el rehacer o deshacer jugada respectivamente.
		*/
		void realizarCambios();
		/*pre: se llama cuando el jugador a pedido deshacer una jugada
		* post: segun sea la ultima jugada reaizada se ubica al jugador que la hizo y se lama al antidestapador
		* o al marcador para deshacer la jugada hecha por el jugador y modificar su puntaje, y en caso de que haya perdido
		* el jugador que hizo la jugada, volverlo a poner en juego; todo esto mientras que hayan jugadas por deshacer, 
		* retorna si es posible o no seguir deshaciendo.
		*/
		bool deshacerJugada();
		/*pre: se llama cuando el jugador a pedido la opcion de rehacer una jugada
		*post: le muestra al usuario por pantalla las opciones de jugadas que se pueden rehacer y segun la opcion 
		* que dio el usuario se llama al rehacer paralela con esa opcion; todo esto mientras que se puedan rehacer jugadas,
		* retorna si se puede seguir rehaciendo jugadas.
		*/
		bool rehacerJugada();
		/*pre: se llama desde el rehacer jugada y recibe por parametro la posicion de la jugada que el jugador quiere rehacer 
		* post: encuentra la jugada que esta en la posicion indicada, rehace la jugada y deja la jugada actual del grafo 
		* apuntando a la jugada que se rehizo.
		*/
		void rehacerParalela(uint posicion);
		/* muestra por pantalla las felicitaciones respectivas del jugador que gano por puntaje, y si hay empate lo muestra 
		* por pantalla.
		*/
		void mostrarFelicitaciones(ListaCircularCursor<Jugador*>* jugadores,
									int puntajeMaximo,int puntajesMaximosIguales);
};

#endif /* JUEZ_H_ */

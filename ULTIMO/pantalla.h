#ifndef PANTALLA_H_
#define PANTALLA_H_

# include <iostream>
# include <string>
# include "constantes.h"
# include "pseudoGrafo.h"
# include "jugadaLight.h"
# include "jugador.h"
# include "listaCircularCursor.h"


class Pantalla{

	public:

		void playGame();

		char pedirOpcionPasadoFuturo();

		int pedirOpcionRehacerJugada(PseudoGrafo<JugadaLight*>* jugadas);

		void noSePuedeRetroceder();

		void mostrarPuntajeDeJugadorQueHaPerdido(Jugador* jugadorActual);

		void terminoLaPartida();

		void mostrarFelicitaciones(ListaCircularCursor<Jugador*>* jugadores,
				int puntajeMaximo,uint puntajesMaximosIguales);

		void noHayJugadas();

		char imprimirOpcionesDeMenu();

		void imprimirReglasDeJuego();

		void imprimirTitulo();

		void imprimirPidiendoDatos();
	
		void comprobarDatos(char dificultad, uint dimFila, uint dimColumna, uint cantJugadores);

		void pedirDimensiones(uint &filaUser, uint &colUser);

		char pedirDificultad();

		uint pedirCantidadJugadores();
	
	private:
	
		void imprimirLinea();
	
		void imprimirDatosIngresados(uint dimFila, uint dimColumna, std::string dificultadPalabra,
				int numeroDeMinas, uint cantJugadores);


};
#endif

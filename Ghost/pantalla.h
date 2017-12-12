#ifndef PANTALLA_H_
#define PANTALLA_H_

# include <iostream>
# include <string>
# include "constantes.h"
# include "pseudoGrafo.h"
# include "jugadaLight.h"
# include "listaCircularCursor.h"


class Pantalla{

	public:

		// Llamados desde Juez:

		void playGame();

		char pedirOpcionPasadoFuturo();

		int pedirOpcionRehacerJugada(PseudoGrafo<JugadaLight*>* jugadas);

		void noSePuedeRetroceder();

		void mostrarPuntajeDeJugadorQueHaPerdido(char alias, int puntaje);

		void terminoLaPartida();

		void noHayJugadas();

		void imprimirEncabezadoUnicoGanador();

		void imprimirEncabezadoGanadores();

		void imprimirFelicitacionesHaGanado(char alias, int puntaje);


		// Llamados desde Menú:

		char imprimirOpcionesDeMenu();

		void imprimirReglasDeJuego();

		void imprimirTitulo();

		void imprimirPidiendoDatos();
	
		void comprobarDatos(char dificultad, uint dimFila, uint dimColumna, uint cantJugadores);

		void pedirDimensiones(uint &filaUser, uint &colUser);

		char pedirDificultad();

		uint pedirCantidadJugadores();


		// Llamados desde Jugador:

		void imprimirTurno(char alias);

		char verSiQuiereModificarJugadas();

		void puntajeInsuficiente();

		void pedirUbicacionAUser(uint &fila, uint &columna);

		char pedirOpcionAUser();

		//Llamados desde antidestapador:
	
		void imprimirJugadorRevive(char alias);


	private:
	
		void imprimirLinea();
	
		void imprimirDatosIngresados(uint dimFila, uint dimColumna, std::string dificultadPalabra,
				int numeroDeMinas, uint cantJugadores);


};
#endif

#ifndef PSEUDOGRAFO_H_
#define PSEUDOGRAFO_H_

#include "nodoGrafo.h"

template <class T> class PseudoGrafo{

private:
	NodoGrafo<T>* primero;
	NodoGrafo<T>* actual;


public:
	//constructor
	PseudoGrafo();

	/* post: el dato se inserta como siguiente al que este como actual. Si el actual ya tiene un siguiente
	 * se inserta como ultimo paralelo al siguiente
	 */
	void insertar(T dato);

	//post: retorna el nodo que este como actual
	NodoGrafo<T>* obtenerActual();

	//post: retorna si la lista no tiene elementos en su interior
	bool estaVacia();

	/* post: retrocede una posicion del cursor, si el cursor estaba en el primer nodo,
	 * este queda apuntando a NULL (no inicializado)
	 */
	bool retrocederCursor();

	//pre: cursor inizializado
	//post: retorna el dato que este como actual
	T obtenerDatoActual();

	//post: retorna el primer Nodo
	NodoGrafo<T>* obtenerPrimero();

	//post: avanza al siguiente del actual (si existe)
	bool avanzarCursor();

	//post: avanza al siguiente paralelo (si existe)
	bool avanzarCursorAParalela();

	//post: elimina el nodo de la lista
	void borrarNodo(NodoGrafo<T>* aBorrar);

	//destructor
	~PseudoGrafo();

private:
	//se inserta el nodo como ultimo paralelo al siguiente del actual
	void insertarComoUltimoParalelo(NodoGrafo<T>* paralelo,NodoGrafo<T>* anteriorParalelo);

};

template <class T>
PseudoGrafo<T>::PseudoGrafo(){

		this->primero=NULL;
		this->actual=NULL;
}

template <class T>
void PseudoGrafo<T>::insertar(T dato){
	/*
	 * ingresa un dato como siguiente al actual, si el siguiente tiene paralelos, lo ingresa como
	 * el ultimo de los paralelos, luego mueve el cursor actual a la nueva posicion.
	 */


	NodoGrafo<T>* nuevo = new NodoGrafo<T>(dato);


	if(primero == NULL){ //si la lista esta vacia

		primero = nuevo;

	}else if(actual == NULL){ //si la lista tiene datos, pero el cursor esta apuntando a NULL
		insertarComoUltimoParalelo(nuevo,primero);
	}
	else if(actual->obtenerSiguiente() == NULL){ //si el actual no tiene siguiente
	    actual->cambiarSiguiente(nuevo);
	    nuevo->cambiarAnterior(actual);
	}else{									//si el actual tiene siguiente, agregarlo como paralelo
		NodoGrafo<T>* siguiente = actual ->obtenerSiguiente();
		insertarComoUltimoParalelo(nuevo,siguiente);
		nuevo->cambiarAnterior(actual);
	}
	actual = nuevo;

}

template <class T>
void PseudoGrafo<T>::insertarComoUltimoParalelo(NodoGrafo<T>* paralelo,NodoGrafo<T>* vecino){

	while(vecino->tieneParalelo())
		vecino = vecino->obtenerParalelo();

	vecino->cambiarParalelo(paralelo);

}

template <class T>
NodoGrafo<T>* PseudoGrafo<T>::obtenerActual(){

	return (this->actual);
}

template <class T>
T PseudoGrafo<T>::obtenerDatoActual(){

	T dato = actual->obtenerDato();
	return dato;

}

template <class T>
bool PseudoGrafo<T>::estaVacia(){

	return (this->primero == NULL);
}

template <class T>
bool PseudoGrafo<T>::retrocederCursor(){

	bool sePuedeRetroceder = false;

	if (actual != NULL){
		if(actual->tieneAnterior())
			actual = actual->obtenerAnterior();
		else actual = NULL;
		sePuedeRetroceder = true;
	}
	return sePuedeRetroceder;
}

template <class T>
NodoGrafo<T>* PseudoGrafo<T>::obtenerPrimero(){

	return this->primero;
}

template <class T>
bool PseudoGrafo<T>::avanzarCursor(){
//si tiene siguiente, lo avanza y devuelve true
	bool sePuedeAvanzar = false;

	if(this->actual == NULL){
		if(this->primero != NULL){
			actual = primero;
			sePuedeAvanzar = true;
		}
	}

	else if(this->actual->tieneSiguiente()){
		this->actual = this->actual->obtenerSiguiente();
		sePuedeAvanzar = true;
	}
return sePuedeAvanzar;
}

template <class T>
bool PseudoGrafo<T>::avanzarCursorAParalela(){
//si tiene paralelo, lo avanza y devuelve true
	bool tieneParalelo = false;

	if(this->actual->tieneParalelo()){
		this->actual= this->actual->obtenerParalelo();
		tieneParalelo = true;
	}
return tieneParalelo;

}

template <class T>
PseudoGrafo<T>::~PseudoGrafo(){

	/* destructor recursivo:
	 * elimina los nodos desde el ultimo paralelo, hasta el primero no paralelo
	 */

	if(actual != NULL){

		NodoGrafo<T>* ultimo = primero;
		NodoGrafo<T>* anterior = NULL;

		while(ultimo->obtenerSiguiente() != NULL)
			ultimo = ultimo->obtenerSiguiente();

		while(primero != ultimo){

			anterior = ultimo->obtenerAnterior();
			borrarNodo(ultimo);
			ultimo = anterior;
		}

		delete ultimo->obtenerDato();
		delete ultimo;
	}
}

template <class T>
void PseudoGrafo<T>::borrarNodo(NodoGrafo<T>* aBorrar){

	if(aBorrar->tieneSiguiente()){
		borrarNodo(aBorrar->obtenerSiguiente());
	}
	if(aBorrar->tieneParalelo()){
		borrarNodo(aBorrar->obtenerParalelo());
	}

	NodoGrafo<T>* anterior = aBorrar->obtenerAnterior();
	anterior->cambiarSiguiente(NULL);
	anterior->cambiarParalelo(NULL);

	delete aBorrar->obtenerDato();
	delete aBorrar;

}

#endif /* PSEUDOGRAFO_H_ */

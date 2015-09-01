#include <stdbool.h>
#include <stdio.h>


/** Tipos lista y nodo **/

	typedef struct lista_t {
		struct nodo_t 	*primero;
	} __attribute__((__packed__)) lista;

	typedef struct nodo_t {
		struct nodo_t 	*siguiente;
		char 			*palabra;
	} __attribute__((__packed__)) nodo;


/** Funciones de palabras **/

	unsigned char palabraLongitud( char *p );
	bool palabraMenor( char *p1, char *p2 );
	void palabraFormatear( char *p, void (*funcModificarString)(char*) );
	void palabraImprimir( char *p, FILE *file );
	char *palabraCopiar( char *p );


/** Funciones de lista y nodo **/

	nodo *nodoCrear( char *palabra );
	void nodoBorrar( nodo *n );
	lista *oracionCrear( void );
	void oracionBorrar( lista *l );
	void oracionImprimir( lista *l, char *archivo, void (*funcImprimirPalabra)(char*,FILE*) );


/** Funciones Avanzadas **/

	float longitudMedia( lista *l );
	void insertarOrdenado( lista *l, char *palabra, bool (*funcCompararPalabra)(char*,char*) );
	void filtrarPalabra( lista *l, bool (*funcCompararPalabra)(char*,char*), char *palabraCmp );
	void descifrarMensajeDiabolico( lista *l, char *archivo, void (*funcImpPbr)(char*,FILE* ) );


/** Funciones Auxiliares ya implementadas en C **/

	bool palabraIgual( char *p1, char *p2 );											
	void insertarAtras( lista *l, char *palabra );


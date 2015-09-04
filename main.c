#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void foo( char *s ){
	if( s[0] != 0 ) s[0] = 'X'; 
}
/*
void bar(char *s, FILE  *f){

}
*/
void oracionBorrar2(lista *list){
	
	//obtengo el primer nodo
	nodo *nodoAux, *siguiente;
	nodoAux = list->primero;

	//si tiene nodos itero y borro
	while(nodoAux != NULL){
		siguiente = nodoAux->siguiente;
		printf("word: %s \n", nodoAux->palabra);
		free(nodoAux);
		nodoAux = siguiente;
	}
	free(list);

	return;

}

int main (void){
	printf( "la longitud de ’hola’ es = %d \n", palabraLongitud( "hola" ) );
	
	if( palabraMenor( "caZa", "casa" ) )
		printf( "TRUE\n" );
	else 
		printf( "FALSE\n" );

	
	char test[] = "hola";
	palabraFormatear( test , foo );
	printf("%s\n", test);

	char test2[] = "imprimir_test";
	FILE *pfile;
	pfile = fopen(test2, "wt");
	palabraImprimir( "Hola mundo", pfile );
	fclose(pfile);


	char *unaPalabra = palabraCopiar( "hola" );
	char *otraPalabra = palabraCopiar( unaPalabra );
	unaPalabra[1] = 'X';
	palabraImprimir( unaPalabra, stdout );
	palabraImprimir( otraPalabra, stdout );
	free( unaPalabra );
	free( otraPalabra );

	nodo *miNodo = nodoCrear( palabraCopiar( "algunaPalabra" ) );
	printf( "Palabra del Nodo: %s\n", miNodo->palabra );
	nodoBorrar(miNodo);
	
	lista *miLista = oracionCrear();
	insertarAtras(miLista, palabraCopiar( "Hola" ));
	insertarAtras(miLista, palabraCopiar( "Mundo" ));
	insertarAtras(miLista, palabraCopiar( "Cruel" ));
	oracionImprimir( miLista, "lista_imprimir", palabraImprimir );
	
	printf( "LongMedia = %2.5f\n", longitudMedia( miLista ) );

	oracionBorrar( miLista );
	return 0;
}
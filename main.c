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

void insertarOrdenado2(lista *l, char *p, bool (*funcCompararPalabra)(char*,char*)){

	nodo *temp;
	temp = l->primero;

	if(temp == NULL){
		insertarAtras(l,p);
		return;
	}

	nodo *nuevo;
	nuevo = nodoCrear(p);
	nodo *temp2;


	// quiero el nodo y el siguiente
	// para luego comparar contra ambos y decidir si
	// colocar el nuevo nodo en el medio
	
	// en primer lugar si es menor al primer nodo
	// lo inserto antes que el y chau

	if(funcCompararPalabra(nuevo->palabra, temp->palabra)){
		l->primero = nuevo;
		nuevo->siguiente = temp;
		return;
	}else{
		temp2 = temp;
		temp = temp->siguiente;
		// busco al primer mayor e inserto antes de el
		// si no lo encuentro inserto al final de la lista :D
		while(temp != NULL){
			if(funcCompararPalabra(nuevo->palabra, temp->palabra))
				break;
			temp2 = temp;
			temp = temp->siguiente;
		}
		// si termino por temp == NULL
		// O porque encontró una palabra mayor a la nueva
		// lo coloco despues de temp 2
		nuevo->siguiente = temp;
		temp2->siguiente = nuevo;
		return;
	}
}

int main (void){
	printf( "la longitud de ’hola’ es = %d \n", palabraLongitud( "hola" ) );
	
	if( palabraMenor( "a", "a" ) )
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
	//insertarAtras(miLista, palabraCopiar( "Hola" ));
	//insertarAtras(miLista, palabraCopiar( "Mundo" ));
	//insertarAtras(miLista, palabraCopiar( "Cruel" ));
	//oracionImprimir( miLista, "lista_imprimir", palabraImprimir );
	
	printf( "LongMedia = %2.5f\n", longitudMedia( miLista ) );

	insertarOrdenado( miLista, palabraCopiar( "b" ), palabraMenor );
	insertarOrdenado( miLista, palabraCopiar( "b" ), palabraMenor );
	insertarOrdenado( miLista, palabraCopiar( "aa" ), palabraMenor );
	insertarOrdenado( miLista, palabraCopiar( "a" ), palabraMenor );
	oracionImprimir( miLista, "insertaOrdenado", palabraImprimir );

	oracionBorrar( miLista );
	return 0;
}
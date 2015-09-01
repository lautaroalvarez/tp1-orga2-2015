#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "lista.h"

void cifrar_diabolico( char *s );
void descifrar_diabolico( char *s );
void listaConFormato( lista *l, void (*funcModificarString)(char*) );
lista* getlistaMixta( int nmax );
lista* getlistaComun();
lista* getlistaInversa();
void palabraImprimirCatedra( char *p, FILE *file );
bool palabraDistinta( char *p1, char *p2 );

char *archivoCaso1 =  "salida.caso1.txt";
char *archivoCaso2 =  "salida.caso2.txt";
char *archivoCasoN =  "salida.casoN.txt";
void caso1Elemento();
void caso2Elementos();
void casoNElementos();

int main() {
  srand(20120831);
  remove("salida.caso1.txt");
  caso1Elemento();
  remove("salida.caso2.txt");
  caso2Elementos();
  remove("salida.casoN.txt");
  casoNElementos();
  return 0;
}

void cifrar_diabolico( char *s ){
	int i = 0;
	while( s[i] != 0 ){
		if( s[i] != 48 && s[i] != 57 && s[i] != 65 && s[i] != 90 && s[i] != 97 && s[i] != 122 )
			s[i] = s[i] + 1;
	i++;
	}
}

void descifrar_diabolico( char *s ){
	int i = 0;
	while( s[i] != 0 ){
		if( s[i] != 48 && s[i] != 57 && s[i] != 65 && s[i] != 90 && s[i] != 97 && s[i] != 122 )
			s[i] = s[i] - 1;
	i++;
	}
}

void listaConFormato( lista *l, void (*funcModificarString)(char*) ){
	nodo *n = l->primero;
	while( n != NULL ){
		palabraFormatear( n->palabra, funcModificarString );
		n = n->siguiente;
	}
	return;
}

lista* getlistaMixta( int nmax ){
	lista* res = oracionCrear();
	char* palabras[] = { "Hice", "a", "mi", "cuerpo", "amigo", "del", "cielo", "y", "la", "distacia", "y", "me", 
							"fui", "a", "buscarle", "una", "verdad", "a", "mi", "corazon", "Algo", "tan", "grande", 
							"como", "el", "cielo", "y", "las", "montanias", "y", "tan", "pequenio", "como", "una", 
							"gota", "de", "rocio", "Y", "ya", "no", "estubo", "mas", "conmigo", "mi", "corazon", 
							"se", "fue", "a", "posar", "en", "cada", "una", "de", "las", "cosas", "se", "fue", "a", 
							"fundir", "con", "la", "escencia", "y", "la", "sabia", "Y", "ahora", "solo", "un", 
							"camino", "he", "de", "caminar", "cualquier", "camino", "que", "tenga", "corazon", 
							"Atravezando", "todo", "su", "largo", "sin", "aliento", "dejando", "atraz", "mil", 
							"razones", "en", "el", "tiempo", "Morir", "queriendo", "ser", "libre", "encontrar", 
							"mi", "lado", "salvaje", "ponerle", "alas", "a", "mi", "destino", "romper", "los", 
							"dientes", "de", "este", "engranaje", "Hice", "un", "lugar", "en", "el", "refugio", 
							"de", "mis", "suenios", "y", "guarde", "ahi", "mi", "tesoro", "mas", "preciado", 
							"Donde", "no", "llega", "el", "hombre", "con", "sus", "jaulas", "ni", "la", 
							"maquinaria", "de", "la", "supervivencia", "Me", "fue", "mas", "facil", "intentar", 
							"la", "vida", "que", "venderla", "al", "intelecto", "y", "la", "conformidad" };
	for( int i = 0 ; i < nmax ; i++ )
		insertarOrdenado( res, palabraCopiar( palabras[rand()%154] ), palabraMenor );
	return res;
}

lista* getlistaComun(){
	lista* res = oracionCrear();
	char* palabras[] = { "Hice", "a", "mi", "cuerpo", "amigo", "del", "cielo", "y", "la", "distacia", "y", "me", 
							"fui", "a", "buscarle", "una", "verdad", "a", "mi", "corazon", "Algo", "tan", "grande", 
							"como", "el", "cielo", "y", "las", "montanias", "y", "tan", "pequenio", "como", "una", 
							"gota", "de", "rocio", "Y", "ya", "no", "estubo", "mas", "conmigo", "mi", "corazon", 
							"se", "fue", "a", "posar", "en", "cada", "una", "de", "las", "cosas", "se", "fue", "a", 
							"fundir", "con", "la", "escencia", "y", "la", "sabia", "Y", "ahora", "solo", "un", 
							"camino", "he", "de", "caminar", "cualquier", "camino", "que", "tenga", "corazon", 
							"Atravezando", "todo", "su", "largo", "sin", "aliento", "dejando", "atraz", "mil", 
							"razones", "en", "el", "tiempo", "Morir", "queriendo", "ser", "libre", "encontrar", 
							"mi", "lado", "salvaje", "ponerle", "alas", "a", "mi", "destino", "romper", "los", 
							"dientes", "de", "este", "engranaje", "Hice", "un", "lugar", "en", "el", "refugio", 
							"de", "mis", "suenios", "y", "guarde", "ahi", "mi", "tesoro", "mas", "preciado", 
							"Donde", "no", "llega", "el", "hombre", "con", "sus", "jaulas", "ni", "la", 
							"maquinaria", "de", "la", "supervivencia", "Me", "fue", "mas", "facil", "intentar", 
							"la", "vida", "que", "venderla", "al", "intelecto", "y", "la", "conformidad" };
	for( int i = 0 ; i < 154 ; i++ )
		insertarAtras( res, palabraCopiar( palabras[i] ) );
	return res;
}

lista* getlistaInversa(){
	lista* res = oracionCrear();
	char* palabras[] = { "Hice", "a", "mi", "cuerpo", "amigo", "del", "cielo", "y", "la", "distacia", "y", "me", 
							"fui", "a", "buscarle", "una", "verdad", "a", "mi", "corazon", "Algo", "tan", "grande", 
							"como", "el", "cielo", "y", "las", "montanias", "y", "tan", "pequenio", "como", "una", 
							"gota", "de", "rocio", "Y", "ya", "no", "estubo", "mas", "conmigo", "mi", "corazon", 
							"se", "fue", "a", "posar", "en", "cada", "una", "de", "las", "cosas", "se", "fue", "a", 
							"fundir", "con", "la", "escencia", "y", "la", "sabia", "Y", "ahora", "solo", "un", 
							"camino", "he", "de", "caminar", "cualquier", "camino", "que", "tenga", "corazon", 
							"Atravezando", "todo", "su", "largo", "sin", "aliento", "dejando", "atraz", "mil", 
							"razones", "en", "el", "tiempo", "Morir", "queriendo", "ser", "libre", "encontrar", 
							"mi", "lado", "salvaje", "ponerle", "alas", "a", "mi", "destino", "romper", "los", 
							"dientes", "de", "este", "engranaje", "Hice", "un", "lugar", "en", "el", "refugio", 
							"de", "mis", "suenios", "y", "guarde", "ahi", "mi", "tesoro", "mas", "preciado", 
							"Donde", "no", "llega", "el", "hombre", "con", "sus", "jaulas", "ni", "la", 
							"maquinaria", "de", "la", "supervivencia", "Me", "fue", "mas", "facil", "intentar", 
							"la", "vida", "que", "venderla", "al", "intelecto", "y", "la", "conformidad" };
	for( int i = 0 ; i < 154 ; i++ )
		insertarAtras( res, palabraCopiar( palabras[154-1-i] ) );
	listaConFormato( res, cifrar_diabolico );
	return res;
}

void palabraImprimirCatedra( char *p, FILE *file ){
	fprintf( file, "%s ", p );
	return;
}

bool palabraDistinta( char *p1, char *p2 ){
	return !palabraIgual( p1, p2 );
}

void caso1Elemento(){
	FILE *pFile; lista *A = oracionCrear(); char pVacia[] = "";


	pFile = fopen( archivoCaso1, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO PALABRA-LONGITUD\n", pFile );
		fprintf( pFile, "%d\n", palabraLongitud( pVacia ) ); 
		fprintf( pFile, "%d\n", palabraLongitud( "a" ) );
		fprintf( pFile, "%d\n", palabraLongitud( "abcd" ) );
	fclose( pFile );
	
	pFile = fopen( archivoCaso1, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO PALABRA-MENOR\n", pFile );			
		fprintf( pFile, "merced < mercurio: " ); if( palabraMenor( "merced", "mercurio" ) ) fprintf( pFile, "TRUE\n" ); else fprintf( pFile, "FALSE\n" );
		fprintf( pFile, "perro < zorro: " ); if( palabraMenor( "perro", "zorro" ) ) fprintf( pFile, "TRUE\n" ); else fprintf( pFile, "FALSE\n" );
		fprintf( pFile, "senior < seniora: " ); if( palabraMenor( "senior", "seniora" ) ) fprintf( pFile, "TRUE\n" ); else fprintf( pFile, "FALSE\n" );
		fprintf( pFile, "seniora < senior: " );	if( palabraMenor( "seniora", "senior" ) ) fprintf( pFile, "TRUE\n" ); else fprintf( pFile, "FALSE\n" );
		fprintf( pFile, "caZa < casa: " ); if( palabraMenor( "caZa", "casa" ) ) fprintf( pFile, "TRUE\n" ); else fprintf( pFile, "FALSE\n" );
		fprintf( pFile, "hola < hola: " ); if( palabraMenor( "hola", "hola" ) ) fprintf( pFile, "TRUE\n" ); else fprintf( pFile, "FALSE\n" );
		fprintf( pFile, "merced < merc2d: " ); if( palabraMenor( "merced", "merc2d" ) ) fprintf( pFile, "TRUE\n" ); else fprintf( pFile, "FALSE\n" );
	fclose( pFile );

	pFile = fopen( archivoCaso1, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO PALABRA-FORMATEAR\n", pFile );			
		palabraFormatear( pVacia, cifrar_diabolico );
		char p1[] = "666hOlA777";
		fprintf( pFile, "%s\n", p1 );
		palabraFormatear( p1, cifrar_diabolico );
		fprintf( pFile, "%s\n", p1 );
	fclose( pFile );

	pFile = fopen( archivoCaso1, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO PALABRA-IMPRIMIR\n", pFile );			
		char p2[] = "palabraAImprimir";
		palabraImprimir( p2, pFile );
		palabraImprimir( pVacia, pFile );
	fclose( pFile );

	pFile = fopen( archivoCaso1, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO PALABRA-COPIAR\n", pFile );			
		char *porig = palabraCopiar( "palabraACopiar" );
		char *pcopia = palabraCopiar( porig );
		palabraImprimir( porig, pFile );
		palabraImprimir( pcopia, pFile );
		porig[3] = 'X';
		pcopia[6] = 'W';
		palabraImprimir( porig, pFile );
		palabraImprimir( pcopia, pFile );
		char *potracopia = palabraCopiar( pVacia );
		palabraImprimir( potracopia, pFile );
		free( porig );	
		free( pcopia );
		free( potracopia );	
	fclose( pFile );

	pFile = fopen( archivoCaso1, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO INSERTAR-ORDENADO y ORACION-IMPRIMIR\n", pFile );			
	fclose( pFile );
		insertarOrdenado( A, palabraCopiar( "hola" ), palabraMenor );
		oracionImprimir( A, archivoCaso1, palabraImprimir );

	pFile = fopen( archivoCaso1, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO LONGITUD-MEDIA, ORACION-CREAR y ORACION-BORRAR\n", pFile );
		lista *B = oracionCrear();
		fprintf( pFile, "longitudMedia: %2.5f\n", longitudMedia( B ) );
		oracionBorrar( B );					
		fprintf( pFile, "longitudMedia: %2.5f\n", longitudMedia( A ) );
	fclose( pFile );

	pFile = fopen( archivoCaso1, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO PALABRA-FILTRAR\n", pFile );			
	fclose( pFile );
		filtrarPalabra( A, palabraMenor, "quilo" );
		oracionImprimir( A, archivoCaso1, palabraImprimir );
		filtrarPalabra( A, palabraMenor, "alo" );
		oracionImprimir( A, archivoCaso1, palabraImprimir );	

	pFile = fopen( archivoCaso1, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO MENSAJE DIABOLICO\n", pFile );			
	fclose( pFile );
		insertarOrdenado( A, palabraCopiar( p1 ), palabraMenor );
		descifrarMensajeDiabolico( A, archivoCaso1, palabraImprimir );	
		lista *C = oracionCrear();
		descifrarMensajeDiabolico( C, archivoCaso1, palabraImprimir );
		oracionBorrar( C );					
		
	oracionBorrar( A );	
}

void caso2Elementos() {
	FILE *pFile; lista* A = oracionCrear();

	pFile = fopen( archivoCaso2, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO INSERTAR-ORDENADO y ORACION-IMPRIMIR\n", pFile );			
	fclose( pFile );
		insertarOrdenado( A, palabraCopiar( "Agustina" ), palabraMenor );
		insertarOrdenado( A, palabraCopiar( "Abelu" ), palabraMenor );
		oracionImprimir( A, archivoCaso2, palabraImprimir );

	pFile = fopen( archivoCaso2, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO LONGITUD-MEDIA\n", pFile );
		fprintf( pFile, "longitudMedia: %2.5f\n", longitudMedia( A ) );
	fclose( pFile );

	pFile = fopen( archivoCaso2, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO PALABRA-FILTRAR\n", pFile );			
	fclose( pFile );
		filtrarPalabra( A, palabraMenor, "Adrian" );
		oracionImprimir( A, archivoCaso2, palabraImprimir );
		filtrarPalabra( A, palabraMenor, "Abel" );
		oracionImprimir( A, archivoCaso2, palabraImprimir );
		insertarOrdenado( A, palabraCopiar( "Juana" ), palabraMenor );
		insertarAtras( A, palabraCopiar( "Ana" ) );
		oracionImprimir( A, archivoCaso2, palabraImprimir );
		filtrarPalabra( A, palabraIgual, "Ana" );
		oracionImprimir( A, archivoCaso2, palabraImprimir );
		filtrarPalabra( A, palabraIgual, "Juana" );
		oracionImprimir( A, archivoCaso2, palabraImprimir );


	pFile = fopen( archivoCaso2, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO MENSAJE DIABOLICO\n", pFile );			
	fclose( pFile );
		insertarOrdenado( A, palabraCopiar( "hola1" ), palabraMenor );
		insertarOrdenado( A, palabraCopiar( "hola2" ), palabraMenor );
		descifrarMensajeDiabolico( A, archivoCaso2, palabraImprimir );	
		lista *C = oracionCrear();
		descifrarMensajeDiabolico( C, archivoCaso2, palabraImprimir );
		oracionBorrar( C );					

	pFile = fopen( archivoCaso2, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO ORACION-BORRAR\n", pFile );			
	fclose( pFile );
		oracionImprimir( A, archivoCaso2, palabraImprimir );
		oracionBorrar( A );	
}

void casoNElementos() {

	FILE *pFile;

	pFile = fopen( archivoCasoN, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO INSERTAR-ORDENADO y ORACION-IMPRIMIR\n", pFile );			
	fclose( pFile );
		lista* HablandoOriginal = getlistaComun();
		oracionImprimir( HablandoOriginal, archivoCasoN, palabraImprimirCatedra );
		pFile = fopen( archivoCasoN, "a" ); fputs( "...\n", pFile ); fclose( pFile );
		lista* HablandoOrdenada = getlistaMixta( 500 );
		oracionImprimir( HablandoOrdenada, archivoCasoN, palabraImprimir );

	pFile = fopen( archivoCasoN, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO LONGITUD-MEDIA\n", pFile );
		fprintf( pFile, "longitudMedia: %2.5f\n", longitudMedia( HablandoOriginal ) );
		fprintf( pFile, "longitudMedia: %2.5f\n", longitudMedia( HablandoOrdenada ) );
	fclose( pFile );

	pFile = fopen( archivoCasoN, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO PALABRA-FILTRAR\n", pFile );			
	fclose( pFile );
		filtrarPalabra( HablandoOriginal, palabraMenor, "engranaje" );
		oracionImprimir( HablandoOriginal, archivoCasoN, palabraImprimirCatedra );
		pFile = fopen( archivoCasoN, "a" ); fputs( "...\n", pFile ); fclose( pFile );
		filtrarPalabra( HablandoOrdenada, palabraDistinta, "y" );
		filtrarPalabra( HablandoOrdenada, palabraDistinta, "Y" );
		filtrarPalabra( HablandoOrdenada, palabraDistinta, "a" );
		filtrarPalabra( HablandoOrdenada, palabraDistinta, "al" );
		filtrarPalabra( HablandoOrdenada, palabraDistinta, "como" );
		filtrarPalabra( HablandoOrdenada, palabraDistinta, "con" );
		filtrarPalabra( HablandoOrdenada, palabraDistinta, "de" );
		filtrarPalabra( HablandoOrdenada, palabraDistinta, "del" );
		filtrarPalabra( HablandoOrdenada, palabraDistinta, "el" );
		filtrarPalabra( HablandoOrdenada, palabraDistinta, "en" );
		filtrarPalabra( HablandoOrdenada, palabraDistinta, "este" );
		filtrarPalabra( HablandoOrdenada, palabraDistinta, "estubo" );
		filtrarPalabra( HablandoOrdenada, palabraDistinta, "la" );
		filtrarPalabra( HablandoOrdenada, palabraDistinta, "las" );
		filtrarPalabra( HablandoOrdenada, palabraDistinta, "los" );
		filtrarPalabra( HablandoOrdenada, palabraDistinta, "que" );
		oracionImprimir( HablandoOrdenada, archivoCasoN, palabraImprimir );

	pFile = fopen( archivoCasoN, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO LONGITUD-MEDIA\n", pFile );
		fprintf( pFile, "longitudMedia: %2.5f\n", longitudMedia( HablandoOriginal ) );
		fprintf( pFile, "longitudMedia: %2.5f\n", longitudMedia( HablandoOrdenada ) );
	fclose( pFile );

	pFile = fopen( archivoCasoN, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO MENSAJE DIABOLICO\n", pFile );			
	fclose( pFile );
		lista* HablandoCifrada = getlistaInversa();
		descifrarMensajeDiabolico( HablandoCifrada, archivoCasoN, palabraImprimirCatedra );	
		pFile = fopen( archivoCasoN, "a" ); fputs( "...\n", pFile ); fclose( pFile );

	pFile = fopen( archivoCasoN, "a" );
		fputs( ">>>>>>>>>>>>>>>> PROBANDO ORACION-BORRAR\n", pFile );			
	fclose( pFile );
		oracionBorrar( HablandoOriginal );	
		oracionBorrar( HablandoOrdenada );	
		oracionBorrar( HablandoCifrada );
}


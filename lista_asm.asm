	extern fprintf
	extern malloc
	extern free
	extern fopen
	extern fclose
; PALABRA
	global palabraLongitud
	global palabraMenor
	global palabraFormatear
	global palabraImprimir
	global palabraCopiar
	
; LISTA y NODO
	global nodoCrear
	global nodoBorrar
	global oracionCrear
	global oracionBorrar
	global oracionImprimir

; AVANZADAS
	global longitudMedia
	global insertarOrdenado
	global filtrarPalabra
	global descifrarMensajeDiabolico

; YA IMPLEMENTADAS EN C
	extern palabraIgual
	extern insertarAtras

; /** DEFINES **/    >> SE RECOMIENDA COMPLETAR LOS DEFINES CON LOS VALORES CORRECTOS
	%define NULL 		0
	%define TRUE 		1
	%define FALSE 		0

	%define LISTA_SIZE 	    	 8
	%define OFFSET_PRIMERO 		 0

	%define NODO_SIZE     		 16
	%define OFFSET_SIGUIENTE   	 0
	%define OFFSET_PALABRA 		 8


section .rodata


section .data

    new_line: db 10, 0
    append_file: db 'a', 0

section .text
;/** FUNCIONES DE PALABRAS **/
;-----------------------------------------------------------

	; unsigned char palabraLongitud( char *p );
	palabraLongitud:
		; RDI puntero a la palabra
						xor r8, r8 ; index
						xor r9, r9
			cPalabraLongitud:	
						mov r9b, [rdi + r8]
						inc r8
						cmp r9b, NULL ; 0 es fin de string
						jnz cPalabraLongitud

						sub r8, 1 ; resto 1 para que no cuente el fin de string
						mov rax, r8
						ret


	; bool palabraMenor( char *p1, char *p2 );
	palabraMenor:
		; RDI primer puntero a la primer palabra
		; RSI segundo puntero a la segunda palabra
						xor r10, r10
						xor r11, r11
						xor r8, r8 ; index
			cPalabraMenor:
						mov r10b, [rdi + r8] 
						mov r11b, [rsi + r8]
						inc r8
						; si alguna palabra llego a su fin salto
						cmp r10b, NULL
						jz finalPalabra
						cmp r11b, NULL
						jz finalPalabra

						cmp r10b, r11b
						jz cPalabraMenor
						jl esMenor
						; si no es menor, ni igual, entonces debe ser mayor
						jmp esMayor
			finalPalabra:
						cmp r10b, r11b
						; si son iguales o la primer palabra es menor 
						; (implica que la segunda no llego a su fin)
						; entonces devuelvo false
						jle esMayor
			esMenor:
						mov rax, TRUE
						ret
			esMayor:
						mov rax, FALSE
						ret


	; void palabraFormatear( char *p, void (*funcModificarString)(char*) );
	palabraFormatear:
						lea r8, [rsi]
						sub rsp, 8
						call r8
						add rsp, 8
						ret


	; void palabraImprimir( char *p, FILE *file );
	palabraImprimir:
						; escribo palabra
						xchg rdi, rsi
						push rdi
						call fprintf
						pop rdi
						;escribo new line
						sub rsp, 8
						mov rsi, new_line
						call fprintf
						add rsp, 8
						ret

	; char *palabraCopiar( char *p );
	palabraCopiar:
						; rdi palabra a copiar
						xor r8, r8 ; contador
						xor r9, r9 ; copia de palabra
						xor r10, r10 ; letra actual
						xor r11, r11 ; tamaño palabra
						; obtengo tamaño de palabra para saber
						; cuanto debo reservar
						sub rsp, 8
						call palabraLongitud
						add rsp, 8
						mov r11, rax
						add r11, 1 ; sumo el final de string
			
						
						; reservo memoria para la copia
						push rdi
						mov rdi, r11
						call malloc
						pop rdi
						mov r9, rax


			cPalabraCopiar:			
						; copio letra por letra
						mov r10b, [rdi + r8]
						mov [r9 + r8], r10b
						inc r8
						cmp r10b, 0	
						jnz cPalabraCopiar

						mov rax, r9
						ret


;/** FUNCIONES DE LISTA Y NODO **/
;-----------------------------------------------------------

	; nodo *nodoCrear( char *palabra );
	nodoCrear:
						; reservo memoria para el nodo
						push rdi
						mov rdi, NODO_SIZE
						call malloc
						pop rdi

						lea r11, [rdi]
						mov [rax + OFFSET_PALABRA], r11
						mov qword [rax + OFFSET_SIGUIENTE], NULL

						; rax ya tiene el puntero ;)
						ret

	; void nodoBorrar( nodo *n );
	nodoBorrar:	
						; primero libero la palabra
						; obtengo direccion de memoria al puntero de la palabra
						mov r8, [rdi + OFFSET_PALABRA]
						push rdi
						mov rdi, r8
						call free
						pop rdi

						; rdi ya tiene el puntero al nodo
						sub rsp, 8
						call free
						add rsp, 8

						ret


	; lista *oracionCrear( void );
	oracionCrear:
						; reservo memoria para la lista
						mov rdi, LISTA_SIZE
						sub rsp, 8
						call malloc
						add rsp, 8

						mov qword [rax + OFFSET_PRIMERO], NULL 

						; rax ya tiene el puntero ;)
						ret
		

	; void oracionBorrar( lista *l );
	;	%define NODO_SIZE     		 16
	; %define OFFSET_SIGUIENTE   	 0
	; %define OFFSET_PALABRA 		 8
	oracionBorrar:
						; puntero al primer nodo
						mov r8, [rdi + OFFSET_PRIMERO]
			cOracionBorrar:			
						cmp r8, NULL
						jnz liberarNodo
						jmp liberarLista
			liberarNodo:
						mov r9, [r8 + OFFSET_SIGUIENTE] ; puntero al siguiente
						push rdi
						push r9
						sub rsp, 8
						mov rdi, r8 ; puntero que quiero liberar
						call nodoBorrar
						add rsp, 8
						pop r9
						pop rdi
						mov r8, r9
						jmp cOracionBorrar
			liberarLista:
						; rdi posee la direccion de mem a la lista
						sub rsp, 8
						call free
						add rsp, 8
						ret
						

	; void oracionImprimir( lista *l, char *archivo, void (*funcImprimirPalabra)(char*,FILE*) );
	oracionImprimir:
						push rdi
						push rsi
						push rdx
						mov rdi, rsi
						mov rsi, append_file
						call fopen
						pop rdx
						pop rsi
						pop rdi


						mov r8, rax ; puntero al archivo :D
						mov r9, [rdi + OFFSET_PRIMERO]
			cOracionImprimir:		
						cmp r9, NULL
						jnz imprimeNodo					
						jmp fin
			imprimeNodo:
						mov r10, [r9 + OFFSET_PALABRA]
						push rdi
						push rsi
						push r9
						push r8
						push rdx
						push rax
						sub rsp, 8
						mov rdi, r10
						mov rsi, r8
						call rdx
						add rsp, 8
						pop rax
						pop rdx
						pop r8
						pop r9
						pop rsi
						pop rdi
						mov r9, [r9 + OFFSET_SIGUIENTE]
						jmp cOracionImprimir
			fin:
						mov rdi, rax
						sub rsp, 8
						call fclose
						add rsp, 8
						ret
						; TODO: cuanto esta vacia la lista poner oracionvacia

;/** FUNCIONES AVANZADAS **/
;-----------------------------------------------------------

	; float longitudMedia( lista *l );
	longitudMedia:
		; COMPLETAR AQUI EL CODIGO

	; void insertarOrdenado( lista *l, char *palabra, bool (*funcCompararPalabra)(char*,char*) );
	insertarOrdenado:
		; COMPLETAR AQUI EL CODIGO

	; void filtrarAltaLista( lista *l, bool (*funcCompararPalabra)(char*,char*), char *palabraCmp );
	filtrarPalabra:
		; COMPLETAR AQUI EL CODIGO

	; void descifrarMensajeDiabolico( lista *l, char *archivo, void (*funcImpPbr)(char*,FILE* ) );
	descifrarMensajeDiabolico:
		; COMPLETAR AQUI EL CODIGO

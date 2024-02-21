(INICIO)
@68    //Tecla D
D=A
@KBD  // Se refiere al espacio de memoria 24576 een el teclado
D=D-M
@Loop
D;JEQ

@ //Tecla G, 
D=A
@KBD
D=D-M 
@Loop  // Bucle para pintar en blanco
D;JEQ

(BorrarPantalla)
@SCREEN //Se refiere al espacio de memoria 16384 para la pantalla
M=0
@INICIO
0;JMP

(CocinandoBucle)
@24576
D=A 

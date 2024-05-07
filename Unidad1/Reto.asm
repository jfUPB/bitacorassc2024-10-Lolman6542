(Inicio)
@80 // Tecla P
D=A
@KBD // Se refiere al espacio memoria 24576 en el teclado
D=D-M
@CocinandoBucle
D;JEQ
@90 // Tecla Z
D=A
@KBD
D=D-M
@CocinandoBucleA // Bucle para pintar en blanco
D;JEQ

(BorrarPantalla)
@SCREEN // Se refiere al espacio de memoria 16384 para la pantalla
M=0
@Inicio
0;JMP

(PintarNegro)
@SCREEN // Se refiere al espacio que pintara en la memoria 16384 para la pantalla
M=-1
@Inicio // No necesitamos volver al inicio, ya que queremos que el cambio sea permanente.
0;JMP

(CocinandoBucle)
@24576
D=A
@suma // Revisa si llego al final de bucle
M=D
@16384 // Se guarda en SCREEN
D=A
@variable // Posicion del bit de la pantalla
M=D

(PintarNegroBucle)
@variable
A=M
M=-1
@variable
M=M+1
D=M
@suma
D=M-D
@PintarNegroBucle
D;JGT
@Inicio
0;JMP

(CocinandoBucleA)
@24576
D=A
@suma
M=D
@16384
D=A
@variable
M=D

(BorrarPantallaBucle)
@variable
A=M
M=0
@variable
M=M+1
D=M
@suma
D=M-D
@BorrarPantallaBucle
D;JGT // Vuelve al inicio
@Inicio
0;JMP
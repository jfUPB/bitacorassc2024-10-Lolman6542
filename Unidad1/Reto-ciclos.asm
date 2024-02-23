(INICIO)
    @80    // Tecla P
    D=A
    @KBD   // Se refiere al espacio de memoria 24576 en el teclado
    D=D-M
    @LoopP
    D;JEQ

    @90 // Tecla Z 
    D=A
    @KBD
    D=D-M 
    @LoopZ  // Bucle para pintar en blanco
    D;JEQ

(BorrarPantalla)
    @SCREEN // Se refiere al espacio de memoria 16384 para la pantalla
    M=0
    @INICIO
    0;JMP

(PintarNegro)
    @SCREEN // Se refiere al espacio que pintara en la memoria 16384 para la pantalla
    M=1
    @INICIO
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

(BorrarBucle)
    @variable
    A=M 
    M=0 
    @variable
    M=M+1
    D=M 
    @suma
    D=M-D

    @BorrarBucle
    D;JGT     // Vuelve al inicio
    @INICIO
    0;JMP

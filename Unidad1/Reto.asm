(Inicio)
@80
D=A
@KBD
D=D-M
@preparandoBucle
D;JEQ

@90
D=A
@KBD
D=D-M
@preparandoBuclee
D;JEQ

(PintarBlanco)
@SCREEN
M=0
@Inicio
0;JMP

(PintarNegro)
@SCREEN
M=-1
@Inicio
0;JMP


(preparandoBucle)

@24576
D=A
@suma
M=D
@16384
D=A
@variable
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

(preparandoBuclee)
@24576
D=A
@suma
M=D
@16384
D=A
@variable
M=D

(PintarBlancoBucle)
@variable

A=M
M=0
@variable
M=M+1
D=M
@suma
D=M-D

@PintarBlancoBucle
D;JGT
@Inicio
0;JMP

# Bitácora de aprendizaje - Unidad 1. Arquitectura del Comuputador

## Semana 2 Lunes 29 de enero

Para este principio de la primera unidad, nos encargaremos en estudiar en cómo funciona un computador digital moderno entendiendo 
cómo hace este para ejecutar un programa en lenguaje ensamblador y la relación entre el lenguaje ensamblador y código de alto nivel. 

Al comienzo habra Reto que habra que ir haciendo al lapso de esta semana que consiste en construir una aplicación
que debe funcionar en ciclo infinito en CPUEmulator.bat y que esta imprima en la pantalla dependiendo de la tecla que aprietes
segun tu primera y ultima letra de tu apelliddo.

Es recomendable el leer o ver videos tutoriales para empezar hacer el reto que propone el profesor, dado que hay que demostrar en 
que entendimos ciertos conceptos para poder seguir avanzado el reto. No hay que responder todas las preguntas que plantea la unidad, 
pero seria lo recomendable que se evidencia algo del trabajo. Tambien podemos empezar a tirar codigo y crear el ejecutable ex15.asm
en el GitHub.

## Investigación - Preguntas Guía Iniciales

1.  Selecciona una función booleana. Representa dicha operación de dos maneras diferentes. ¿Pudiste observar en el video esas dos maneras?
  
 R/= Como tal podremos usar una tabla de verdad (Verdadero o Falso) que tambien podriamos decir que es:

 Sí   o  No
 On   o  Off
 True o  False 

Junto a las expresiones:

- AND: La salida es verdadera solo si todas las variables son verdaderas.

                             Z . X . Y

- OR: La salida es verdadera si al menos una de las variables es verdadera.

                             Z + X + Y

- XOR: La salida es verdadera si exactamente una de las variables es verdadera.

                             Z ⊕ X ⊕ Y

- NOT: La salida es el inverso de la entrada.

                             _ _ _
                             Z X Y            

Para el primera caso usara la tabla de la verdad junto la expresion AND:

![image](../assets/301288286-b7bec477-92dc-4f6f-8a91-143236d7700c.png)

Ahora lo usaremos junto el Logic Gate junto a la expresión AND:

 ``` c
          _________
          |         \
   x ----|          AND ----\
          |_________/       \
                             AND ---- Output
          _________         /
          |         \       /
   y ----|          AND --/
          |_________/
                             
          _________
          |         \
   z ----|          AND
          |_________/

```


## Micro sesión de Cierre
Hasta el momento ando revisando la primera pregunta y en ver de que va las expresiones Boolenas asumo que la primera pregunta me pide 
en que operaciones se puede represantar estas, se de dos que son expresión booleana y una tabla de verdad, como tal se que los valores Booleanos
siempre sera DOS fijos, ni a medias o nitades, siempre seran un SI o NO, Verdadero o Falso y asi sucesivamente. Debo de repasar este tema y pedirle
ayuda a ChatGPTE en enteder mas este tema. Dejare esta reflexion por ahora y voy ver si en el transcurso de la semana avanzo en algo.....

## Semana 2 Miercoles 31 de enero

2. Inventa una tabla de verdad de tres entradas y una salida. ¿Cuál es la función booleana que la representa?

R/=  Inventamos una función que devuelve verdadero (1) si al menos dos de las tres entradas son verdaderas (1), y falso (0) en cualquier otro caso.

   ## Función => (x,y,z)=(x⋅y)+(x⋅z)+(y⋅z)

   Esta función representa la lógica "al menos dos de las tres son verdaderas". Ahora, podemos construir la tabla de verdad:

   ![image](../assets/301295863-5a3a2d15-7df4-4804-9252-b3a3a33b48dd.png)

Esta tabla de verdad representa la función booleana que hemos definido, donde la salida es verdadera (1) 
si al menos dos de las tres entradas son verdaderas (1), y falso (0) en cualquier otro caso.

## Micro sesión de Cierre
Hoy por hoy, me dedique a completar el primer punto dado que lo tenia incompleto del primer día.
Tambien me dedique a en hacer la pregunta 2 y ver los videos 1.2 y 1.3. De lo que tengo entendido es que una
Compuerta Logica es un componente electroinico encargado de operar entradas para producir una señal de salida
que en si es una tabla de verdad (¿creo?). Tambien el profesor me colaboro con unos ajustes en como crear un repositorio
privado y en como agregar colaboradores a este. Resulta que mi error era que habia ingresado con otro correo.
Debo de repasar estos videos de la actividades que coloque y apartar dudas para la proxima clase.

## Semana 2 Domingo 4 de Febreo - Día Autonomo

3. ¿Como seria el circuto logico que representa la función booleana?
   
R/= Función(x,y,z)=(x⋅y)+(x⋅z)+(y⋅z) con compuertas lógicas, podemos construir el circuito utilizando compuertas AND, OR y NOT. Aquí está el diseño del circuito: 

``` c
          _________
         |         \
    x ---|          AND ----\
         |_________/       \
                              \
    x ---|          AND ----\  \
         |_________/       \  OR --- Output
                              /
    y ---|          AND ----/  /
         |_________/       /
                             /
    y ---|          AND ---/
         |_________/
                             
    z ---|          AND
         |_________/
    z ---|

```

En este circuito:
-Las entradas x, y , z están conectadas a puertas lógicas AND individuales.

- Las salidas de estas puertas AND se conectan a puertas lógicas OR, que realizan la operación de suma lógica (x⋅y)+(x⋅z)+(y⋅z).

- La salida de la puerta OR es la salida del circuito.

- Este circuito implementa la función booleana deseada utilizando compuertas lógicas estándar.

4.  ¿Cuántos números diferentes puede representar un computador de 8 bits?
   
R/= Un computador de 8 bits puede representar 2^8 = 256 numeros diferentes.
Lo recomendable no usar todos esos valores en solo los numeros positivos, 
mas bien usar la mitad de este en 127 numeros positivos, 0 y 127 numeros negativos.   

5. ¿Cuál es la representación binaria del número en 8 bits del número 128?

R/= Seria 128 = 1 0 0 0 0 0 0 0 0 

![image](https://github.com/jfUPB/bitacorassc2024-10-Lolman6542/assets/127360762/35d80fa9-8b20-417e-9252-8fdc98b34b90)

6. ¿Qué es un overflow en una suma binaria? inventa un ejemplo.

R/= Un overflow en una suma binaria, ocurre cuando los ultimos digitos de la operación se suma y 
dan como resultado un 1 mas para agregar. En este caso lo mejor es que simplemente  no hagamos nada con el, 
y nos que demos como quedo el resultado final.

         1 0 1 0 1 1 0 1
       + 1 1 0 1 1 1 1 1
       ___________________ 
         1 0 0 0 1 1 0 0 

Al final de la operacion me quedaba un 1 demas por agregar, pero no se puede por que no hay nada que hacer por el.

## Micro sesión de Cierre
Al fin logre entender en si (creo), en como funciona o se convierte un numero entero a numero binario, 
el cual conciste en dividir el numero entero por dos, y seguir diviendo el resultado de la operación anterior
hasta quede 1 (1/2 = 0), despues con los resultados sacados de la abstración de numero, se usan para crear el numero binario,
estos siempre se lee de manera inversa, es decir el ultimo resultado de la abstración es el primero que se lee y el primero es 
ultimo en ser leido. Recuerda que si el numero es divisible por dos exacto el resultado en la abstracion es 0 y si no es divisible
exacto sera un 1. y claro junto a la suma Overflow, solo que creo que varia segun el numero de bits.

En lo demas creo que voy entendiendo de a poquito, aun asi me parece un gran paso en haber captado en como se crean los 
numeros binarios, espero que puede seguir entendiendo el tema hasta que le coja el tiro.

----------------------------------------------------------------------------------------------------------------------------------------

## Semana 3 Lunes 5 de febreo

![image](https://github.com/jfUPB/bitacorassc2024-10-Lolman6542/assets/127360762/459a6f15-ecdb-4cf0-b5bd-814f037f87d8)

Como tal hoy nos dedicamos en trabajar en un programa o mas bien un videojuego rompecabeza, llamado 
Silicon Zeroes, el cual replica la construcción compleja de componentes electronicos/digitales como adders, latches
y multiplexers.  

Un sistema digital es un conjunto de elementos binarios relacionados entre si de alguna manera. Se
distinguen dos tipos de variables en un sistema digital. Las variables de entrada y las variables de salida que
dependen de las de entrada. Cuando cada combinación de las variables (Vector de entrada) de entrada se corresponde con una y sólo
una combinación de las variables de salida (Vector de salida), se trata de un sistema combinacional. Dicho de
otra manera, siempre que se repita un conjunto de valores de las variables de entrada, se repetirá la salida.

Cuando las funciones lógicas son muy complejas no siempre el diseño basado en la minimización y
posterior implementación con compuertas lógicas, es el más adecuado. Estos bloques funcionales MSI, si
bien a veces tienen fines específicos, pueden aplicarse a la implementación de funciones lógicas de muchas
variables. Las ventajas caen en la disminución de los CI necesarios, del tiempo de diseño, del número de
conexiones externas y facilita el mantenimiento.

## Codificadores
- Permiten codificar las líneas de entrada. Generalmente codifican en binario o BCD. 
- Si ninguna entrada está activa las salidas son todas cero, igual que si estuviera activada la entrada D0.
- Para evitar este problema los codificadores cuentan con una salida adicional que indica la ausencia de activación
  de las entradas.
- Por último los codificadores suelen contar con una entrada de habilitación. Cuando el chip está activado
  es válida la tabla de verdad, si no lo está el chip no funciona.
  
## Decodificadores
- Son Combinacionales que poseen n entradas y m salidas.
- El orden adecuado de la salida se activa cuando la codificación correspondiente se inyecta ala entrada.
- Generalmente son binarios o BCD. En caso de un decodificador binario si tiene n entradas poseerá m = 2n salidas. 
  Así un decodificador realiza lo opuesto a un codificador.

 ## Multiplexores
 - Disponen de m = 2n líneas de entrada (canales), una línea de salida y n líneas de selección. En función
   de las líneas de selección determina qué entrada aparece en la salida.
 - Los multiplexores, además de multiplexar, pueden usarse eficazmente para implementar funciones lógicas.
 - Para realizar multiplexores de muchos canales pueden combinarse diferentes multiplexores.

## Micro sesión de cierre
Dado el caso con el videojuego de Silicon Zeroes y en sí el tema, busca que las personas entiendan 
en como los componentes electronicos y digitales funcionan en los gadgets/dispositivos, junto 
en como implementarlos en estos, para que se puede ahorrar espacio/almacenamiento e incluso
en reducir o simplificar el proceso o tarea que se este ejecutando, para que le tome tanto el 
CPU en hacer.
Ya por aparte con el mismo videojuego (recalco que me descargue una demo) logre llegar hasta el desafio "Memsum"
el cual me costo en entender, hasta que cai en cuenta que "read" se encargaba de imprimir los valores que estaban
guardados en memoria, por lo tanto debia de usar el resultado de read y sumarlo con el "adder" para asi poder hallar el 
numero 7 que me pedian. En general no parece que se duro en entender (creo), mas que todo en como se lee. Recomendable hacer mas de estos ejercicios.

### Unidad 1: Miercoles 7 de Febrero

## Micro-Sesión 1: Apertura

Lo que hizimos al principio 
````
## SEMANA 3
###Unidad 1: Miercoles Febrero 7
#### Micro-Sesión 1 :Apertura
#### Micro-Sesión 2: Cierre

````c

## Semana 3 ???? (en proceso) - Día Autonomo


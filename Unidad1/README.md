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

----------------------------------------------------------------------------------------------------------------

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

-----------------------------------------------------------------------------------------------------------------

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

5.
   

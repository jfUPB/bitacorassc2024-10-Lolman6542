# Bitácora de aprendizaje

## ¿Cómo voy?

- [ ] Terminé la fase de investigación. 
- [ ] Terminé la fase de aplicación.
- [ ] Terminé la fase de compartir.

## Compartir

### Resultado de aprendizaje 1 (RAE1)

> Muestra que tu aplicación cumple con todos los requisitos establecidos.

> Explicas cómo solucionaste cada requisito de la aplicación.

### Resultado de aprendizaje 2 (RAE2)

> Muestras cómo probaste cada requisito por separado.

> Muestras cómo probaste que la aplicación funciona integrada, con todos los requisitos.

## Proceso

En cada sesión vas a realizar experimentos para explorar a profundidad los conceptos. También podrás 
implementar requisitos de la aplicación, resolver algún error, implementar una prueba o probar 
la integración de varias partes. Cada una de estas actividades las vas a reportar en tu bitácora
usando la siguiente plantilla:

``` markdown
> 1. ¿Qué tipo de actividad estás evidenciando?
> 2. Describe la actividad y cuál es el propósito de esta y/o la pregunta que quieres investigar.
> 3. Todas las actividades deben estar soportadas por código fuente. Vas a inidicar el commit que tiene
>    el resultado final de la actividad.
> 4. ¿Cuáles es el resultado de la actividad?
> 5. ¿Qué aprendiste de la actividad?
```

> :warning: **MUY IMPORTANTE**
> 
> Cada sesión debe tener al menos dos actividades para ganar los puntos de la sesión. La actividad debe estar completa,
> es decir, debe tener los 5 puntos de la plantilla realizados correctamente.

### Semana 14

#### Sesión 1


Ahora mismo estamos resolviendo los primeros ejercicios de seccion de Investigación
de la Unidad 4, por lo tanto se dara como la resolucion algunos ejercios tanto aca
en la bitcara, como en el espacio de trabajo CodeSpace a futuro.

Ejercicio 1: ¿Qué es un sistema operativo?

Es el software principal que coordina y controla todas las actividades de una computadora o dispositivo electrónico, facilitando su uso y asegurando su funcionamiento eficiente y seguro.

Ejercicio 2:

¿Cuál es la diferencia entre un programa y un proceso?

- Un programa es el conjunto de instrucciones y datos almacenados en el sistema, mientras que un proceso es una instancia en ejecución de ese programa que tiene recursos asignados y está siendo gestionado por el sistema operativo.

¿Puedo tener múltiples procesos corriendo el mismo programa?

- Sí, es posible tener múltiples procesos ejecutando el mismo programa al mismo tiempo. Este escenario se conoce como "multiprocesamiento" o "multiprogramación". 

En un sistema operativo que admite multiprocesamiento, como la mayoría de los sistemas modernos, cada vez que un programa se ejecuta, el sistema operativo crea un nuevo proceso para ese programa. Esto significa que puedes tener varias instancias de un programa en ejecución al mismo tiempo, cada una como un proceso independiente con su propio espacio de memoria y recursos asignados.

- ¿Para qué sirve el stack de un proceso?

El stack de un proceso es esencial para la gestión eficiente de llamadas a funciones, variables locales y retorno de funciones en un programa. Proporciona un mecanismo ordenado para la ejecución de funciones y la gestión de datos locales dentro de un proceso.

- ¿Para qué sirve el heap de un proceso?

Es una región de memoria dinámica utilizada para asignar memoria de forma dinámica durante la ejecución del programa, permitiendo la gestión flexible de estructuras de datos, objetos y variables que no tienen un tamaño fijo en tiempo de compilación.

- ¿Qué es la zona de texto de un proceso?

Almacenan las instrucciones ejecutables del programa, es de solo lectura, puede ser compartida entre procesos y está protegida para garantizar la integridad y seguridad del código ejecutable.

- ¿Dónde se almacenan las variables globales inicializadas?

En el segmento de datos estáticos Y Heap. Las variables globales inicializadas pueden almacenarse en diferentes áreas de memoria según su alcance y tipo. Por ejemplo, las variables globales estáticas se almacenan en el segmento de datos estáticos, mientras que las variables globales no estáticas se pueden almacenar en el heap o en otras áreas de memoria según las necesidades del programa.

- ¿Dónde se almacenan las variables globales no inicializadas?

Segmento de datos no inicializados (BSS), reserva para variables globales y estáticas que no se inicializan explícitamente en el código. El Stack en algunos compiladores y sistemas operativos pueden almacenar temporariamente las variables globales no inicializadas en el stack durante la inicialización del programa. Heap En ciertos casos, especialmente cuando las variables globales no inicializadas son objetos o estructuras de datos complejas, pueden ser almacenadas en el heap.

- ¿Cuáles son los posibles estados de un proceso en general? Ten en cuenta que esto varía entre sistemas operativos.

Listo (Ready): El proceso está listo para ser ejecutado por el procesador, pero aún no se le ha asignado tiempo de CPU. Está en espera de que el planificador de procesos lo seleccione para la ejecución.

Ejecución (Running): El proceso está siendo ejecutado por la CPU en este momento. Solo un proceso puede estar en este estado en un momento dado en un sistema monoprocesador, mientras que en sistemas multiprocesador, varios procesos pueden estar en estado de ejecución simultáneamente en diferentes núcleos.

Bloqueado (Blocked o Waiting): El proceso está esperando que ocurra algún evento, como la finalización de una operación de entrada/salida (E/S), la liberación de un recurso, o la recepción de una señal, para poder continuar su ejecución. Mientras está bloqueado, el proceso no utiliza la CPU.

Listo suspendido (Ready Suspended): El proceso está listo para ejecutarse, pero se encuentra en un estado de suspensión temporal. Esto puede ocurrir debido a que se ha pausado manualmente, por decisión del sistema operativo para priorizar otros procesos, o por otras razones.

Bloqueado suspendido (Blocked Suspended): Similar al estado de bloqueado, pero el proceso está suspendido temporalmente mientras espera la ocurrencia de un evento específico. Está en espera y suspendido simultáneamente.

Terminado (Terminated): El proceso ha finalizado su ejecución de manera exitosa o ha sido finalizado por el sistema operativo debido a un error. En este estado, se liberan los recursos que estaba utilizando el proceso.



Ejercicio 3: Concepto de hilo


Es una unidad de ejecución dentro de un proceso que permite la multitarea a nivel de proceso, mejora la eficiencia y la concurrencia en los programas, y facilita la comunicación y la sincronización entre diferentes partes del código.

Ahora lo que hizimos fue resolver las preguntas de los ejercicios 1, 2 y 3. Y como tal el proposito de estas fueron de como La CPU y el sistema operativa de un computador pueden hacer varias tareas, ejecutar programas, tener servicios activos. Gracias a los hilos que ejecutan intrucciones de manera independiente al proceso que se este corriendo.

Los resultados de las actividades fueron las preguntas que fueron resueltas o respondidas e la indagacion de los conceptos.

Dar a conocer en cómo funcionan los programas y procesos en un sistema operativo y a su vez optimizar el rendimiento, resolver problemas rapido y el diseño de Software optimo.


#### Sesión 2

#### Sesión 3

### Semana 15

#### Sesión 1

#### Sesión 2

#### Sesión 3

### Semana 16

#### Sesión 1

#### Sesión 2

#### Sesión 3

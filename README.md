# Hoteles
Trabajo Practico Nº4 - Estructuras, busqueda y ordenamiento

Una prestigiosa cadena de hoteles desea obtener un sistema que le permita gestionar la ocupación de
todos sus hoteles.
Esta cadena, posee 30 destinos en distintas partes del mundo. De cada destino se conoce:

Nombre: string

Descripción: string

País: string

Temporada: char (I | V)

En cada destino, existe un único hotel de 60 habitaciones.

Los datos de cada habitación son:

Número de habitación: entero entre (1 - 60)

Cantidad de ocupantes que puede recibir

Estado: char (D: disponible; O: ocupada)

La cadena desea obtener un sistema que le permita a los empleados del call center gestionar las reservas
del hotel. Para ello cuando un cliente llama, se le solicita el nombre del destino al que quiere viajar. Luego
se le solicita la cantidad de personas que ocuparán la habitación. Con todo esto el sistema deberá buscar la
habitación que se le asignará.

El sistema deberá obtener la primera habitación que se encuentre disponible y luego deberá marcarla como
ocupada informando al usuario el número de habitación.
En caso de no encontrar una habitación que cumpla con las características solicitadas por el cliente, se
deberá mostrar un mensaje que indique lo ocurrido.

El sistema también debe permitir liberar una habitación, para ello el cliente debe indicar el destino y el
número de habitación en la que se encontraba para que el sistema marque la habitación como disponible.
La cadena nos solicita que el sistema presente un menú que permita a los usuarios realizar las acciones
mencionadas.

Se pide:

a. Obtener las estructuras que permitan representar y resolver la situación planteada.

b. Desarrollar una función que permita realizar la reserva de una habitación.

c. Desarrollar una función que permita liberar una habitación.

d. A partir del ingreso de una temporada ("Invierno" o "Verano"), generar un listado que imprima los 3
destinos con mayor ocupación.

Consideraciones y restricciones

1. El conjunto de Destinos se encuentra desordenado

2. Sobre el conjunto de Destinos no se pueden realizar búsquedas secuenciales, excepto para el punto 'd'.

3. Todos los hoteles poseen:

1. 20 habitaciones para 2 personas

2. 20 habitaciones para 4 personas

3. 20 habitaciones para 8 personas

4. La cantidad de personas que ocupen 1 habitación siempre deberá ser menor o igual a la capacidad de
la misma.

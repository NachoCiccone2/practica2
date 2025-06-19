/**
 * Alumno:……………………………….                    Fecha:……………………………
    1) Una agencia de reparto posee dos canales para recibir pedidos, uno es 
    la página web de la empresa y el otro un operador que atiende la línea 
    telefónica. La operatoria es que al finalizar el horario de toma de 
    pedidos (de 6.00hs a 12.00hs), se juntan todos los pedidos por orden 
    de llegada y se genera un listado único con los repartos del día. De 
    cada pedido se tiene la siguiente información:
    • Hora Pedido (hora en formato HHMM)
    • Codigo de cliente (numérico)
    • Tipo de paquete: (1-Liviano / 2-Medio / 3-Pesado)
    • Origen(texto)
    • Destino(texto)

La capacidad de reparto varía según cuántos móviles disponga la empresa en el 
momento y las horas que se dispongan para realizar repartos, por lo cual la 
cantidad máxima de pedidos que puede tener el listado unificado resultará de 
un cálculo: 
Pedidos_Max = Móviles * Horas_Reparto * 3

    a. Definir las estructuras necesarias para el enunciado descrito y para 
    los puntos siguientes:
    b. Realizar codificación de un procedimiento que reciba los pedidos de 
    ambos canales de atención y genere un listado de pedidos unificado a 
    atender y otro de los que no entran en el reparto diario por la capacidad 
    máxima.
    c. Realizar diagrama de un procedimiento que reciba el listado de pedidos 
    a realizar en el día y genere el siguiente listado agrupado por hora del pedido recibido:
HORA	LIVIANOS	MEDIO		PESADO	TOTAL X HORA
  6		2	        0		            1			         3
    d. Al finalizar el listado imprimir los siguientes datos de reporte:
TOTAL LIVIANOS: 99 	TOTAL MEDIO: 99	TOTAL PESADOS: 99
HORA CON MENOS ENVIOS: 13

Consideraciones: Los listados de ambos canales de atención se encuentran 
ordenados en forma ascendente por hora de pedido.
Restricciones: Solo se puede recorrer secuencialmente una vez cada vector

    2) Realizar diagrama del procedimiento intersección que dados dos arreglos 
    de entrada uno de N y otro de M elementos genere un nuevo arreglo de 
    salida sólo con los elementos que  están en ambos conjuntos ordenado en 
    forma ascendente. 
Ejemplo: vecA = {0, 2, 4, 9} y vecB = {9, 5, 3, 2, 1) => vecC = {2, 9} 

Consideraciones: Ambos arreglos de entrada están ordenados pero el primero 
en forma ascendente y el segundo en forma descendente. Ambos son conjuntos 
sin elementos repetidos 
Restricciones: Sólo se puede recorrer una vez cada vector de entrada

 * 
 */

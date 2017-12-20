
#ifndef sensores
#define sensores
#include "../mcp/analogToDigital.h"

/*
	Librerias para hablar con los sensores del robot.
	Sensor de proximidad: Canal 0 del MCP. Serán nuestros ojos para evitar obstaculos.
	Sensor CYN: Canal 1 del MCP. Será nuestro sigue lineas.
	Sensor CYN2: Canal 2 del MCP. Será nuestro cuenta pasos.

*/
#define PASO 			-1 	//Indica la distancia recorrida correspondiente a leer una línea de la rueda TODO, aun no está medido. (seria ver cuantas divisiones tiene, ver el perimetro de la rueda y dividir.)
#define SENSOR_PROX_1 	0 	//Indica el canal del sensor de proximidad 1
#define SENSOR_CYN_1 	2	//Indica el canal del sensor CYN 1
#define SENSOR_CYN_2 	3	//Indica el canal del sensor CYN 2


/* 
	==================================
	Funciones del sensor de proximidad
   	==================================
*/

/*
  	Devuelve si hay obstaculo o no frente al sensor de proximidad / robot en nuestro caso
  	ya que este sensor serán los ojos del robot para no chocarse.

    OUTPUT:
        bool return: true si detecta objeto, false en otro caso.
*/
bool hayObstaculo();

/*
  	Devuelve la distancia al obstaculo o -1 en caso de no haber obstaculo frente a nuestro sensor / robot en nuestro caso
  	ya que este sensor serán los ojos del robot para no chocarse.

    OUTPUT:
       	float return: true si detecta objeto, false en otro caso.
*/
float distanciaObstaculo();



/* 
	=========================================
	Funciones del sensor CYN 2 (Cuenta pasos)
   	=========================================
*/

/*
  	Devuelve True si blanco y False si negro.

    OUTPUT:
       	bool return: true si blanco, false si negro.
*/	
bool paso();

/*TODO ESTO SERÍA EL DECODER. EL DECODER TIENE QUE FUNCIONAR DE MANERA CONCURRENTE Y ESTAR LEYENDO Y ACTUALIZANDO ALGUNA VARIABLE O ALGO...*/

/*En una logica de capa superior
  crear variable global "distancia". crear funcion concurrente que llame a "paso" (OJO CON LLAMAR AL RECURSO A LA PAR QUE OTRO DATO)
  la funcion lee todo el rato paso. cada vez que hay transicion de true a false y vicecersa... hay un paso.
  sumar a variable distancia el tamaño de un paso SI SENTIDO == delante
  restar "                                      " SI SENTIDO == detras

  ESTO SOLO HACERLO SI VA HACIA DELANTE O HACIA ATRAS. EN CASO DE QUE SEA UNA ROTACION, MEDIR DE OTRA FORMA LA ROTACION
  Y TAMBIEN TENERLA EN CUENTA PARA SABER LA POSICION DEL OBJETO

*/




/* 
	=========================================
	Funciones del sensor CYN 1 (Sigue líneas)
   	=========================================
*/

/*
  	Devuelve la distancia al obstaculo o -1 en caso de no haber obstaculo frente a nuestro sensor / robot en nuestro caso
  	ya que este sensor serán los ojos del robot para no chocarse.

    OUTPUT:
       	bool return: true si detecta negro(linea), false en otro caso.
*/
bool hayLinea();

#endif
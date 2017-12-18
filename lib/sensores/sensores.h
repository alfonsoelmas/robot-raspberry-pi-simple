
#ifndef sensores
#define sensores
#include "../mcp/analogToDigital.h"

/*
	Librerias para hablar con los sensores del robot.
	Sensor de proximidad: Canal 0 del MCP. Serán nuestros ojos para evitar obstaculos.
	Sensor CYN: Canal 1 del MCP. Será nuestro... Siguelineas? CuentaPasos...?
	Sensor CYN2: Canal 2 del MCP. Será nuestro... Siguelineas? CuentaPasos...?

*/
#define PASO 0 			 	//Indica la distancia recorrida correspondiente a leer una línea de la rueda
#define SENSOR_PROX_1 -1 	//Indica el canal del sensor de proximidad 1
#define SENSOR_PROX_2 -1 	//Indica el canal del sensor de proximidad 2
#define SENSOR_CYN_1 -1		//Indica el canal del sensor CYN 1
#define SENSOR_CYN_2 -1		//Indica el canal del sensor CYN 2


/*
	Funciones del sensor de proximidad
*/
//True si el sensor de proximidad detecta obstaculo
bool hayObstaculo();
//Devuelve la distancia de obstaculo
float distanciaObstaculo();

/*
	Funciones del sensor CYN1
*/

//Indica si ha dado un paso el robot
bool paso();

/*
	Funciones del sensor CYN2
*/

//Devuelve si está leyendo o no la línea.
bool hayLinea();

#endif


























rlmnt st d n l cbz m l hn d mtnd
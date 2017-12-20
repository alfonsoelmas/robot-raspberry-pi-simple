/**
Autor: Alfonso Soria Muñoz
Este código está bajo licencia Apache
**/


#include <wiringPi.h>
#include <softPwm.h>

#ifndef SERVOS_LIB
#define SERVOS_LIB
/*
	Libreria para hablar con los servos del robot.
	Servo 1: Pin X de la RPI
	Servo 2: Pin x de la RPI

	Datos sobre los servos empleados:

	Servos parallax de movilidad continua.
	Comunicación mediante PWM.
	Conexión a los pines 11 y 12 de la RPI.

	Datos del servo:

	20ms su pwm (su ciclo de reloj)
	1.5ms de valor alto = quiero
	1.2ms de valor bajo = izquierda
	1.7ms de valor alto = derecha

	Frecuencia del reloj de la rpi = 19200000
	Frecuencia del servo = 50
	Divisor del reloj = FrecServo / FrecReloj

*/

#define PIN_SERVO_DER 1 			//PIN DEL SERVO DERECHO A LA RPI3 MODEL B (patilla 12)   GPIO 18
#define PIN_SERVO_IZQ 0 			//PIN DEL SERVO IZQUIERDO A LA RPI3 MODEL B (patilla 11) GPIO 17


#define MAX_VELOCIDAD 100 			//Equivalente a 50 RPM de nuestro servo parallax		
#define MIN_VELOCIDAD 0
#define DEFAULT_VEL 50 				


#define FRECUENCIA_PWM 50 			//Frecuencia del servo pwm.
#define FRECUENCIA_RELOJ 19200000 	//Frecuencia estandar reloj Rpi (Para PWM)

/*Sentido del servo*/
typedef enum Sentido
{
	DELANTE, 
	QUIETO, 
	DETRAS
};


static int velocidad = DEFAULT_VEL;


/*====================================
	Funciones de los servos
=====================================*/

/*
	Mueve el servo izquierdo en sentido "s"
	Input:
		Sentido s: Sentido del servo (DELANTE, QUIERO, DETRAS)
*/

void moverServoIzquierdo (Sentido s);


/*
	Mueve el servo izquierdo en sentido "s"
	Input:
		Sentido s: Sentido del servo (DELANTE, QUIERO, DETRAS)
*/
void moverServoDerecho (Sentido s);

/*
	Selecciona la velocidad a la que mover los servos.
	Input:
		int vel: Velocidad entre 0 y 100 (porcentaje sobre el maximo de revoluciones del servo)
*/

void setVelocidad(int vel);

/*
	Inicializa y deja preparados los servos
	estableciendo los pines y la frecuencia para el PWM.

	Configura los pines de los servos como PWM y los establece a frecuencia FRECUENCIA_PWM
	Return:
		int: 0 si todo ok. Otro valor en otro caso.
*/
int servosSetup(); 
#endif

/**
Autor: Alfonso Soria Muñoz
Este código está bajo licencia Apache
**/

#include <wiringPi.h>
#include <wiringPiSPI.h>

/*

    Esta librería funciona como interfaz entre RPI spi y MCP3008.
    Para su correcto funcionamiento, conectar MCP3008 en los siguientes pines mencionados:

    MCP3008 VDD to Raspberry Pi 3.3V
    MCP3008 VREF to Raspberry Pi 3.3V
    MCP3008 AGND to Raspberry Pi GND
    MCP3008 DGND to Raspberry Pi GND
    MCP3008 CLK to Raspberry Pi pin 23 (gpio 11)
    MCP3008 DOUT to Raspberry Pi pin 21 (gpio 9)
    MCP3008 DIN to Raspberry Pi pin 19 (gpio 10)
    MCP3008 CS/SHDN to Raspberry Pi pin 24 (gpio 8)

        CH0     -1=========16-      VDD
        CH1     -2    M    15-      VREF
        CH2     -3    C    14-      AGND
        CH3     -4    P    13-      CLK
        CH4     -5    |    12-      DOUT
        CH5     -6    30   11-      DIN
        CH6     -7    08   10-      CS/SHDN
        CH7     -8==========9-      DGND


*/
#ifndef MCP3008
#define MCP3008

#define CLK 23
#define DOUT 21
#define DIN 19
#define CS_SHDN 24

#define CHAN_CONFIG_SINGLE  8
#define CHAN_CONFIG_DIFF    0
#define CANAL1 1
#define CANAL0 0


static int myFd;


/*
  Lee un valor analogico del canal "canal"
    INPUT:
        int canal: Canal a leer (entre 0 y 7)
    OUTPUT:
        int return: valor leído del canal "canal" o -1 en caso de error
*/
int     analogReadMCP(int canal);
/*
  Escribe un valor analogico al canal "canal". El valor debe comprender entre 0 y 1024
  Si la operación sale correctamente devuelve 0 y -1 si sale incorrectamente
    INPUT:
        int canal: Canal a escribir. (Entre 0 y 7)
        int valor: Valor a escribir del canal. (Entre 0 y 1024)
    OUTPUT:
        return int: 0 si todo ok. -1 si error de operacion
*/
int    analogWriteMCP(int canal, int valor);
/*
  Carga las configuraciones para dejarla lista para su uso.
  Devuelve -1 si da error.  
*/
int    mcpSetup();
/*
    Cierra la conexion ISP con la MCP.
*/
void mcpClose();

/*
	Transforma el valor al voltaje de referencia.
		INPUT:
			int data: Dato de voltaje en ADC. (Entre 0 y 1024).
		OUTPUT:
			float voltaje: Voltaje referente. (3.3 voltios de referencia). (Entre 0 y 3.3). -1 si error de operacion.
*/
float dataToVolt(int data);



#endif

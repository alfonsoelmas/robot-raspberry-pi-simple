# robot-raspberry-pi-simple

Diseño de un robot realizado desde cero, en lenguaje C, con wiringPi, sensores y servos.
El proyecto se compone de un diagrama/esquema sobre la electronica del robot. Indicando sensores, controladores, chips y resistencias necesarias.
Por otro lado, el codigo se divide en varias capas y trabaja sobre wiringPi separando en capas su estructura.

## Electrónica

Los componentes a empleados son:

* 1 Raspberry pi 3 modelo B
* 1 MCP3008 (Analogico/Digital) Conversor
* 2 Sensores CYN para un decoders y siguelíneas
* 1 Sensor de proximidad por infrarrojos (GP2Y0A21YK0F)
* Cables (m-m, m-h, h-h)
* 1 protoboard
* 2 servos parallax de rotación contínua

En la carpeta de documentación podeis encontrar una imagen llamada "disenio_circuito" que muestra cómo está organizada la electrónica para cablearla de la misma forma.

### Sobre la MCP3008

La MCP3008 será un chip que nos permitirá leer los datos análógicos de nuestros sensores, puesto que la raspberry pi solo trabaja con datos digitales,
por lo que este chip nos hará de interfaz para leer datos analógicos que nos aportarán los sensores de proximidad y CYN. Crearemos una interfaz de comunicación
en C con wiringPi y SPI que nos permita leer de los 8 canales que tiene con funciones simples y cómodas.

La MCP 3008 es un chip que utiliza el protocolo SPI para comunicarse con la raspberry pi. Por lo que emplearemos los pines necesarios para aplicar este protocolo.
En la cabecera de la interfaz de comunicación llamada "analogToDigital" se puede encontrar más informacion sobre el cableado entre la RPI y la MCP3008, así como la
información de sus patillas.

La MCP 3008 genera valores de entre 0 y 1024 referenciando su valor máximo como el valor que se tenga metido en la patilla de Vref, en nuestro caso, 3.3voltios de referencia.
Con esta información, nos permite parsear el valor de dato a voltaje y viceversa.

La MCP 3008 nos permite tanto leer como escribir a través de SPI con hasta 8 canales analógicos. En nuestro caso, estaremos empleando de momento 3 canales analógicos.

La MCP 3008 necesita ser conectada a 3.3 voltios, tanto su valor de referencia, como su alimentación.

### Sobre los sensores CYN

Los sensores CYN están compuestos por un mini led infrarrojo y un transistor sensible a ciertas ondas de luz. Los sensores CYN se disparan de valores muy bajos a altos según
la reflexión de la luz con un objeto muy próximo a estos (Hablamos de medidas milimetrales). Estos sensores nos permitiran la construcción de decoders para medir el movimiento
del robot, así como poder usarlos como siguelíneas.

El sensor CYN necesita 3 resistencias. Una para el led, de aproximadamente 220, 270 ohmnios, y dos para la salida del transistor (Una antes de su outPut y otra antes de conectarlo a tierra), de 10K Ohmnios y 15K Ohmnios respectivamente. En el esquema de la imágen se puede ver con más detalle las conexiones del CYN. Los colores del cableado
tienen sentido para entender mejor las conexiones. (Negro = tierra, rojo = corriente, amarillo = señal...)

### Sobre el sensor de proximidad (GP2Y0A)

* Comentar función GP2Y0A
* Comentar caracteristicas
* Conexion a 5V
* Formula correspondiente

### Sobre los servos de rotación contínua Parallax

* TODO *


## Software / Estructuración del código

### Estructura del proyecto

#### AnalogToDigital.h - primera capa

#### Servos.h - primera capa

#### Sensores.h - primera capa



### Sobre la documentación
Animo a todo el mundo a añadir toda documentacion posible de forma legible y no caotica. Animo a realizar aportaciones, y mejoras,
pero pido ser notificado previamente para no alborotar mucho mi proyecto.

En cuestion de semanas mejorare y aportare documentacion así como añadiré todo lo que falta por desarrollar.

Este código está bajo licencia apache y ha sido desarrollado por Alfonso Soria Muñoz.

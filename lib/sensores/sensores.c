/**
Autor: Alfonso Soria Muñoz
Este código está bajo licencia Apache
**/


/* 
  ==================================
  Funciones del sensor de proximidad
  ==================================
*/

bool hayObstaculo()
{

    int dato[10];
    int i;

    for(i=0; i<10; i++) dato[i] = analogReadMCP(SENSOR_PROX_1); //Leemos 10 valores del sensor -Hacemos 10 lecturas porque alguna vez obtenemos una desviación de +40-
    
    //Calculamos la media
    int sum=0;
    for(i=0; i<10; i++) suma += dato[i];
    int media = sum/10;

    //Hacemos return... consideramos que hay objeto a partir de 25...

    if(media > 25)
      return true;
    else
      return false;


}


float distanciaObstaculo()
{

    /*
      La función que cumple nuestro sensor
      tiene la forma (y = 26,902x^-1,274  con un R² = 0,9933)
      dentro de los valores comprendidos entre y >= 5 && y <=80.
      Para y<5 habría que aplicar otra fórmula que no tendremos en cuenta actualmente.
      Para las X < 0.4, asignamos la distancia = 0;
    */

    for(i=0; i<10; i++) dato[i] = analogReadMCP(SENSOR_PROX_1); //Leemos 10 valores del sensor -Hacemos 10 lecturas porque alguna vez obtenemos una desviación de +40-
    
    //Calculamos la media
    int sum=0;
    for(i=0; i<10; i++) suma += dato[i];
    int media = sum/10;

    float voltaje = dataToVolt(media); //Calculamos el voltaje correspondiente.
    if(voltaje < 0.43)
      return 0;
    if(voltaje > 3.29)
      return -1;
    //Calculamos la distancia con nuestra formula de voltaje a distancia
    float distancia = 26.902*(voltaje^(-1,274));

    return distancia;
}

//=======================================
//    Funciones auxiliares
//=======================================

//Funcion para ser llamada por haylinea y paso para reutilizar código ya que funcionan igual.
bool blancoNegro(int sensor)
{
    //Si el valor del sensor es menor que 150... es que está leyendo linea negra
    /*
      Nota: Añado 150 como rango, pero el sensor se dispara rapidamente entre 0 si lee negro a 500 si lee blanco. (Mas reflexion de luz provoca mas voltaje)
      Si no lee nada, en luz ambiente, sobre fluorezcentes el sensor obtiene valores entre 0 y 100, por ese "ruido" que pueda existir y porque se dispara fácilmente
      frente al rebote de luz con objetos blancos, considero válida y suficientemente óptimo el valor 150.
    */
    if(analogReadMCP(sensor) < 150)
      return false; //Si lee negro
    else
      return true;  //Si lee blanco

}


/* 
	=========================================
	Funciones del sensor CYN 2 (Cuenta pasos)
  =========================================
*/

bool paso()
{
  return blancoNegro(SENSOR_CYN_2);
}


/*
	=========================================
	Funciones del sensor CYN 1 (Sigue líneas)
  =========================================
*/

bool hayLinea()
{
  return !blancoNegro(SENSOR_CYN_1);
}



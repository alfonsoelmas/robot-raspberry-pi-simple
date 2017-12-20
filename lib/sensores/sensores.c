
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

    //TODO

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



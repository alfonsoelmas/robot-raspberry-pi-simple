
void moverServo(int pin, Sentido s)
{

	if (s == Sentido.DELANTE)
	{
		/*
			Coger velocidad
			Velocidad entre 0 y 100
			MS entre 1.5 y 2.4 (TODO, no se si deberia ser 1.7 en realidad pero depurando el tope al que llega es 2.4)
		*/
		float diferencia = 24 - 15;
		float media = velocidad/100;
		diferencia = diferencia * media;
		diferencia +=15;

		softPwmWrite(pin,diferencia);
		
	} 
	else if (s == Sentido.DETRAS)
	{

		/*
			Coger velocidad
			Velocidad entre 0 y 100
			MS entre 1.5 y 0.6 (TODO, no se si deberia ser 1.3 en realidad pero depurando el tope al que llega es 0.6)
		*/
		float diferencia = 15 - 6;
		float media = velocidad/100;
		diferencia = diferencia * media;
		diferencia +=6;

		softPwmWrite(pin,diferencia);
	} 
	else
	{
		//Sentido = quieto
		softPwmWrite(pin, 15); //Depurando, el valor 15 implica "quieto" == 1.5ms de valor alto por cada ciclo de reloj de 20 ms.
	}
}



void moverServoIzquierdo (Sentido s)
{
	moverServo(PIN_SERVO_IZQUIERDA, s);
}


void moverServoDerecho (Sentido s)
{
	moverServo(PIN_SERVO_DERECHA, s);
}


void setVelocidad(int vel)
{
	//Si la velocidad está entre 0 y 100 los datos son validos y la modifico.
	//La velocidad en realidad es un porcentaje sobre la máxima velocidad (RPM) del servo empleado.
	if(vel >= 0 && vel <= 100)
		velocidad = vel;
}


void servosSetup()
{

	pinMode(PIN_SERVO_IZQUIERDA, PWM_OUTPUT);		//Servo motor izquierda
	pinMode(PIN_SERVO_DERECHA,	 PWM_OUTPUT);		//Servo motor derecha

	digitalWrite(PIN_SERVO_DERECHA,0);				//Ponemos a 0 su salida digital (servo derecho)
	digitalWrite(PIN_SERVO_IZQUIERDA,0);			//Ponemos a 0 su salida digital (servo izquierdo)

	softPwmCreate(PIN_SERVO_IZQUIERDA,0,200);		//Establecemos un PWM de 20 ms, y lo configuramos a nivel bajo constante. (servo Izquierdo)
	softPwmCreate(PIN_SERVO_DERECHA,0,200);			//Establecemos un PWM de 20 ms, y lo configuramos a nivel bajo constante. (servo Izquierdo)
}
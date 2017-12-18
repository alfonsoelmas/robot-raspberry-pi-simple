
void moverServo(int pin, Sentido s)
{

	if (s == Sentido.DELANTE)
	{
		
	} 
	else if (s == Sentido.DETRAS)
	{
		/* code */
	} 
	else
	{

	}
}



void moverServoIzquierdo (Sentido s) //TODO
{
	moverServo(PIN_SERVO_IZQUIERDA, s);
}


void moverServoDerecho (Sentido s) //TODO
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
	int divisor: //TODO INICIALIZARLO. VER A CUANTO ESTÁ EL CLOCK PARA EL DIVISOR
	divisor = frecuencia_reloj/FRECUENCIA_PWM;

	pwmSetClock(divisor); //TODO posible burrada
	//pwmSetMode(); POR DEFECTO EN MODO BALANCEADO.

	pinMode(PIN_SERVO_IZQUIERDA, PWM_OUTPUT);	//Servo motor izquierda
	pinMode(PIN_SERVO_DERECHA,PWM_OUTPUT);		//Servo motor derecha

	

	/* TODO
		80MHZ MODO SISTEMA
		5 MHZ DE VALOR ALTO?
	*/

}
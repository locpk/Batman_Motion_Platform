#include "SServo.h"


void SServoClass::init(int pin, int trim)
{
	servo.attach(pin);
	servoTrim = trim;
	ResetServo();
}

void SServoClass::ResetServo()
{
	if (servo.attached())
	{
		servoCurPos = 90 + servoTrim;
		servo.write(servoCurPos);
	}
}


void SServoClass::SetMovementRange(int startPos, int endPos)
{
	 sPos = startPos + servoTrim;
	 ePos = endPos + servoTrim;
}

float lerp(float a, float b, float f)
{
	return a + f * (b - a);
}

void SServoClass::Update(float dt)
{
	if (dt <= 1.0f)
	{
		servoCurPos = lerp(sPos, ePos, dt) + servoTrim;
		servo.write(servoCurPos);
	}
}


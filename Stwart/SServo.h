// SServo.h

#ifndef _SSERVO_h
#define _SSERVO_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#include <Servo.h>
#else
#include "WProgram.h"
#endif

class SServoClass
{
protected:
	Servo servo;
	int pin;
	int servoTrim;
	int servoStep;
	int servoSpeed;
	int servoCurPos;
	unsigned long lastTimeMoved;
	float fServoSpeed;
	int sPos;
	int ePos;

public:
	void init(int pin, int trim = 0);
	void ResetServo();
	void SetMovementRange(int startPos, int endPos);
	void Update(float dt);

};


#endif


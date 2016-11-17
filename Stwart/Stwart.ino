#include "SServo.h"





/*CONSTANTS*/
const int SERVO_TRIMS[6] = { 7,-9,7,0,0,-9 };

/*VERIABLES*/
SServoClass servos[6];

static float dt = 0.0f;
static unsigned long currStateTimer = 0;
const unsigned long  stateInterval = 1000;
int State = 0;

const int servoPosTable0[][6] =
{
	//YAW
	{ 90,90,90,90,90,90 },
	{ 34,34,34,34,34,34 },
	{ 90,90,90,90,90,90 },
	{ 149,149,149,149,149,149 },
	//PITCH
	{ 90,90,90,90,90,90 },
	{ 28,76,116,64,104,152 },
	{ 90,90,90,90,90,90 },
	{ 149,119,29,151,61,31 },
	//ROLL
	{ 90,90,90,90,90,90 },
	{ 93,148,41,29,164,64 },
	{ 90,90,90,90,90,90 },
	{ 112,17,142,126,25,119 },
	//SURGE
	{ 90,90,90,90,90,90 },
	{ 136,117,168,2,60,40 },
	{ 90,90,90,90,90,90 },
	{ 99,9,82,96,175,77 },
	//SWAY
	{ 90,90,90,90,90,90 },
	{ 65,68,153,102,129,10 },
	{ 90,90,90,90,90,90 },
	{ 158,52,77,30,106,108 },
	//HEAVE
	{ 90,90,90,90,90,90 },
	{ 146,34,146,34,146,34 },
	{ 90,90,90,90,90,90 },
	{ 37,149, 37,149, 37,149 },
	{ 90,90,90,90,90,90 },
};






void setup()
{
	Serial.begin(115200);
	servos[0].init(3, SERVO_TRIMS[0]);
	servos[1].init(5, SERVO_TRIMS[1]);
	servos[2].init(6, SERVO_TRIMS[2]);
	servos[3].init(9, SERVO_TRIMS[3]);
	servos[4].init(10, SERVO_TRIMS[4]);
	servos[5].init(11, SERVO_TRIMS[5]);
}


void loop()
{

	
	if (millis() >= currStateTimer)
	{

		State++;
		if (State >= 24)
		{
			State = 0;
		}


		for (size_t i = 0; i < 6; i++)
		{
			servos[i].SetMovementRange(servoPosTable0[State][i], servoPosTable0[State + 1][i]);
		}

		currStateTimer = millis() + stateInterval;

	}

	dt = 1.0f - static_cast<float>(currStateTimer - millis()) / static_cast<float>(stateInterval);


	for (auto& servo : servos)
	{
		servo.Update(dt);
	}

}

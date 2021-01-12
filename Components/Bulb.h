#pragma once
#include "Component.h"

class Bulb :public Component
{
private:
	int x;
public:
	
	Bulb(GraphicsInfo* r_GfxInfo);
	void Draw(UI*);	//Draws the bulb
	void Operate();
	string save() const;
	void load(int id, string LABELi , double VALUE); //load Bulb
	Component* Copy();
	int GetOutStatus();	//returns status of output if BULB/BUZZER, return -1
	int GetInputStatus();	//returns status of SWITCH, return -1

	void setInputStatus(STATUS s);	//set status of SWITCH
};



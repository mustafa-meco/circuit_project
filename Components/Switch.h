#pragma once
#include "Component.h"

class Switch :public Component
{

public:
	Switch(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws the bulb
	virtual void Operate();
	string save() const;
	void load(int id ,string, double); //Load the switch 
	Component* Copy();                 //Copy the component information 

	int GetOutStatus();	//returns status of output if BULB/BUZZER, return -1
	int GetInputStatus();	//returns status of SWITCH, return -1

	void setInputStatus(STATUS s);	//set status of SWITCH
};




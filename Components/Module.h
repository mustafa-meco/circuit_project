#pragma once
#include "Component.h"
#include "Resistor.h"
class Module :
    public Component
{
public:
	Module(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Operate();
	string save() const;
	void load(int id, string LABELi, double VALUE);
	Component* Copy();

	int GetOutStatus();	//returns status of output if BULB/BUZZER, return -1
	int GetInputStatus();	//returns status of SWITCH, return -1

	void setInputStatus(STATUS s);	//set status of SWITCH
};


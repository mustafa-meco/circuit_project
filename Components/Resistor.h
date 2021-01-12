#pragma once
#include "Component.h"

class Resistor :public Component
{
public:
	Resistor(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Operate();
	string save() const;
	void load(int id,string LABELi, double VALUE);   //Load the Resistor 
	Component* Copy();                               //Copy the component information 

	int GetOutStatus();	//returns status of output if BULB/BUZZER, return -1
	int GetInputStatus();	//returns status of SWITCH, return -1

	void setInputStatus(STATUS s);	//set status of SWITCH
};


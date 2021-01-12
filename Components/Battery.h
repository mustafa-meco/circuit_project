#pragma once
#include "Component.h" 

class Battery :public Component
{
public:
	Battery(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws the battrey 
	void Operate();
	string save() const;
	void load(int id, string LABELi, double VALUE);        //load the battery
	Component* Copy();
	//virtual void setPolarity(BatPolarity p); 
	//virtual BatPolarity GetPolarity();
	int GetOutStatus();	//returns status of output if BULB/BUZZER, return -1
	int GetInputStatus();	//returns status of SWITCH, return -1

	void setInputStatus(STATUS s);	//set status of SWITCH
};



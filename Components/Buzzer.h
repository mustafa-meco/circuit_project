#pragma once
#include "Component.h"


class Buzzer :public Component
{
public:
	Buzzer(GraphicsInfo* r_GfxInfo/*, UI* pUI*/);  //Constructor to intialize the data of the Buzzer
	virtual void Draw(UI*);	                       //Draws buzzer
	virtual void Operate();
	string save() const;                           //Save and return the Buzzer info
	void load(int id,string LABELi, double VALUE); //load the buzzer 
	Component* Copy();
	int GetOutStatus();	//returns status of output if BULB/BUZZER, return -1
	int GetInputStatus();	//returns status of SWITCH, return -1

	void setInputStatus(STATUS s);	//set status of SWITCH
};


#pragma once
#include"Component.h"


class Fues :public Component
{
public:
	Fues(GraphicsInfo* r_GfxInfo/*, double*/);             //Constructor to intialize the data of the Fues
	virtual void Draw(UI*);	                               // Drawsfues
	virtual void Operate();
	int GetOutStatus();	//returns status of output if BULB/BUZZER, return -1
	int GetInputStatus();	//returns status of SWITCH, return -1

	void setInputStatus(STATUS s);	//set status of SWITCH
	string save() const;                                   //Save and return the Fues info
	void load(int id,string LABELi, double VALUE );        //load fues
	Component* Copy();                                     //Copy the component information 
};


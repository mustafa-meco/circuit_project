#pragma once
#include "Component.h" 

class Battery :public Component
{
public:
	Battery(GraphicsInfo* r_GfxInfo);                      //Constructor to intialize the data of the Battery
	virtual void Draw(UI*);                                //Draws the battrey 
	virtual void Operate();
	string save() const;                                   //Save and return the Battery info
	void load(int id, string LABELi, double VALUE);        //load the battery
	Component* Copy();                                     //Copy the component information 
	//virtual void setPolarity(BatPolarity p); 
	//virtual BatPolarity GetPolarity();
	int GetOutStatus();	//returns status of output if BULB/BUZZER, return -1
	int GetInputStatus();	//returns status of SWITCH, return -1

	void setInputStatus(STATUS s);	//set status of SWITCH
};



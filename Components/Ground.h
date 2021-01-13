#pragma once
#include"Component.h"
#include "..\UI\UI.h"
#include "..\ApplicationManager.h"
#include "../ApplicationManager.h"

class Ground :public Component
{
public:
	Ground(GraphicsInfo* r_GfxInfo);                //Constructor to intialize the data of the Ground
	virtual void Draw(UI*);                         //Draws the ground
	virtual void Operate();
	string save() const;                            //Save and return the Ground info
	void load(int id, string LABELi, double VALUE); // load ground component
	Component* Copy();                              //Copy the component information 

	int GetOutStatus();	//returns status of output if BULB/BUZZER, return -1
	int GetInputStatus();	//returns status of SWITCH, return -1

	void setInputStatus(STATUS s);	//set status of SWITCH
};


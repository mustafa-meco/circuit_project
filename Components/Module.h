#pragma once
#include "Component.h"
#include "Resistor.h"
class Module :
    public Component
{
public:
	Module(GraphicsInfo* r_GfxInfo);                //Constructor to intialize the data of the Module
	virtual void Draw(UI*);                        	//Draws the resistor
	virtual void Operate();
	string save() const;                             //Save and return the Module info
	void load(int id, string LABELi, double VALUE);  //load the Module
	Component* Copy();                               //Copy the Module information
};


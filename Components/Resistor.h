#pragma once
#include "Component.h"

class Resistor :public Component
{
public:
	Resistor(GraphicsInfo* r_GfxInfo);              //constructor to intialize the data of the switch 
	virtual void Draw(UI*);                        	//Draws the resistor
	virtual void Operate();
	string save() const;                             //save and return the component info
	void load(int id,string LABELi, double VALUE);   //Load the Resistor 
	Component* Copy();                               //Copy the component information 
};


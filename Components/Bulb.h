#pragma once
#include "Component.h"

class Bulb :public Component
{
public:
	Bulb(GraphicsInfo* r_GfxInfo);                   //Constructor to intialize the data of the Bulb
	virtual void Draw(UI*);	                         //Draws the bulb
	virtual void Operate();
	string save() const;                             //Save and return the Bulb info
	void load(int id, string LABELi , double VALUE); //load Bulb
	Component* Copy();                               //Copy the component information 
};

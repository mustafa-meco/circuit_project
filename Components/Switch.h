#pragma once
#include "Component.h"

class Switch :public Component
{
public:
	Switch(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws the bulb
	virtual void Operate();
	string save() const;
	void load(int id ,string, double); //Load the switch 
	Component* Copy();                 //Copy the component information 


};




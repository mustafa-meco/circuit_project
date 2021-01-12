#pragma once
#include "Component.h"

class Switch :public Component
{
public:
	Switch(GraphicsInfo* r_GfxInfo);    //constructor to intialize the data of the switch 
	virtual void Draw(UI*);	            //Draws the bulb
	virtual void Operate();        
	string save() const;                //save and return the component info
	void load(int id ,string, double);  //Load the switch 
	Component* Copy();                  //Copy the component information 


};




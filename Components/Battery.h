#pragma once
#include "Component.h" 

class Battery :public Component
{
public:
	Battery(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws the battrey 
	virtual void Operate();
	string save() const;
	void load(int id, string LABELi, double VALUE);        //load the battery
	Component* Copy();
	//virtual void setPolarity(BatPolarity p); 
	//virtual BatPolarity GetPolarity();
};

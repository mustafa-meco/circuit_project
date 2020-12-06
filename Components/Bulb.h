#pragma once
#include "Component.h"

class Bulb :public Component
{
public:
	Bulb(GraphicsInfo* r_GfxInfo/*, double R*/);
	virtual void Draw(UI*);	//Draws the bulb
	virtual void Operate();
	string save() const;
	void load(int id, string LABELi , double VALUE);
};

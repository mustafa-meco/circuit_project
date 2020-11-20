#pragma once
#include "Component.h"

class Resistor:public Component
{
public:
	Resistor(GraphicsInfo *r_GfxInfo, UI* pUI);
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Operate();
};

#pragma once
#include "Component.h"

class Switch :public Component
{
public:
	Switch(GraphicsInfo* r_GfxInfo, UI* pUI);
	virtual void Draw(UI*);	//Draws the bulb
	virtual void Operate();
	string save() const;
};




#pragma once
#include "Component.h"

class Bulb :public Component
{
public:
	Bulb(GraphicsInfo* r_GfxInfo, UI* pUI);
	virtual void Draw(UI*);	//Draws the bulb
	virtual void Operate();
	string* save() const;
};

#pragma once
#include "Component.h" 
//#include "../Electric Circuit Simulator - Code Framework/Components/Component.h"

class Battery :public Component
{
public:
	Battery(GraphicsInfo* r_GfxInfo, UI*);
	virtual void Draw(UI*);	//Draws the battrey 
	virtual void Operate();
	string save() const;
	void load(int id, string LABELi, double VALUE);
};

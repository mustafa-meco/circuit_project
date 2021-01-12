#pragma once
#include "Component.h"
#include "Resistor.h"
class Module :
    public Component
{
private:
	double r[4];
public:
	Module(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Operate();
	string save() const;
	void load(int id, string LABELi, double VALUE);
};


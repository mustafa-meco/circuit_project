#pragma once
#include "Component.h"


class Buzzer :public Component
{
public:
	Buzzer(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws buzzer
	virtual void Operate();
	string* save() const;
};

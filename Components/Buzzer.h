#pragma once
#include "Component.h"


class Buzzer :public Component
{
public:
	Buzzer(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Draws buzzer
	virtual void Operate();
	string save() const;
	void load(int id,string LABELi, double VALUE); //load the buzzer 
	void Copy(Component* B);

};

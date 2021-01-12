#pragma once
#include "Component.h"


class Buzzer :public Component
{
public:
	Buzzer(GraphicsInfo* r_GfxInfo/*, UI* pUI*/);  //Constructor to intialize the data of the Buzzer
	virtual void Draw(UI*);	                       //Draws buzzer
	virtual void Operate();
	string save() const;                           //Save and return the Buzzer info
	void load(int id,string LABELi, double VALUE); //load the buzzer 
	Component* Copy();                             //Copy the component information 
};

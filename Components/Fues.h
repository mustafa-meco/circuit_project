#pragma once
#include"Component.h"


class Fues :public Component
{
public:
	Fues(GraphicsInfo* r_GfxInfo/*, double*/);
	virtual void Draw(UI*);	// Drawsfues
	virtual void Operate();
	string save() const;
	void load(int id,string LABELi, double VALUE ); //load fues

};

#pragma once
#include"Component.h"


class Fues :public Component
{
public:
	Fues(GraphicsInfo* r_GfxInfo);
	virtual void Draw(UI*);	//Drawsfues
	virtual void Operate();
	string* save() const;
};

#pragma once
#include"Component.h"
//#include "../Electric Circuit Simulator - Code Framework/Components/Component.h"

class Ground :public Component
{
public:
	Ground(GraphicsInfo* r_GfxInfo, UI* pUI);
	virtual void Draw(UI*);	//Draws the ground
	virtual void Operate();
};

#pragma once
#include"Component.h"
#include "..\UI\UI.h"
#include "..\ApplicationManager.h"
#include "../ApplicationManager.h"

class Ground :public Component
{
public:
	Ground(GraphicsInfo* r_GfxInfo); 
	virtual void Draw(UI*);	//Draws the ground
	virtual void Operate();
	string save() const;
	void load(int id, string LABELi, double VALUE); // load ground component
	void Copy(Component* &B);

};

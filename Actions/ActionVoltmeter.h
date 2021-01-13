#pragma once
#include "Action.h"
#include "..\Components\Component.h"
class ActionVoltmeter :
    public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	Component* comp;
	GraphicsInfo* undo1;
	double undo2;
public:
	ActionVoltmeter(ApplicationManager* pApp);
	virtual ~ActionVoltmeter(void);

	//Execute action (code depends on action type)
void Execute();

	void Undo();
	void Redo();
};


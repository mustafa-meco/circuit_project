#pragma once
#include "Action.h"
#include"../Components/Module.h"
#include "../ApplicationManager.h"
#include <fstream>
class ActionAddDesignedModule :
    public Action
{
private:
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	Component* comp;
	GraphicsInfo* undo1;
	double undo2;
public:
	ActionAddDesignedModule(ApplicationManager* pApp);

	~ActionAddDesignedModule(void);
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};


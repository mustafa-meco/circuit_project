#pragma once
#include "Action.h"
class ActionAddModule :
    public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x[8]; int y[8];
public:
	ActionAddModule(ApplicationManager* pApp);
	virtual ~ActionAddModule(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};


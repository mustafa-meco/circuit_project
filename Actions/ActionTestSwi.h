#pragma once
#include"../Components/Component.h"
#include "Action.h"
class ActionTestSwi :
    public Action
{

private:
	//parameters for rectangular area to be occupied by the comp
	Component* comp;
	Connection* connection;
	int cx, cy;	//center point of the comp
	int x1, y1, x2, y2;	//two corners of the rectangluar area
public:
	ActionTestSwi(ApplicationManager* pApp);
	virtual ~ActionTestSwi(void);
	//execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};


#pragma once

#include "Action.h"
#include "../Components/Component.h"

//Class responsible for adding a new resistor action
class ActionMove : public Action
{
private:
	Component* comp;
	Connection* connection;
	int cx, cy;	//center point of the comp
	int x1, y1, x2, y2;	//two corners of the rectangluar area
	GraphicsInfo* undo1;

public:
	ActionMove(ApplicationManager* pApp);
	virtual ~ActionMove(void);
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};


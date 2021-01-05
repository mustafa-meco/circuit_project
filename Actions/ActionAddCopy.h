#pragma once
#include "../ApplicationManager.h"
#include "Action.h" 
class ActionAddCopy : public Action
{
	int Cx;
	int Cy;
public:
	ActionAddCopy(ApplicationManager* pApp);
	

	~ActionAddCopy(void);
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

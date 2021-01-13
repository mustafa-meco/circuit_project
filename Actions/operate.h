#pragma once
#include "Action.h"
class Actionoperate :
    public Action
{
public:
	Actionoperate(ApplicationManager* pApp);
	virtual ~Actionoperate(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};


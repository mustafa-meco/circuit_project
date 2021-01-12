#pragma once
#include "../ApplicationManager.h"
#include "Action.h" 
#include "../Components/Component.h"
class ActionAddCut : public Action
{
	int Cx;
	int Cy;
public:
	ActionAddCut(ApplicationManager* pApp);

	~ActionAddCut(void);
	virtual void Execute(); //Execute action

	virtual void Undo();
	virtual void Redo();
};
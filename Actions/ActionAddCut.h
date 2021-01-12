#pragma once
#include "../ApplicationManager.h"
#include "Action.h" 
#include "../Components/Component.h"
class ActionAddCut : public Action
{
	int C1, C2;
	int Cx;
	int Cy;
	Component* comp2;
	Component* temp1;
	Connection* undo1[10];
	Connection* undo2[10];
public:
	ActionAddCut(ApplicationManager* pApp);

	~ActionAddCut(void);
	virtual void Execute(); //Execute action

	virtual void Undo();
	virtual void Redo();
};
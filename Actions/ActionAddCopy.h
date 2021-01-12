#pragma once
#include "../ApplicationManager.h"
#include "Action.h"
//#include "../circuit_project/ApplicationManager.h"
//#include "../circuit_project/Actions/Action.h" 
class ActionAddCopy : public Action
{
	int Cx;
	int Cy;
public:
	ActionAddCopy(ApplicationManager* pApp);
	

	~ActionAddCopy(void); 
	virtual void Execute();              //Execute action

	virtual void Undo();
	virtual void Redo();
};

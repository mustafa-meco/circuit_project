#pragma once
#include "../circuit_project/ApplicationManager.h"
#include "../circuit_project/Actions/Action.h" 
#include "../circuit_project/Components/Component.h"
class ActionAddCut : public Action
{
	int Cx;
	int Cy;
public:
	ActionAddCut(ApplicationManager* pApp);

	~ActionAddCut(void);
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
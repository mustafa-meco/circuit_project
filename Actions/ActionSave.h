#pragma once
#include "Action.h"

class ActionSave : public Action
{
public:
	ActionSave(ApplicationManager* pApp);//constructor
	virtual ~ActionSave();//destructor
	virtual void Execute();

	void Undo();// undo for the save


	void Redo();//Redo for the save

private:

};

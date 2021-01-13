#pragma once
#include "../ApplicationManager.h"
#include "Action.h"
//#include "../circuit_project/ApplicationManager.h"
//#include "../circuit_project/Actions/Action.h" 
class ActionAddCopy : public Action
{
	int Cx; //center points of the components
	int Cy;
public:
	ActionAddCopy(ApplicationManager* pApp);//constructor

	

	~ActionAddCopy(void); //destructor 

	virtual void Execute();              //Execute action

	virtual void Undo(); //undo for copy

	virtual void Redo(); //Redo for the copy 

};


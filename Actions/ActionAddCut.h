#pragma once
#include "../ApplicationManager.h"
#include "Action.h" 
#include "../Components/Component.h"
class ActionAddCut : public Action
{
	int C1, C2;
	int Cx; // points of centre
	int Cy;

	//undo redo for componnents
	Component* temp1;
	Connection* temp3[10];
	Connection* temp4[10];
	Connection* undo1[10];
	Connection* undo2[10];
	TerminalNum tt1[10];
	TerminalNum tt2[10];

	Component* comp2;

public:
	ActionAddCut(ApplicationManager* pApp);//constructor


	~ActionAddCut(void);//destructor 

	virtual void Execute(); //Execute action

	virtual void Undo(); //undo for cut 

	virtual void Redo();//Redo for cut
};

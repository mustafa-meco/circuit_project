#pragma once
#include "Action.h"
#include"../Components/Component.h"


//Class responsible for adding a new resistor action
class ActionLabel : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionLabel(ApplicationManager* pApp);//constructor

	virtual ~ActionLabel (void);//destructor 


	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();//undo for the label
	virtual void Redo();  //Redo for the label 
};

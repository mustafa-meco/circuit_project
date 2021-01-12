#pragma once
#include "Action.h"
#include"../Components/Module.h"
#include "../ApplicationManager.h"
#include <fstream>
class ActionAddDesignedModule :
    public Action
{
private:
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	Component* comp; // pointer to component
	GraphicsInfo* undo1; //save the graphics info to do undo or redo 
	// to store value of the component
	double undo2;
public:
	ActionAddDesignedModule(ApplicationManager* pApp);//constructor

	~ActionAddDesignedModule(void);//destructor 

	virtual void Execute();

	virtual void Undo(); //undo for the DesignedModule

	virtual void Redo(); //redo for the DesignedModule

};

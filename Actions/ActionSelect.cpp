#include "Action.h"
#include"ActionSelect.h"

#include<iostream>

ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{}
ActionSelect::~ActionSelect(void)
{}

void ActionSelect::Execute()
{
    UI* pUI = pManager->GetUI();
	pUI->PrintMsg("select a component");
	pUI->GetPointClicked(cx,cy);
	comp = pManager->GetComponentByCordinates(cx, cy);
	connection = pManager->GetConnectionByCordinates(cx, cy);
	//double intValue = comp->getValue();
	//std::string striValue = std::to_string(intValue);
	if (comp)
	{
		pUI->PrintMsg("label: " + comp->getlabel());// + "              Value is: " + striValue);
	}
}


void ActionSelect::Undo() {}
void ActionSelect::Redo() {}
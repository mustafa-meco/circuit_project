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
	
	if (comp)
	{
		
		/*std::string striValue = std::to_string(comp->getValue());*/
		double Value = -1;
		if (comp->getResistance() !=0)
		{
			comp->getResistance();
			 Value = comp->getResistance();
		}
		else if ( comp->getSourceVoltage()!=0)
		{
			comp->getSourceVoltage();
		    Value = comp->getSourceVoltage();
		}
		std::string striValue = std::to_string(Value);
		pUI->PrintMsg("label: " + comp->getlabel() + "              Value is: " + striValue );
	}
}


void ActionSelect::Undo() {}
void ActionSelect::Redo() {}
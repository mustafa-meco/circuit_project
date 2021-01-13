#include "ActionVoltmeter.h"
#include"../ApplicationManager.h"

ActionVoltmeter::ActionVoltmeter(ApplicationManager* pApp) :Action(pApp)
{
}
ActionVoltmeter::~ActionVoltmeter(void)
{
}

//Execute action (code depends on action type)
void ActionVoltmeter::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("select a component to print voltage");
	pUI->GetPointClicked(Cx, Cy);

	Component* comp = pManager->GetComponentByCordinates(Cx, Cy);
	if (comp != nullptr)
	{
		double x = comp->getTerm2Volt() - comp->getTerm1Volt();
		abs(x);
		string s = to_string(x);
		pUI->PrintMsg(s);
	}
}

void ActionVoltmeter::Undo()
{
}
void ActionVoltmeter::Redo()
{
}
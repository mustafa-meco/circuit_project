#include "ActionAmmeter.h"
#include "../ApplicationManager.h"
#include"..\Components\Component.h"

ActionAmmeter::ActionAmmeter(ApplicationManager * pApp) :Action(pApp)
{
}

ActionAmmeter::~ActionAmmeter(void)
{
}

void ActionAmmeter::Execute()
{
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	//Print Action Message
	pUI->PrintMsg("Choose Component to show its current");
	do {
		pUI->GetPointClicked(Cx, Cy);
	} while (!pManager->GetComponentByCordinates(Cx, Cy));
	pUI->PrintMsg("the current: " + to_string(pManager->CalculateCurrent()));
	//Clear Status Bar
	pUI->ClearStatusBar();
}

void ActionAmmeter::Undo()
{
}

void ActionAmmeter::Redo()
{}
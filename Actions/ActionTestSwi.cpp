#include "ActionTestSwi.h"
#include "Action.h"
#include"../ApplicationManager.h"
#include"../Components/Switch.h"

#include<iostream>

ActionTestSwi::ActionTestSwi(ApplicationManager* pApp) :Action(pApp)
{}
ActionTestSwi::~ActionTestSwi(void)
{}

void ActionTestSwi::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("select a Switch");
	pUI->GetPointClicked(cx, cy);
	comp = pManager->GetComponentByCordinates(cx, cy);

	Switch* test = dynamic_cast<Switch*>(comp);
	if (pManager->isSim() && test != nullptr)
	{
		string sS;             // Checking if the switch is open or closed. 
		bool isBool;
		bool S;
		do {
			pUI->PrintMsg("Enter the value of the switch (0: opened, 1: closed)");
			sS = pUI->GetSrting();
			isBool = false;
			if (sS == "0" || sS == "1") {
				isBool = true;
				S = static_cast<bool>(stoi(sS));
			}
		} while (!isBool);

		test->setStatus(S);
		pManager->operation();
	}
}


void ActionTestSwi::Undo() {}
void ActionTestSwi::Redo() {}
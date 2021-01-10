#include "ActionMove.h"
#include "../ApplicationManager.h"
#include<iostream>
using namespace std;
ActionMove::ActionMove(ApplicationManager* pApp) :Action(pApp)
{

}

ActionMove::~ActionMove(void)
{
}

void ActionMove::Execute()
{

	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("move any ");
	pUI->GetPointClicked(cx, cy);

	pUI->ClearStatusBar();
	comp = pManager->GetComponentByCordinates(cx, cy);
	int x = cy, y = cx;
	buttonstate c;
	if (comp != nullptr)
	{
		do
		{
			pUI->detectMouse(cx, cy);
			c = pUI->getbuttonstate(LEFT_BUTTON, x, y);
			comp->setm_pGfxInfo(cx, cy);
			pManager->UpdateInterface();
		} while (c == BUTTON_UP);
	}
}

void ActionMove::Undo()
{}

void ActionMove::Redo()
{}
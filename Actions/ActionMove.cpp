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
	undo1=comp->getm_pGfxInfo();
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
{
	GraphicsInfo* temp= comp->getm_pGfxInfo();
	comp->setm_pGfxInfo((undo1->PointsList[1].x + undo1->PointsList[0].x)/2, (undo1->PointsList[1].y + undo1->PointsList[0].y)/2);
	undo1 = temp;
}

void ActionMove::Redo()
{
	GraphicsInfo* temp = comp->getm_pGfxInfo();
	comp->setm_pGfxInfo((undo1->PointsList[1].x + undo1->PointsList[0].x) / 2, (undo1->PointsList[1].y + undo1->PointsList[0].y) / 2);
	undo1 = temp;
}
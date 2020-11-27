#include "ActionAddSwi.h"
#include "../ApplicationManager.h"

ActionAddSwi::ActionAddSwi(ApplicationManager* pApp) :Action(pApp) 
{

}

ActionAddSwi::~ActionAddSwi(void)
{
}

void ActionAddSwi::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new switch: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);
	while (!(Cy > 80 + 50 / 2 &&
		Cy < 650 - 50 - 50 / 2 &&
		Cx>50 / 2 &&
		Cx < 1200 - 80 / 2))
	{
		pUI->GetPointClicked(Cx, Cy);
	}
	//Clear Status Bar
	pUI->ClearToolBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Switch* pS = new Switch(pGInfo, pUI);
	pManager->AddComponent(pS);
}

void ActionAddSwi::Undo()
{}

void ActionAddSwi::Redo()
{}


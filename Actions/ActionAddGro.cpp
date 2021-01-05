
#include "..\ApplicationManager.h"
#include "ActionAddGro.h"

ActionAddGro::ActionAddGro(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddGro::~ActionAddGro(void)
{
}

void ActionAddGro::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new ground:Click any where to add");
	

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
	pUI->ClearStatusBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = (Cx - compWidth/2);
	pGInfo->PointsList[0].y = (Cy - compHeight/2);
	pGInfo->PointsList[1].x = (Cx + compWidth/2);
	pGInfo->PointsList[1].y = (Cy + compHeight/2);

	Ground* pR = new Ground(pGInfo);
	pManager->AddComponent(pR);
}

void ActionAddGro::Undo()
{}

void ActionAddGro::Redo()
{}
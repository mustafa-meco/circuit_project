#include "ActionAddBul.h"
#include "../ApplicationManager.h"

ActionAddBul::ActionAddBul(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddBul::~ActionAddBul(void)
{
}

void ActionAddBul::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new bulb: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
<<<<<<< HEAD
	pUI->GetPointClicked(Cx, Cy); 

=======
	pUI->GetPointClicked(Cx, Cy);
	while (!(Cy > 80 + 50 / 2 &&
		Cy < 650 - 50 - 50 / 2 &&
		Cx>50 / 2 &&
		Cx < 1200 - 80 / 2))
	{
		pUI->GetPointClicked(Cx, Cy);
	}
>>>>>>> 5d071cea8a107f807d0ea9113e28a43418a987dc
	//Clear Status Bar
	pUI->ClearStatusBar();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;
	
	Bulb* pB = new Bulb(pGInfo, pUI);
	
	pManager->AddComponent(pB);
}

void ActionAddBul::Undo()
{}

void ActionAddBul::Redo()
{}


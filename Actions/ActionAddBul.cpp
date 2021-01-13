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
	pUI->GetPointClicked(Cx, Cy); 

	pUI->GetPointClicked(Cx, Cy);
	while (!(Cy > pUI->getToolBarHeight() + pUI->getCompHeight() / 2
		&& Cy < pUI->getHeight() - pUI->getStatusBarHeight() - pUI->getCompHeight() / 2
		&& Cx>pUI->getCompWidth() / 2
		&& Cx < pUI->getWidth() - pUI->getToolItemWidth() / 2))
	{
		pUI->GetPointClicked(Cx, Cy);
	}

	string sR;
	bool isNumber;
	do {
		pUI->PrintMsg("Enter the value of the source voltage(enter a number): ");
		sR = pUI->GetSrting();
		isNumber = true;
		for (int i = 0; i < sR.length(); i++)
			if (isdigit(sR[i]) == false)
				isNumber = false;
	} while (!isNumber || stod(sR) <= 0);

	
	double R = stod(sR);

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
	
	Bulb* pB = new Bulb(pGInfo/*, R*/);
	pB->setResistance(R);
	pManager->AddComponent(pB);
	comp = pB;
	undo1 = pGInfo;
	undo2 = R;
}

void ActionAddBul::Undo()
{
	pManager->deleteCompounent(comp);
}

void ActionAddBul::Redo()
{
	Bulb* pR = new Bulb(undo1/*, undo2*/);
	pR->setSourceVoltage(undo2);
	pManager->AddComponent(pR);
}


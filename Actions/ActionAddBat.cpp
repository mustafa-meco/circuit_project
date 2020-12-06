
#include "..\ApplicationManager.h"
#include "ActionAddBat.h"

ActionAddBat::ActionAddBat(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddBat::~ActionAddBat(void)
{
}

void ActionAddBat::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new battery: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	
	pUI->GetPointClicked(Cx, Cy);
	while (!(Cy > 80 + 50 / 2 &&
		Cy < 650 - 50 - 50 / 2 &&
		Cx>50 / 2 &&
		Cx < 1200 - 80 / 2))
	{
		pUI->GetPointClicked(Cx, Cy);
	}
	string sV;
	bool isNumber;
	do {
		pUI->PrintMsg("Enter the value of the source voltage(enter a number): ");
		sV = pUI->GetSrting();
		isNumber = true;
		for (int i = 0; i < sV.length(); i++)
			if (isdigit(sV[i]) == false)
				isNumber = false;
	} while (!isNumber);

	double V = stod(sV);
	

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

	Battery* pR = new Battery(pGInfo/*, V*/);
	pR->setSourceVoltage(V);
	pManager->AddComponent(pR);
}

void ActionAddBat::Undo()
{}

void ActionAddBat::Redo()
{}
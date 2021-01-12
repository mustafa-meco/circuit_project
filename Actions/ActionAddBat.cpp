
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
	pUI->PrintMsg("Adding a new resistor: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	
	pUI->GetPointClicked(Cx, Cy);
	//pManager->GetComponentByCordinates(Cx, Cy);

	/*int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();*/
	//pGInfo->PointsList[0].y = comp->getCompCentery(pUI);
	//pGInfo->PointsList[1].y = comp->getCompCentery(pUI);

	while (!(Cy > pUI->getToolBarHeight() + pUI->getCompHeight() / 2
		&& Cy < pUI->getHeight() - pUI->getStatusBarHeight() - pUI->getCompHeight() / 2
		&& Cx>pUI->getCompWidth() / 2
		&& Cx < pUI->getWidth() - pUI->getToolItemWidth() / 2)
		)
	{
		pUI->GetPointClicked(Cx, Cy);
	}
	//pManager->GetComponentByCordinates(Cx, Cy);

	/*	for (int i = 0; i < ; i++)
		{
			if ()
			{
			}
		}*/


	string sS;                          // determine the polarity direction 
	bool isBool;
	bool SP;
	do {
		pUI->PrintMsg("Enter the value of the battery (0: rightToLeft, 1: LeftToRight)");
		sS = pUI->GetSrting();
		isBool = false;
		if (sS == "0" || sS == "1") {
			isBool = true;
			SP = static_cast<bool>(stoi(sS));
		}
	} while (!isBool);

	//Clear Status Bar
	pUI->ClearStatusBar();





	string sV;
	bool isNumber;                    // putting a value for the battery 
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

	Battery* pR = new Battery(pGInfo/*, V*/);     // the voltage value depends on the direction of the battery 
	if (SP==LTR) 
	{
		pR->setSourceVoltage(V);
    }
	else 
	{
		pR->setSourceVoltage(-V);
	}
	pManager->AddComponent(pR);
}

void ActionAddBat::Undo()
{}

void ActionAddBat::Redo()
{}
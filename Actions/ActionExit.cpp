#include "ActionExit.h"
#include "../ApplicationManager.h"
#include"..\Components\Component.h"

ActionExit::ActionExit(ApplicationManager* pApp) :Action(pApp)
{
}

ActionExit::~ActionExit(void)
{
}

void ActionExit::Execute()
{

	////Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	////Print Action Message
	//pUI->PrintMsg("Adding a new resistor: Click anywhere to add");
	////Get Center point of the area where the Comp should be drawn
	//pUI->GetPointClicked(Cx, Cy);
	//while (!(Cy > 80 + 50 / 2 &&
	//	Cy < 650 - 50 - 50 / 2 &&
	//	Cx>50 / 2 &&
	//	Cx < 1200 - 80 / 2))
	//{
	//	pUI->GetPointClicked(Cx, Cy);
	//}
	////Clear Status Bar
	//pUI->ClearStatusBar();

	//Resistor* pR = new Resistor(pGInfo, pUI);
	//pManager->AddComponent(pR);
	//delete pManager;


	delete pManager;
	pManager=nullptr;
}

void ActionExit::Undo()
{}

void ActionExit::Redo()
{}

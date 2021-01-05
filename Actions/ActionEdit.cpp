#include "ActionEdit.h"
#include "../ApplicationManager.h"


ActionEdit::ActionEdit(ApplicationManager * pApp) :Action(pApp)
{

}

ActionEdit::~ActionEdit(void)
{
}

void ActionEdit::Execute()
{
	int x = 0;
	int y = 0;
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Edit");
	
	/*pUI->PrintMsg("select a component");*/
	pUI->GetPointClicked(x,y);
    Component* comp= pManager->GetComponentByCordinates(x, y);
	Connection* connection = pManager->GetConnectionByCordinates(x, y);
	if (comp != nullptr)
	{	//comp->selection();

		pUI->PrintMsg("Choose 1 to Edit the label or choose 2 to Edit the value");
		string r = pUI->GetSrting();
		if (r == ("1"))
		{
			pUI->PrintMsg("enter the new label");
			comp->Setlabel(pUI->GetSrting());

			pUI->ClearStatusBar();

		}
    }
	else if(connection!=nullptr)
	{
		pUI->PrintMsg("choose the component that you want to change");
		pUI->GetPointClicked(x, y);
		Component* component1 = pManager->GetComponentByCordinates(x, y);

		Component* compConnect= connection->getOtherComponent(component1);
		pUI->PrintMsg("choose the componet the component to be connect ");
		pUI->GetPointClicked(x, y);
		Component* component2 = pManager->GetComponentByCordinates(x, y);
		GraphicsInfo* pGInfo = new GraphicsInfo(1); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
		int compWidth = pUI->getCompWidth();
		int compHeight = pUI->getCompHeight();
		
		pGInfo->PointsList[0].y = component2->getCompCentery(pUI);
		
		if (x < component2->getCompCenterx(pUI))
		{
			pGInfo->PointsList[0].x = component2->getCompCenterx(pUI) - compWidth / 2;
		}
		else
		{
			pGInfo->PointsList[0].x = component2->getCompCenterx(pUI) + compWidth / 2;
		}
		connection->EditConnection(compConnect, component2, pGInfo,pUI);
		pUI->ClearStatusBar();

	}



	//pUI->PrintMsg(Component::Setlabel());
	

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	
}

void ActionEdit::Undo()
{}

void ActionEdit::Redo()
{}


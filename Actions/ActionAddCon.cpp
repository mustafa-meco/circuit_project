
#include"..\Actions\ActionAddCon.h" 
#include "..\ApplicationManager.h" 


#include "../Components/Component.h"
ActionAddCon::ActionAddCon(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddCon::~ActionAddCon(void)
{
}

void ActionAddCon::Execute()
{
	

	
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg(" choose two points for connection : ");
	do
	{

		pUI->GetPointClicked(Cx1, Cy1);
		comp1 = pManager->GetComponentByCordinates(Cx1, Cy1);
		//comp1->addTerm1Connection();
	} while (comp1 == nullptr);

	
	do
	{

	
	pUI->PrintMsg(" You Choose the first point, now choose the second one : "); 

	pUI->GetPointClicked(Cx2, Cy2);
	comp2=pManager->GetComponentByCordinates(Cx2, Cy2); 
	pUI->ClearStatusBar(); 
	} while (comp2 == nullptr || comp2==comp1);

	




	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
	pGInfo->PointsList[0].y = comp1->getCompCentery(pUI);
	pGInfo->PointsList[1].y = comp2->getCompCentery(pUI);
	if (Cx1 < comp1->getCompCenterx(pUI))
	{
		pGInfo->PointsList[0].x = comp1->getCompCenterx(pUI)-compWidth/2;
	}
	else 
	{
		pGInfo->PointsList[0].x = comp1->getCompCenterx(pUI) + compWidth/2;
	}	
	if (Cx1 < comp2->getCompCenterx(pUI))
	{
		pGInfo->PointsList[1].x = comp2->getCompCenterx(pUI) - compWidth/2;
	}
	else
	{
		pGInfo->PointsList[1].x = comp2->getCompCenterx(pUI) + compWidth/2;
	}
	pUI->PrintMsg(to_string(comp1->getCompCenterx(pUI)+comp2-> getCompCentery(pUI)));
	//pUI->PrintMsg(to_string(pGInfo->PointsList[0].x)+ to_string(pGInfo->PointsList[0].y)+ to_string(pGInfo->PointsList[1].x)+ to_string(pGInfo->PointsList[1].y));
    /*pUI->PrintMsg(to_string(pGInfo->PointsList[0].y));
	pUI->PrintMsg(to_string(pGInfo->PointsList[1].x));
	pUI->PrintMsg(to_string(pGInfo->PointsList[1].y));*/


	//pGInfo->PointsList[0].x = Cx1; 
	//pGInfo->PointsList[0].y = Cy1;
	//pGInfo->PointsList[1].x = Cx2;
	//pGInfo->PointsList[1].y = Cy2;

	Connection* pCON = new Connection(pGInfo, comp1, comp2);
	//pUI->PrintMsg(to_string(comp1->getResistance()));

	//pUI->DrawConnection(*pGInfo);
	pManager->AddConnection(pCON);  
} 













void ActionAddCon::Undo()
{}

void ActionAddCon::Redo()
{}
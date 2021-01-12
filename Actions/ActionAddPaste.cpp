#include "ActionAddPaste.h"
#include "../Components/Resistor.h"


ActionAddPaste::ActionAddPaste(ApplicationManager* pApp) : Action(pApp)
{
}

ActionAddPaste::~ActionAddPaste(void)
{

}
void ActionAddPaste::Execute() //Execute action
{

	UI* pUI = pManager->GetUI(); 
	pUI->PrintMsg("Select a place to paste your component : ");     
	while (!(Cy > pUI->getToolBarHeight() + pUI->getCompHeight() / 2
		&& Cy < pUI->getHeight() - pUI->getStatusBarHeight() - pUI->getCompHeight() / 2
		&& Cx>pUI->getCompWidth() / 2
		&& Cx < pUI->getWidth() - pUI->getToolItemWidth() / 2))// (!(Cy > 80 + 50 / 2 &&                                // Check if the place between the boundary or not 
	//	Cy < 650 - 50 - 50 / 2 &&
	//	Cx>50 / 2 &&
	//	Cx < 1200 - 80 / 2))
	{
		pUI->GetPointClicked(Cx, Cy);
	}
	
	GraphicsInfo* pGInfo = new GraphicsInfo(2); 
	
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
	
	pGInfo->PointsList[0].x = Cx - compWidth / 2;                // Creating a graphics info for the new place
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Component* ptrCOMP=nullptr; 					   	
	/*pManager->GetCopyComp()->Copy(ptrCOMP);*/
//	ptrCOMP->SetGinfo(pGInfo);
	
	if (pManager->GetCopyComp() ==nullptr)                        // showing a window if there is no comp to paste
	{
		pUI->ClearStatusBar();
		pUI->CreateErrorWind("error \n");
	}
	else
	{
		ptrCOMP = pManager->GetCopyComp()/*->Copy(ptrCOMP)*/;     // Paste the component after taking its graphics info 
		//Component* ptrCOMP=nullptr; 					   	  
        //pManager->GetCopyComp()->Copy(ptrCOMP);
		ptrCOMP->SetGinfo(pGInfo);
		pManager->AddComponent(ptrCOMP);
		pUI->ClearStatusBar();


		comp1 = ptrCOMP;
	}
	
	
	
	//if (pManager->ComponentData.COMPNAME == "RES" )
	//{
	//	Resistor* pR = new Resistor(pGInfo);
	//	pR->setResistance(pManager->ComponentData.COMPvalueRESIS);			//TAYIL74
	//	pR->setSourceVoltage(pManager->ComponentData.COMPvalueVOLT);	    //TAYIL74
	//	//label
	//	pManager->AddComponent(pR); 
	//}
	//if (pManager->ComponentData.COMPNAME == "BLB")
	//{
	//	Bulb* pR = new Bulb(pGInfo);
	//	pR->setResistance(pManager->ComponentData.COMPvalueRESIS);          //TAYIL74
	//	pR->setSourceVoltage(pManager->ComponentData.COMPvalueVOLT);		//TAYIL74
	//			//label
	//	pManager->AddComponent(pR);
	//}
	//if (pManager->ComponentData.COMPNAME == "BUZ")
	//{
	//	Buzzer* pR = new Buzzer(pGInfo);
	//	pR->setResistance(pManager->ComponentData.COMPvalueRESIS);			//TAYIL74
	//	pR->setSourceVoltage(pManager->ComponentData.COMPvalueVOLT);		//TAYIL74
	//			//label
	//	pManager->AddComponent(pR);
	//}
	//if (pManager->ComponentData.COMPNAME == "SWT")
	//{
	//	Switch* pR = new Switch(pGInfo);
	//	pR->setResistance(pManager->ComponentData.COMPvalueRESIS);			//TAYIL74
	//	pR->setSourceVoltage(pManager->ComponentData.COMPvalueVOLT);		//TAYIL74
	//			//label
	//	pManager->AddComponent(pR);
	//}
	//if (pManager->ComponentData.COMPNAME == "GND")
	//{
	//	Ground* pR = new Ground(pGInfo);
	//	pR->setResistance(pManager->ComponentData.COMPvalueRESIS);			//TAYIL74
	//	pR->setSourceVoltage(pManager->ComponentData.COMPvalueVOLT);		//TAYIL74
	//			//label
	//	pManager->AddComponent(pR);
	//}
	//if (pManager->ComponentData.COMPNAME == "BAT")
	//{
	//	Battery* pR = new Battery(pGInfo);
	//	pR->setResistance(pManager->ComponentData.COMPvalueRESIS);			//TAYIL74
	//	pR->setSourceVoltage(pManager->ComponentData.COMPvalueVOLT);		//TAYIL74
	//			//label
	//	pManager->AddComponent(pR);
	//}
	//if (pManager->ComponentData.COMPNAME == "FUS")
	//{
	//	Fues* pR = new Fues(pGInfo);
	//	pR->setResistance(pManager->ComponentData.COMPvalueRESIS);			//TAYIL74
	//	pR->setSourceVoltage(pManager->ComponentData.COMPvalueVOLT);		//TAYIL74
	//			//label
	//	pManager->AddComponent(pR);
	//}
	//
}

void ActionAddPaste::Undo()
{
	//ln
	comp2 = comp1->Copy();
	pManager->deleteCompounent(comp1);
}

void ActionAddPaste::Redo()
{
	comp1 = comp2;
	pManager->AddComponent(comp1);
}

#include "ActionAddPaste.h"
#include "../Components/Resistor.h"


ActionAddPaste::ActionAddPaste(ApplicationManager* pApp) : Action(pApp)
{
}

ActionAddPaste::~ActionAddPaste(void)
{

}
void ActionAddPaste::Execute()
{

	UI* pUI = pManager->GetUI(); 
	pUI->PrintMsg("Select a place to paste your component : ");
	while (!(Cy > 80 + 50 / 2 &&
		Cy < 650 - 50 - 50 / 2 &&
		Cx>50 / 2 &&
		Cx < 1200 - 80 / 2))
	{
		pUI->GetPointClicked(Cx, Cy);
	}
	
	GraphicsInfo* pGInfo = new GraphicsInfo(2); 
	
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
	
	pGInfo->PointsList[0].x = Cx - compWidth / 2; 
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Component* ptrCOMP = pManager->GetCopyComp();					   	   //TAYIL74


	if (ptrCOMP==NULL)
	{
		pUI->ClearStatusBar();
		pUI->CreateErrorWind("error \n");
	}
	else
	{
		ptrCOMP->SetGinfo(pGInfo);
		pManager->AddComponent(ptrCOMP);
		pUI->ClearStatusBar();
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

}

void ActionAddPaste::Redo()
{

}

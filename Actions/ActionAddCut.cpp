#include "ActionAddCopy.h"
#include "Action.h"
#include"ActionAddBat.h"
#include "ActionAddBul.h"
#include "ActionAddBuz.h"
#include "ActionAddFues.h"
#include "ActionAddGro.h"
#include "ActionAddRes.h"
#include "ActionAddSwi.h"
#include "ActionAddCut.h"
#include "UI/UI.h"

ActionAddCut::ActionAddCut(ApplicationManager* pApp) : Action(pApp)
{

}

ActionAddCut::~ActionAddCut(void)
{

}
void ActionAddCut::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Select component for cutting : ");

	pUI->GetPointClicked(Cx, Cy);
	pUI->ClearStatusBar();															//TAYIL74
 	Component* ptrComp = pManager->GetComponentByCordinates(Cx, Cy);

	Connection* ptConnection = dynamic_cast<Connection*>(ptrComp);                 //TAYIL74
	
	/*Resistor* ptResistor = dynamic_cast<Resistor*>(ptrComp);
	Bulb* ptBulb = dynamic_cast<Bulb*>(ptrComp);
	Buzzer* ptBuzzer = dynamic_cast<Buzzer*>(ptrComp);
	Battery* ptBattery = dynamic_cast<Battery*>(ptrComp);
	Switch* ptSwitch = dynamic_cast<Switch*>(ptrComp);
	Ground* ptGround = dynamic_cast<Ground*>(ptrComp);
	Fues* ptFues = dynamic_cast<Fues*>(ptrComp);*/

	if (ptrComp == NULL)															//TAYIL74
	{
		pUI->PrintMsg("NO component is selected: ");
	}

	if (ptConnection != NULL)
	{
		pUI->PrintMsg("It is not allowed to cut a connection : ");					//TAYIL74
	}
	else																			//TAYIL74
	{
		pManager->SetCopyComp(ptrComp);
	}
	//if (ptResistor != NULL)
	//{
	//	pManager->ComponentData.COMPNAME = "RES";
	//	pManager->ComponentData.COMPvalueRESIS = ptrComp->getResistance();			//TAYIL74
	//	pManager->ComponentData.COMPvalueVOLT = ptrComp->getSourceVoltage();		//TAYIL74
	//	//pManager->ComponentData.COMPLABEL = ptrComp->;
	//}
	//if (ptBulb != NULL)
	//{
	//	pManager->ComponentData.COMPNAME = "BLB";
	//	pManager->ComponentData.COMPvalueRESIS = ptrComp->getResistance();			//TAYIL74
	//	pManager->ComponentData.COMPvalueVOLT = ptrComp->getSourceVoltage();		//TAYIL74
	//	//pManager->ComponentData.COMPLABEL = ptrComp->;
	//}
	//if (ptBuzzer != NULL)
	//{
	//	pManager->ComponentData.COMPNAME = "BUZ";
	//	pManager->ComponentData.COMPvalueRESIS = ptrComp->getResistance();			//TAYIL74
	//	pManager->ComponentData.COMPvalueVOLT = ptrComp->getSourceVoltage();		//TAYIL74
	//	//pManager->ComponentData.COMPLABEL = ptrComp->;
	//}
	//if (ptBattery != NULL)
	//{
	//	pManager->ComponentData.COMPNAME = "BAT";
	//	pManager->ComponentData.COMPvalueRESIS = ptrComp->getResistance();			//TAYIL74
	//	pManager->ComponentData.COMPvalueVOLT = ptrComp->getSourceVoltage();		//TAYIL74
	//	//pManager->ComponentData.COMPLABEL = ptrComp->;
	//}
	//if (ptSwitch != NULL)
	//{
	//	pManager->ComponentData.COMPNAME = "SWT";
	//	pManager->ComponentData.COMPvalueRESIS = ptrComp->getResistance();			//TAYIL74
	//	pManager->ComponentData.COMPvalueVOLT = ptrComp->getSourceVoltage();		//TAYIL74
	//	//pManager->ComponentData.COMPLABEL = ptrComp->;
	//}

	//if (ptGround != NULL)
	//{
	//	pManager->ComponentData.COMPNAME = "GND";
	//	pManager->ComponentData.COMPvalueRESIS = ptrComp->getResistance();			//TAYIL74
	//	pManager->ComponentData.COMPvalueVOLT = ptrComp->getSourceVoltage();		//TAYIL74
	//	//pManager->ComponentData.COMPLABEL = ptrComp->;
	//}
	//if (ptFues != NULL)
	//{
	//	pManager->ComponentData.COMPNAME = "FUS";
	//	pManager->ComponentData.COMPvalueRESIS = ptrComp->getResistance();			//TAYIL74
	//	pManager->ComponentData.COMPvalueVOLT = ptrComp->getSourceVoltage();		//TAYIL74
	//	//pManager->ComponentData.COMPLABEL = ptrComp->;
	//}

}

void ActionAddCut::Undo()
{

}
void  ActionAddCut::Redo() {

}
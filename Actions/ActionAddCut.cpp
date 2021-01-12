//#include "../circuit_project/ActionAddCopy.h"
//#include "Actions/Action.h"
//#include"Actions/ActionAddBat.h"
//#include "Actions/ActionAddBul.h"
//#include "Actions/ActionAddBuz.h"
//#include "Actions/ActionAddFues.h"
//#include "Actions/ActionAddGro.h"
//#include "Actions/ActionAddRes.h"
//#include "Actions/ActionAddSwi.h"
//#include "ActionAddCut.h"
//#include "UI/UI.h"
#include "ActionAddCut.h"
#include "Action.h"

#include "../UI/UI.h"

ActionAddCut::ActionAddCut(ApplicationManager* pApp) : Action(pApp)
{

}

ActionAddCut::~ActionAddCut(void)
{

}
void ActionAddCut::Execute() //Execute action 
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Select component for cutting : "); 

	pUI->GetPointClicked(Cx, Cy);                                              // indicate where  the user clicks
	pUI->ClearStatusBar();															
 	Component* ptrComp = pManager->GetComponentByCordinates(Cx, Cy);            //knowing the comp type

	Connection* ptConnection = dynamic_cast<Connection*>(ptrComp);              //check if the user select a connection 
	
	/*Resistor* ptResistor = dynamic_cast<Resistor*>(ptrComp);
	Bulb* ptBulb = dynamic_cast<Bulb*>(ptrComp);
	Buzzer* ptBuzzer = dynamic_cast<Buzzer*>(ptrComp);
	Battery* ptBattery = dynamic_cast<Battery*>(ptrComp);
	Switch* ptSwitch = dynamic_cast<Switch*>(ptrComp);
	Ground* ptGround = dynamic_cast<Ground*>(ptrComp);
	Fues* ptFues = dynamic_cast<Fues*>(ptrComp);*/
	while(ptrComp == nullptr)
	{

	if (ptConnection != NULL)              // showing a message to prevent the user from cutting the connection
	{
		pUI->PrintMsg("It is not allowed to cut a connection : ");
		
	}

	if (ptrComp == NULL)                   // showing a message to tell the user that no comp is selected 
	{
		pUI->PrintMsg("NO component is selected: ");
	}
	else								  // Cut the component 										
		if (ptrComp == nullptr)															//TAYIL74
		{
			pUI->PrintMsg("NO component is selected: ");
		}
		else if (ptConnection != nullptr)
		{
			pUI->PrintMsg("It is not allowed to cut a connection : ");					//TAYIL74
		}
		pUI->GetPointClicked(Cx, Cy);														//TAYIL74
		ptrComp = pManager->GetComponentByCordinates(Cx, Cy);
		ptConnection = dynamic_cast<Connection*>(ptrComp);
	}
	pUI->ClearStatusBar();
	pManager->SetCopyComp(ptrComp);
	comp2 = ptrComp->Copy();
	C1 = ptrComp->getTermConnCount(TERM1);
	C2 = ptrComp->getTermConnCount(TERM2);
	for (int i = 0; i < 10; i++)
	{
		undo1[i] = nullptr;
		undo2[i] = nullptr;
	}
	
	for (int i = 0; i < C1; i++)
	{
		undo1[i] = ptrComp->getTermConnections(TERM1)[i]->copyconnection();;
	}

	for (int i = 0; i < C2; i++)
	{
		undo2[i] = ptrComp->getTermConnections(TERM2)[i]->copyconnection();
	}
	pManager->deleteCompounent(ptrComp);

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
	if (comp2 != nullptr)
	{
		pManager->AddComponent(comp2);
		for (int y = 0; y < C1; y++)
		{

			pManager->AddConnection(undo1[y]);
		}
		for (int y = 0; y < C2; y++)
		{
			pManager->AddConnection(undo2[y]);
		}
	}
}
void  ActionAddCut::Redo() 
{
	if (comp2 != nullptr)
		temp1 = comp2->Copy();
	pManager->deleteCompounent(comp2);
	comp2 = temp1;
}
//#include "../circuit_project/ActionAddCopy.h"
//#include "Actions/Action.h"
//#include"Actions/ActionAddBat.h"
//#include "Actions/ActionAddBul.h"
//#include "Actions/ActionAddBuz.h"
//#include "Actions/ActionAddFues.h"
//#include "Actions/ActionAddGro.h"
//#include "Actions/ActionAddRes.h"
//#include "Actions/ActionAddSwi.h"
//#include "UI/UI.h"
#include "ActionAddCopy.h"
#include "Action.h"
#include "ActionAddBat.h"
#include "ActionAddBuz.h" 
#include "ActionAddBul.h"
#include "ActionAddFues.h"
#include "ActionAddGro.h"
#include "ActionAddRes.h"
#include "ActionAddSwi.h"
#include "../UI/UI.h"

ActionAddCopy::ActionAddCopy(ApplicationManager* pApp) : Action(pApp)
{

}

ActionAddCopy::~ActionAddCopy(void)
{

}
void ActionAddCopy::Execute()                       //Execute action 
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Select component for copying : ");

	pUI->GetPointClicked(Cx, Cy);                   // indicate where  the user clicks
	pUI->ClearStatusBar();															
	// do while
	Component * ptrComp = pManager->GetComponentByCordinates(Cx, Cy);        //knowing the comp type
	
	Connection* ptConnection = dynamic_cast<Connection*>(ptrComp);           //check if the user select a connection 

	//Resistor* ptResistor = dynamic_cast< Resistor *>(ptrComp);
	//Bulb* ptBulb = dynamic_cast<Bulb*>(ptrComp);
	//Buzzer* ptBuzzer= dynamic_cast<Buzzer*>(ptrComp);
	//Battery* ptBattery = dynamic_cast<Battery*>(ptrComp);
	//Switch* ptSwitch = dynamic_cast<Switch*>(ptrComp);
	//Ground* ptGround = dynamic_cast<Ground*>(ptrComp);
	//Fues* ptFues = dynamic_cast<Fues*>(ptrComp);
 	
	
	 if (ptConnection != NULL)                       // showing a message to prevent the user from cutting the connection
	 {
		 pUI->PrintMsg("It is not allowed to copy a connection : ");					
	 }
	 
	 if (ptrComp == NULL)		                     // showing a message to tell the user that no comp is selected 
	 {
		 pUI->PrintMsg("NO component is selected: ");
	 }
	 else								          // Copy the component 			
	 {
		pManager->SetCopyComp(ptrComp);            
	 }
		 //ptrComp->Copy(ptrComp);
	 //if (ptResistor!=NULL)
	 //{
		// pManager->ComponentData.COMPNAME = "RES";
		// pManager->ComponentData.COMPvalueRESIS = ptrComp->getResistance();			//TAYIL74
		// pManager->ComponentData.COMPvalueVOLT = ptrComp->getSourceVoltage();		//TAYIL74
		// //pManager->ComponentData.COMPLABEL = ptrComp->;
	 //}
	 //if (ptBulb != NULL)
	 //{
		// pManager->ComponentData.COMPNAME = "BLB";
		// pManager->ComponentData.COMPvalueRESIS = ptrComp->getResistance();			//TAYIL74
		// pManager->ComponentData.COMPvalueVOLT = ptrComp->getSourceVoltage();		//TAYIL74
		// //pManager->ComponentData.COMPLABEL = ptrComp->;
  //   }
  //   if (ptBuzzer != NULL)
	 //{
		// pManager->ComponentData.COMPNAME = "BUZ";
		// pManager->ComponentData.COMPvalueRESIS = ptrComp->getResistance();			//TAYIL74
		// pManager->ComponentData.COMPvalueVOLT = ptrComp->getSourceVoltage();		//TAYIL74
		// //pManager->ComponentData.COMPLABEL = ptrComp->;
	 //}
	 //if (ptBattery != NULL)
  // 	 {
		// pManager->ComponentData.COMPNAME = "BAT";
		// pManager->ComponentData.COMPvalueRESIS = ptrComp->getResistance();			//TAYIL74
		// pManager->ComponentData.COMPvalueVOLT = ptrComp->getSourceVoltage();		//TAYIL74
		// //pManager->ComponentData.COMPLABEL = ptrComp->;
	 //}
  //   if (ptSwitch != NULL)
	 //{
		// pManager->ComponentData.COMPNAME = "SWT";
		// pManager->ComponentData.COMPvalueRESIS = ptrComp->getResistance();			//TAYIL74
		// pManager->ComponentData.COMPvalueVOLT = ptrComp->getSourceVoltage();		//TAYIL74
		// //pManager->ComponentData.COMPLABEL = ptrComp->;
	 //}
	
	 //if (ptGround != NULL)
	 //{
		// pManager->ComponentData.COMPNAME = "GND";
		// pManager->ComponentData.COMPvalueRESIS = ptrComp->getResistance();			//TAYIL74
		// pManager->ComponentData.COMPvalueVOLT = ptrComp->getSourceVoltage();		//TAYIL74
		// //pManager->ComponentData.COMPLABEL = ptrComp->;
	 //}
	 //if (ptFues != NULL)
	 //{
		// pManager->ComponentData.COMPNAME = "FUS";
		// pManager->ComponentData.COMPvalueRESIS = ptrComp->getResistance();			//TAYIL74
		// pManager->ComponentData.COMPvalueVOLT = ptrComp->getSourceVoltage();		//TAYIL74
		// //pManager->ComponentData.COMPLABEL = ptrComp->;
	 //}
}

 void ActionAddCopy::Undo()
 {

 }
 void  ActionAddCopy::Redo()
 {

 }
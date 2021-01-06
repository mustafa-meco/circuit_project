#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddBul.h"
#include "Actions/ActionAddSwi.h"
#include "Actions\ActionAddBuz.h"
#include "Actions\ActionAddFues.h"
#include "Actions/ActionAddCon.h"
#include "Actions/ActionEdit.h"
#include "Actions/ActionSave.h"
//#include "ActionLoad.h"
#include "Actions/ActionLoad.h"
#include "Actions/ActionSelect.h"
#include "Actions/ActionAddCopy.h"
#include "Actions/ActionExit.h"
#include "Actions/ActionLabel.h"
#include "Actions/ActionAddPaste.h"
#include "Actions/ActionAddCut.h"
#include <iostream>
#include <dos.h>
#include "dos.h"
using namespace std;


ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	ConnCount = 0;

	lineCount = 0;	

	IsSimulation = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = nullptr;
	for (int i = 0; i<MaxCompCount; i++)
		ConnList[i] = nullptr;

	//Creates the UI Object & Initialize the UI
	pUI = new UI;

}
////////////////////////////////////////////////////////////////////
//void ApplicationManager::save(ActionType act) {
//	string compType[] = { "RES","SWT","BLB","GND","BAT","BZR","FUS" };
//	if (act <= 6) {
//		if (CompCount < 10)
//			compLineList[CompCount] = { compType[act] , char(CompCount)  , CompList[CompCount]->getResistance() };
//		else if (CompCount < 100)
//			compLineList[CompCount] = { compType[act] , char(CompCount / 10) + char(CompCount % 10) };
//		else
//			compLineList[CompCount] = { compType[act] , char(CompCount / 100) + char((CompCount % 100) / 10) + char(CompCount % 10) };
//
//	}
//}
//string* ApplicationManager::getSaved(int &m, int &n) {
//	m = CompCount;
//	n = ConnCount;
//	return compLineList;
//}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;	
}
void ApplicationManager::AddConnection(Connection* pConn)
{
	ConnList[ConnCount++] = pConn;
}
Component* ApplicationManager::GetComponentByCordinates(int x, int y) 
{
	
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->isInRegion(x,y, pUI) == true)
		{
				return	CompList[i];
		}
		
	}
	return nullptr;
}

/// //////////////////////////////////////////////////////////////////////////////

Connection* ApplicationManager::GetConnectionByCordinates(int x, int y)
{

	for (int i = 0; i < ConnCount; i++)
	{
		if (ConnList[i]->IsInRegion(x, y, pUI) == true)
		{
			return	ConnList[i];
		}

	}
	return nullptr;
}

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = nullptr;
	switch (ActType)
	{
		case ADD_RESISTOR:
			pAct= new ActionAddRes(this);
			break;
		// TODO: Add remaining actions
		case ADD_BULB:
			pAct = new ActionAddBul(this);
			break;
		case ADD_SWITCH:
			pAct = new ActionAddSwi(this);
			break;
		case ADD_GROUND:
			pAct = new ActionAddGro(this);
			break;
		case ADD_BATTERY:
			pAct = new ActionAddBat(this);
			break;
		case ADD_BUZZER:
			pAct = new ActionAddBuz(this);
			break;
		case ADD_FUES:
			pAct = new ActionAddFues(this);
			break;
		case EDIT_Label:
			pAct = new ActionEdit(this);
			break;
		case ADD_Label:
			pAct = new  ActionLabel(this);
			break;
	    case ADD_CONNECTION: 
			pAct = new ActionAddCon(this);   
			break; 
		case SELECT:
			pAct = new ActionSelect(this);
			break;
		case SAVE:
			pAct = new ActionSave(this);
			break;
		case SIM_MODE:
			ToSimulation();
			break;
		case DSN_MODE:
			ToDesign();
			break;
		case LOAD:
			pAct = new ActionLoad(this);
			break;
		case ADD_COPY: 
			pAct = new ActionAddCopy(this);
			break;
		case ADD_CUT:
			pAct = new ActionAddCut(this);
			break;
		case ADD_PASTE:
			pAct = new ActionAddPaste(this);
			break;
		case EXIT:
			pAct = new ActionExit(this);           //TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		//save(ActType);
		pAct->Execute();
		delete pAct;
		pAct = nullptr;
	}
}
////////////////////////////////////////////////////////////////////

string* ApplicationManager::save(int& cp,int& cn) const {
	cp = CompCount;
	cn = ConnCount;
	string* compData = new string[CompCount+ConnCount];
	for (int i = 0; i < CompCount; i++)
		compData[i] = CompList[i]->save();
	for (int i = 0; i < ConnCount; i++)
		compData[i+CompCount] = ConnList[i]->save();
	return compData;
}

void ApplicationManager::UpdateInterface()
{
	//if (CompCount) 
	//{

		for (int i = 0; i < CompCount; i++)
			CompList[i]->Draw(pUI);
		for (int i = 0; i < ConnCount; i++)
			ConnList[i]->Draw(pUI);
		
	//}
	//else
//Exit()
}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}
////////////////////////////////////////////////////////////////////
// Validates the circuit before going into simultion mode
bool ApplicationManager::ValidateCircuit() {
	//Connection** term1;
	//Connection** term2;
	int i1 = 0, j1 = 0, er = 0;
	Connection** conno;
	Component** compolist = new Component * [CompCount + 1];
	compolist[j1++] = CompList[i1];
	if (CompCount < 3)
		return false;

	int cG = 0;
	/*for (int i = 0; i < CompCount; i++) {
		
	}*/
	
	int c1, c2;
	for (int i = 0; i < CompCount; i++) {
		c1 = 0, c2 = 0;
		if (dynamic_cast<Ground*>(CompList[i]))
			cG++;
		//pUI->PrintMsg(to_string(cG) + " " + to_string(CompCount));
		c1 = CompList[i]->getTermConnCount(TERM1);
		c2 = CompList[i]->getTermConnCount(TERM2);
		//if (dynamic_cast<Ground*>(CompList[i])) {
		//	if ((c1 != 1 && c2 != 1)) {
		//		//pUI->PrintMsg(to_string(c1) + " aw " + to_string(c2));
		//		return false;
		//	}
		//} else 
		if (c1 != 1 || c2 != 1) {
				pUI->PrintMsg(to_string(c1) + " at " + to_string(c2));
				return false;
		}
		conno = nullptr;
		conno = CompList[i1]->getTermConnections(TERM1);



		compolist[j1] = conno[i1]->getOtherComponent(CompList[i1]);
		if (compolist[j1] == compolist[j1 - 1]) {
			conno = nullptr;
			conno = CompList[i1]->getTermConnections(TERM2);
			compolist[j1] = nullptr;
			compolist[j1] = conno[i1]->getOtherComponent(CompList[i1]);

		}
		
		for (int k = 0; k < CompCount; k++) {
			if (compolist[j1] == CompList[k]) {
				i1 = k;
				++j1;
				++er;
				break;
			}
		}
		if (er != 1) {
			
			return false;
		}
			
		er = 0;
		if (compolist[j1 - 1] == CompList[0] && (j1 - 1) != CompCount) {
			
			return false;
		}
			
	}
	if (cG != 1)
		return false;
	
	if (compolist[j1 - 1] != CompList[0])
		return false;
	return true;
}



////////////////////////////////////////////////////////////////////
void ApplicationManager::ToSimulation() {
	if (!ValidateCircuit()) {
		pUI->CreateErrorWind("error \n");
	}
	else {
		this->IsSimulation = true;
		// Compute all needed voltages and current
		double current = CalculateCurrent();
		CalculateVoltages(current);
		pUI->CreateSimulationToolBar();
	}
}
void ApplicationManager::ToDesign() {
	this->IsSimulation = false;
	// Compute all needed voltages and current
	pUI->CreateDesignToolBar();
}
////////////////////////////////////////////////////////////////////
// Calculates current passing through the circuit
double ApplicationManager::CalculateCurrent() {
	// TODO
	return 0;
}

// Calculates voltage at each component terminal
void ApplicationManager::CalculateVoltages(double current) {
	// TODO
}
void ApplicationManager::load( string* labeli , double* valueI, Component** comp001 , Component** comp002) //load the connection 
{
	for (int i = 0; i < CompCount; i++)
		CompList[i]->load(i+1,labeli[i], valueI[i] );
	for (int i = 0; i < ConnCount; i++)
		ConnList[i]->load(comp001[i], comp002[i]);  
}

////////////////////////////////////////////////////////////////////
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < ConnCount; i++)
		delete ConnList[i];
	for (int i = 0; i < CompCount; i++)
		delete CompList[i];

	ConnCount = 0;
	CompCount = 0;
	pUI->ClearAll();

	// TODO
}

///////////////////////////////////////////////////////////////////
//void ApplicationManager::Exit()
//{
//	for (int i=0 ; i < ConnCount; i++)
//		delete ConnList[i];
//	for (int i=0 ; i < CompCount; i++)
//		delete CompList[i];
//	
//	ConnCount = 0;
//	CompCount = 0;
//	
//	pUI->ClearAll();
//	pUI->Dra
//
//
//
//
//	
//    CompList = nullptr;
//    delete GetUI();
//	GetUI() = nullptr;
//    /*delete pConn;
//	pConn = nullptr;
//	delete pComp;
//	pComp = nullptr;*/
//	/*delete GetConnectionByCordinates();
//	delete GetComponentByCordinates();*/
//
//}

 bool ApplicationManager::isAvalible()
 {
	 
		 if ( CompCount >= 2) 
		 {
			 return true;
		 }
		 
		 return false;
	 
	
 } 
 void ApplicationManager::SetCopyComp(Component* comp1)            //TAYIL74
 {
	 CopyComp = comp1;
 }
 Component* ApplicationManager::GetCopyComp() const				   //TAYIL74
 {
	 return CopyComp;
 }


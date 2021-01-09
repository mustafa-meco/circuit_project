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
#include "Actions/ActionExit.h"
#include "Actions/ActionLabel.h"
#include "Actions/ActionDelete.h"
#include<Windows.h>
#include <iostream>
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
		case DEL:
			pAct = new ActionDelete(this);
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
	pUI->ClearDrawingArea();
	for (int i = 0; i < CompCount; i++)
	{
		
		
			CompList[i]->Draw(pUI);
		
		
	
	}
		for (int i = 0; i < ConnCount; i++)
			ConnList[i]->Draw(pUI);
		Sleep(50);
}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}
////////////////////////////////////////////////////////////////////
// Validates the circuit before going into simultion mode
bool ApplicationManager::ValidateCircuit() {
	return true;
}



////////////////////////////////////////////////////////////////////
void ApplicationManager::ToSimulation() {
	if (!ValidateCircuit()) {
		// TODO
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

void ApplicationManager::deleteCompounent(Component*delet)
 {
	int x1 = 0;
	Component* T;
		for (int i = 0; i < CompCount; i++)
		{
			if (CompList[i] == delet)
			{
				x1 = i;
				for (int j = x1; j < CompCount; j++)
				{
					CompList[j] = CompList[j + 1];
				}
				CompCount--;

				int C1, C2;
				C1 = delet->getTermConnCount(TERM1);
				C2 = delet->getTermConnCount(TERM2);
				Connection** c1;
				Connection** c2;
				/* c1 = nullptr;
				 c2 = nullptr;*/
				c1 = delet->getTermConnections(TERM1);
			
				c2 = delet->getTermConnections(TERM2);
		
				for (int y = 0; y < C1; y++)
				{
					pUI->PrintMsg("FUCK THE WORLD");
					delet->removeTerm1Connection(c1[y]);
					pUI->ChangeTitle(c1[y]->getOtherComponent(delet)->getlabel());
					deleteConnection(c1[y]);
				}
				for (int y = 0; y < C2; y++)
				{
					pUI->PrintMsg("FUCK THE WORLD");
					delet->removeTerm2Connection(c2[y]);
					pUI->ChangeTitle(c2[y]->getOtherComponent(delet)->getlabel());
					deleteConnection(c2[y]);
				}
				delete	delet;

			}
		}
	
 }
void ApplicationManager::deleteConnection(Connection* delet) 
{
	int x1 = 0;
	Component* T;
	for (int i = 0; i < ConnCount; i++)
	{
		if (ConnList[i] == delet)
		{
			x1 = i;
			for (int j = x1; j < ConnCount; j++)
			{
				ConnList[j] = ConnList[j + 1];
			}
			ConnCount--;
			for (int zc = 0; zc < CompCount; zc++)
			{
				if(delet->getOtherComponent(CompList[i]))
				{

				}
			}
			delete	delet;
		}
	}
}
//int C1, C2;
		//C1 = delet->getTermConnCount(TERM1);
		//C2 = delet->getTermConnCount(TERM2);
		//Connection** c1;
		//Connection** c2;
		//c1 = nullptr;
		//c2 = nullptr;
		//c1 = delet->getTermConnections(TERM1);

		//c2 = delet->getTermConnections(TERM2);

		//for (int y = 0; y < C1; y++)
		//{
		//    //deletconnection(c1[y]);
		//}
		//for (int y = 0; y < C2; y++)
		//{
		//    //deletconnection(c2[y]);
		//}



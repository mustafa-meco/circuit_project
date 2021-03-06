#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddBul.h"
#include "Actions/ActionAddSwi.h"
#include "Actions\ActionAddBuz.h"
#include "Actions\ActionAddFues.h"
#include "Actions/ActionAddCon.h"
#include "Actions/ActionEdit.h"
#include "Actions/ActionSave.h"
#include "Actions/ActionLoad.h"
#include "Actions/ActionSelect.h"
#include "Actions/ActionAddCopy.h"
#include "Actions/ActionExit.h"
#include "Actions/ActionLabel.h"
#include "Actions/ActionAddPaste.h"
#include "Actions/ActionAddCut.h"
#include "Actions/ActionMove.h"
#include "Actions/ActionDelete.h"
#include "Actions/ActionUndo.h"
#include "Actions/ActionRedo.h"
#include "Actions/ActionMultipleDelete.h"
#include"Actions/operate.h"
#include"Actions/ActionVoltmeter.h"
#include "Actions/ActionAddModule.h"
#include "Actions/ActionAddDesignedModule.h"
#include "Actions/ActionSaveDesignedModule.h"
#include "Actions/ActionAmmeter.h"
#include"Actions/ActionTestSwi.h"
#include "Actions/ActionSimulate.h"
#include "Actions/ActionVoltmeter.h"
#include "Actions/ActionRealistic.h"
#include "Actions/ActionDesign.h"
#include<Windows.h>

#include <iostream>

using namespace std;


ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	ConnCount = 0;

	lineCount = 0;

	IsSimulation = 0;
	IsModulation = 0;
	undoNum = 0;
	redoNum = 0;

	for (int i = 0; i < MaxCompCount; i++)
		CompList[i] = nullptr;
	for (int i = 0; i < MaxCompCount; i++)
		ConnList[i] = nullptr;
	for (int i = 0; i < 10; i++)
		UndoList[i] = nullptr;
	for (int i = 0; i < 10; i++)
		RedoList[i] = nullptr;

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
	if(pConn!=nullptr)
	ConnList[ConnCount++] = pConn;
}
Component* ApplicationManager::GetComponentByCordinates(int x, int y)   //returns pointer to the component if (x,y) is in the component region  
                                                                        //through this function you can know the component type. 
{

	for (int i = 0; i < CompCount; i++)                                 // looping on the all components and find the selected component 
	{
		if (CompList[i]->isInRegion(x, y, pUI) == true)
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
bool ApplicationManager::isSim()
{
	return IsSimulation;
}

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = nullptr;
	switch (ActType)
	{
	case ADD_RESISTOR:
		pAct = new ActionAddRes(this);
		AddToUndoList(pAct);
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
	case ADD_MOD:
		pAct = new ActionAddModule(this);
		AddToUndoList(pAct);
		break;
	case TestSwitch:
		pAct = new ActionTestSwi(this);
		break;

	case UNDO:
		pAct = new  ActionUndo(this);
		break;
	case REDO:
		pAct = new ActionRedo(this);
		break;
	case EDIT_Label:
		pAct = new ActionEdit(this);
		break;
	case MOVE:
		pAct = new ActionMove(this);
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
	case MDEL:
		pAct = new ActionMultipleDelete(this);
		break;
	case SAVE:
		if (IsModulation)
			pAct = new ActionSaveDesignedModule(this);
		else
			pAct = new ActionSave(this);
		break;
	case SIM_MODE:
		pAct = new ActionSimulate(this);
		break;
	case DSN_MODE:
		pAct = new ActionDesign(this);
		break;
	case MOD_MODE:
		pAct = new ActionAddDesignedModule(this);
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
	case ADD_REALISTIC:
		pAct = new ActionRealistic(this);
		break;
	case AMM:
		pAct = new ActionAmmeter(this);
		break;
	case VOL:
		pAct = new ActionVoltmeter(this);
		break;
	case EXIT:
		pAct = new ActionExit(this);           //TODO: create ExitAction here
		break;
	}
	if (pAct)
	{
		pUI->DrawLight();
		//save(ActType);
		AddToUndoList(pAct);
		pAct->Execute();
		/*delete pAct;
		pAct = nullptr;*/
	}
}
////////////////////////////////////////////////////////////////////

string* ApplicationManager::save(int& cp, int& cn) {

	cp = CompCount;
	cn = ConnCount;
	if (IsModulation) {
		double ResistanceT = saveModule();
		string ModData = "MOD " + to_string(ResistanceT);
	}
	else {
		string* compData = new string[CompCount + ConnCount];
		for (int i = 0; i < CompCount; i++)
			compData[i] = CompList[i]->save();
		for (int i = 0; i < ConnCount; i++)
			compData[i + CompCount] = ConnList[i]->save();
		return compData;
	}

}

void ApplicationManager::UpdateInterface()
{
	cout << CompCount<<endl;
	//if (CompCount) 
	//{


	pUI->ClearDrawingArea();
	pUI->DrawReal();
	for (int i = 0; i < CompCount; i++)
		CompList[i]->Draw(pUI);

	for (int i = 0; i < ConnCount; i++)
		ConnList[i]->Draw(pUI);

	Sleep(100);

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
	TerminalNum T = TERM2;
	if (CompCount < 3)
		return false;
	int cG = 0, tkrar = 0;

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
		
		if (T == TERM1)
			conno = CompList[i1]->getTermConnections(TERM2);
		else
			conno = CompList[i1]->getTermConnections(TERM1);
		compolist[j1] = conno[0]->getOtherComponent(CompList[i1]);
		T = compolist[j1]->whichTerminal(conno[0]);
		
		for (int k = 0; k < CompCount; k++) {
			if (compolist[j1] == compolist[k] && j1 != k)
				tkrar++;
			if (compolist[j1] == CompList[k]) {
				i1 = k;
				++j1;
				++er;
				break;
			}
		}

		if (er != 1) {
			pUI->PrintMsg("er" + to_string(i) + to_string(er));
			return false;
		}

		er = 0;
	}
	/*compolist[j1] = conno[0]->getOtherComponent(CompList[i1]);
	if (compolist[j1] == compolist[j1 - 1]) {

		conno = CompList[i1]->getTermConnections(TERM2);

		compolist[j1] = conno[0]->getOtherComponent(CompList[i1]);

	}

	if (compolist[j1 -1] == CompList[0] && (j1 -1 ) != CompCount) {
			pUI->PrintMsg(to_string(j1)+  " end " + to_string(CompCount) + " end " );
			pUI->PrintMsg(to_string(j1)+  " end " + to_string(CompCount) + " end " );
			return false;
	}*/

	if (cG != 1 || tkrar > 1) {
		pUI->PrintMsg("tkrar "+to_string(tkrar));
		return false;
	}
	/*if (compolist[j1] != CompList[0]) {
		pUI->PrintMsg(compolist[j1]->getlabel());
		return false;
	}*/
	pUI->PrintMsg(to_string(j1));
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
	//CalculateVoltages(0);
	if (IsModulation) {
		if (ValidateModule()) {
			Action* a = new ActionSaveDesignedModule(this);
			delete a;
		}
		deleteAll();
	}
	this->IsSimulation = false;
	this->IsModulation = false;
	// Compute all needed voltages and current
	pUI->CreateDesignToolBar();
}
///////////////////////////////////////////////////////////////////////////
// Calculates current passing through the circuit
double ApplicationManager::CalculateCurrent() {
	for (int i = 0; i < CompCount; i++)
	{
		{
			cout << "m" << CompList[i]->GetInputStatus() << "m";			
			cout << "m" << CompList[i]->GetInputStatus() << "m";
			if (CompList[i]->GetInputStatus() == 0 || IsSimulation == false)
				return 0;
		}
	}
	double SumResistance = 0;
	double SumVoltage = 0;
	for (int i = 0; i < CompCount; i++)
	{


		if (CompList[i]->getResistance() != -1)
		{
			SumResistance = SumResistance + CompList[i]->getResistance();
		}
		//if (CompList[i]->getSourceVoltage() != 0 || CompList[i]->getSourceVoltage() != -1)
			/*SumVoltage = SumVoltage + CompList[i]->getSourceVoltage();*/
	}

	int j = 0;
	TerminalNum TM;
	Connection* TempConn =CompList[0]->getTermConnections(TERM1)[0];
	Component** TermComp = new Component * [CompCount+1];
	TermComp[j] = TempConn->getOtherComponent(CompList[0]);
	
	while (TermComp[j] != CompList[0])
	{
		
		
			TM = TermComp[j]->whichTerminal(TempConn);

			if (TM == TERM1)
			{
				SumVoltage = SumVoltage - TermComp[j]->getSourceVoltage();
				TempConn = TermComp[j]->getTermConnections(TERM2)[0];
			}
			else
			{
				SumVoltage = SumVoltage + TermComp[j]->getSourceVoltage();
				TempConn = TermComp[j]->getTermConnections(TERM1)[0];
			}
		
		
		TermComp[++j] = TempConn->getOtherComponent(TermComp[j - 1]);
	}

	cout << (SumVoltage / SumResistance) << endl << SumVoltage << endl << SumResistance;
	return abs(SumVoltage / SumResistance);
}
// Calculates voltage at each component terminal
void ApplicationManager::CalculateVoltages(double current) {
	Component* G = nullptr;
	Component** TemComp = new Component * [CompCount];
	Connection* TempConn;
	TerminalNum TM;
	int z = 0;
	double TotalV = 0;
	for (int i = 0; i < CompCount; i++)
	{
		if (dynamic_cast<Ground*>(CompList[i]))
		{
			G = dynamic_cast<Ground*>(CompList[i]);
			break;
		}
	}
	TempConn = G->getTermConnections(TERM1)[0];
	TemComp[z] = TempConn->getOtherComponent(G);
	G->setTerm1Volt(TotalV);
	G->setTerm2Volt(TotalV);
	while (!dynamic_cast<Ground*>(CompList[z]))
	{
		TM = TemComp[z]->whichTerminal(TempConn);
		if (TM == TERM1)
		{
			TemComp[z]->setTerm1Volt(TotalV);
			cout << " comp "<< z << " term1 "<< TotalV << " term2 ";
			TotalV += current * TemComp[z]->getResistance() - TemComp[z]->getSourceVoltage();
			cout << TotalV << endl;
			TemComp[z]->setTerm2Volt(TotalV);
			TempConn = TemComp[z]->getTermConnections(TERM2)[0];
		}
		else
		{	
			TemComp[z]->setTerm2Volt(TotalV);
			cout << "e comp " << z << " term1 " << TotalV << " term2 ";
			TotalV += current * TemComp[z]->getResistance() + TemComp[z]->getSourceVoltage();
			cout << TotalV << endl;
			TemComp[z]->setTerm1Volt(TotalV);
			TempConn = TemComp[z]->getTermConnections(TERM1)[0];
		}
		TemComp[++z] = TempConn->getOtherComponent(TemComp[z - 1]);
	}
}

void ApplicationManager::operation()
{
	cout << "opp";
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->Operate();
		cout << CompList[i]->getTerm1Volt() << " ww " << CompList[i]->getTerm2Volt() << endl;
	}
}

void ApplicationManager::load(string* labeli, double* valueI, Component** comp001, Component** comp002) //load the circuit  
{
	for (int i = 0; i < CompCount; i++)
		CompList[i]->load(i + 1, labeli[i], valueI[i]);    // load the components 
	for (int i = 0; i < ConnCount; i++)
		ConnList[i]->load(comp001[i], comp002[i]);         // load the connections 
}

////////////////////////////////////////////////////////////////////
ApplicationManager::~ApplicationManager()
{
	//deleteAll();
	for (int i = 0; i < ConnCount; i++)
		delete ConnList[i
		];
	for (int i = 0; i < CompCount; i++)
		delete CompList[i];
	ConnCount = 0;
	CompCount = 0;
	pUI->ClearAll();
}

///////////////////////////////////////////////////////////////////
//void ApplicationManager::Exit()
//{
//	for (int i=0 ; i < ConnCount; i++)
//		delete ConnList[i];
//	for (int i=0 ; i < CompCount; i++)
//		delete CompList[i];
//	ConnCount = 0;
//	CompCount = 0;
//	pUI->ClearAll();
//	pUI->Dra
//  CompList = nullptr;
//  delete GetUI();
//	GetUI() = nullptr;
//  /*delete pConn;
//	pConn = nullptr;
//	delete pComp;
//	pComp = nullptr;*/
//	/*delete GetConnectionByCordinates();
//	delete GetComponentByCordinates();*/
//}

 bool ApplicationManager::isAvalible()
 {
		 if ( CompCount >= 2) 
		 {
			 return true;
		 }
		 return false;
 } 
 void ApplicationManager::SetCopyComp(Component* comp1)            //Setter for the component + saving its values(copy). 
 {
	 if(comp1!=nullptr)
	 CopyComp = comp1->Copy();
 }
 Component* ApplicationManager::GetCopyComp() const				   //Getter for the component after coping or cutting the component.
 {
	 return CopyComp->Copy();
 }
////if (CopyComp==nullptr)
   //		//{
   //		//	pUI->ClearStatusBar();
   //		//	//delete pAct;
   //		//	//pAct = nullptr;
   //		//	pUI->CreateErrorWind("error \n");
   //		//}
   //		//else {
//pAct = new ActionAddPaste(this);
//*	}*/
//break;
void ApplicationManager::deleteCompounent(Component* delet)
{
	int x1 = 0;
	if (delet)
	{
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
				c1 = delet->getTermConnections(TERM1);

				c2 = delet->getTermConnections(TERM2);

				for (int y = 0; y < C1; y++)
				{

					deleteConnection(c1[0]);
				}
				for (int y = 0; y < C2; y++)
				{
					deleteConnection(c2[0]);
				}
				delete	delet;

			}
		}
	}

}
//
//void ApplicationManager::operation()
//{
//	cout << "opp";
//	for (int i = 0; i < CompCount; i++)
//	{
//		CompList[i]->Operate();
//	}
//}

void ApplicationManager::deleteConnection(Connection* delet)
{
	if (delet)
	{
		for (int i = 0; i < ConnCount; i++)
		{
			if (ConnList[i] == delet)
			{
				int x1 = i;
				for (int j = x1; j < ConnCount; j++)
				{
					ConnList[j] = ConnList[j + 1];
				}
				ConnCount--;
				for (int zc = 0; zc < CompCount; zc++)
				{
					if (delet->getOtherComponent(CompList[i]))
					{
						CompList[i]->removeTerm1Connection(delet);
						CompList[i]->removeTerm2Connection(delet);
						delet->getOtherComponent(CompList[i])->removeTerm1Connection(delet);
						delet->getOtherComponent(CompList[i])->removeTerm2Connection(delet);
					}
				}
				delete	delet;
			}
		}
	}
}


int  ApplicationManager::multipleStoreComp(Component* multi,int m)
{
	static int multiplecount = 0;
	if (m != 0)
	{
		multiCompList = nullptr;
		multiCompList = new Component * [CompCount];
		multiplecount = 0;
		return 0;
	}
	

	multiCompList[multiplecount++]=multi;
	return multiplecount;

}
int  ApplicationManager::multipleStoreCon(Connection* multi, int m)
{
	static int multiplecount = 0;
	if (m != 0)
	{
		multiConnList = nullptr;
		multiConnList = new Connection * [ConnCount];
		multiplecount = 0;
		return 0;
		
	}

	
	multiConnList[multiplecount++] = multi;
	return multiplecount;

}
void ApplicationManager::MultipleDelete(int comp, int conn) 
{
	for(int i=0;i<comp;i++)
    {
		deleteCompounent(multiCompList[i]);
    }

	for (int j=0; j < conn; j++)
    {
		deleteConnection(multiConnList[j]);
    }
}




void ApplicationManager::AddToUndoList(Action* A)
{
	if (undoNum < 10)
	{

		UndoList[undoNum] = A;
		undoNum++;
	}
	else
	{
		delete UndoList[0];
		UndoList[0] = nullptr;
		for (int i = 0; i < 9 ; i++)
		{
			UndoList[i] = UndoList[i++];
		}
		UndoList[9] = A;
	}
}
void ApplicationManager::AddToRedoList(Action* A)
{
	if (redoNum < 10)
	{
		RedoList[redoNum] = A;
		redoNum++;
	}
	else
	{
		delete RedoList[0];
		RedoList[0] = nullptr;
		for (int i = 0; i < 9; i++)
		{
			
			RedoList[i] = RedoList[i++];
		}
		RedoList[9] = A;
	}
}
void ApplicationManager::ExcuteUndo()
{
	if (undoNum > 0 )
	{
		undoNum--;
		UndoList[undoNum]->Undo();
		AddToRedoList(UndoList[undoNum]);
		UndoList[undoNum] = nullptr;
	} 
}
void ApplicationManager::ExcuteRedo()
{
	if (redoNum > 0 )
	{
		redoNum--;
		RedoList[redoNum]->Redo();
		AddToUndoList(RedoList[redoNum]);
		RedoList[redoNum] = nullptr;
	}
	if (redoNum < 0)
		redoNum = 0;
}

bool ApplicationManager::ValidateClear() {
	if (CompCount != 0 || ConnCount != 0)
		return false;
	for (int i = 0; i < MaxCompCount; i++) {
		if (CompList[i])
			return false;
	}
	for (int i = 0; i < MaxConnCount; i++) {
		if (ConnList[i])
			return false;
	}
}

bool ApplicationManager::ValidateModule() {
	int c1, c2, cc = 0;
	for (int i = 0; i < CompCount; i++) {
		if (!dynamic_cast<Resistor*>(CompList[i]))
			return false;
		c1 = 0, c2 = 0;
		c1 = CompList[i]->getTermConnCount(TERM1);
		c2 = CompList[i]->getTermConnCount(TERM2);
		if (c1 != 1 && c2 != 1) 
			return false;
		if (c1 != 1 || c2 != 1) 
			cc++;
		if (cc > 2)
			return false;
	}
	return true;
}


double ApplicationManager::saveModule() {
	if (!ValidateModule()) {
		pUI->CreateErrorWind("error \n");
	}
	else {
		double SumResistance=0;
		
		for (int i = 0; i < CompCount; i++)
		{
			SumResistance = SumResistance + CompList[i]->getResistance();
		}
		return SumResistance;
		// Compute all needed voltages and current
		

		//pUI->CreateSimulationToolBar();
	}
}

void ApplicationManager::ToModulation() {
	if (!ValidateClear())
		pUI->CreateErrorWind("error \n");
	else {
		this->IsModulation = true;
		this->IsSimulation = false;
		pUI->CreateModulationToolBar();
	}
}



Component* ApplicationManager::getOne(Connection* con)
{
	for (int zc = 0; zc < CompCount; zc++)
	{
		if (con->getOtherComponent(CompList[zc]) != nullptr)
		{
			return CompList[zc];
		}
	}
}


void ApplicationManager::deleteAll()
{
	for (int i = 0; i < CompCount; i++) {
		deleteCompounent(CompList[i]);
	}
}

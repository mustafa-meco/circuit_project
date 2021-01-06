#pragma once

#include "ActionLoad.h"


ActionLoad::ActionLoad(ApplicationManager* pApp) : Action(pApp)
{
}

ActionLoad::~ActionLoad(void)
{
}
void ActionLoad::Execute()
{
	UI* pUI = pManager->GetUI();
	fstream inFile;
	
	pUI->PrintMsg("Enter the file name : ");
	filename = pUI->GetSrting();
	 

	inFile.open(filename);
	while (!inFile)
	{
		pUI->PrintMsg("Enter the file name : ");
		filename = pUI->GetSrting();
		inFile.open(filename);
	}
	
	getline(inFile, input);
	int x = stoi(input);

	
	string* arr = new string[x];
	string* arrName = new string[x];
	string* arrID = new string[x];
	int* arrIdCorr = new int[x];
	string* arrLABELS = new string[x];
	string* arrVALUE = new string[x];
	double* arrVALUEcorr = new double[x];
	string* arrCOORDINATES1 = new string[x];
	int* arrCOORDINATES1corr = new int[x];
	string* arrCOORDINATES2 = new string[x];
	int* arrCOORDINATES2corr = new int[x];

	//GraphicsInfo** ARRpGInfo = new GraphicsInfo * [x];
	int dump = 0; int dump2 = 0;
	

	for (int j = 0; j < x; j++)
	{
		


		getline(inFile, arrName[j], ' ');


		getline(inFile, arrID[j], ' ');
		
		getline(inFile, arrLABELS[j], ' ');
		
		getline(inFile, arrVALUE[j], ' ');
	
		getline(inFile, arrCOORDINATES1[j], ' ');
	
		getline(inFile, arrCOORDINATES2[j]);
		
		arrIdCorr[j] = stoi(arrID[j]);
		arrVALUEcorr[j] = stod(arrVALUE[j]);
		arrCOORDINATES1corr[j] = stoi(arrCOORDINATES1[j]);
		arrCOORDINATES2corr[j] = stoi(arrCOORDINATES2[j]);

		
		
		GraphicsInfo* pGInfo5 = new GraphicsInfo(2);
		pGInfo5->PointsList[0].x = stoi(arrCOORDINATES1[j]);
		pGInfo5->PointsList[0].y = stoi(arrCOORDINATES2[j]);
		pGInfo5->PointsList[1].x = pGInfo5->PointsList[0].x + pUI->getCompWidth();
		pGInfo5->PointsList[1].y = pGInfo5->PointsList[0].y + pUI->getCompHeight();
		if (arrName[j] == "RES")
		{
		
			Resistor* pR = new Resistor(pGInfo5/*, pUI*/);
			pManager->AddComponent(pR);
		}
		else if (arrName[j] == "SWT")
		{

			Switch* pR = new Switch(pGInfo5);
			pManager->AddComponent(pR);

		}
		else if (arrName[j] == "BAT")
		{

			Battery* pR = new Battery(pGInfo5);
			pManager->AddComponent(pR);

		}
		else if (arrName[j] == "BLB")
		{

			Bulb* pR = new Bulb(pGInfo5);
			pManager->AddComponent(pR);

		}
		else if (arrName[j] == "GND")
		{

			Ground* pR = new Ground(pGInfo5);
			pManager->AddComponent(pR);

		}
		else if (arrName[j] == "FUS")
		{
			Fues* pR = new Fues(pGInfo5);
			pManager->AddComponent(pR);

		}
		else 
		{
			Buzzer* pR = new Buzzer(pGInfo5);
			pManager->AddComponent(pR);
		}
		
	}

	
	getline(inFile, input);
	input = "";
	getline(inFile, input);
	int y = stoi(input);
	int* arr11 = new int[y];
	int* arr22 = new int[y];
	int* arr33 = new int[y];
	int* arr44 = new int[y];
	int* arr55 = new int[y];
	int* arr66 = new int[y];
	Component** arrCOMP1 = new Component*[y];
	Component** arrCOMP2 = new Component * [y];

	for (int j = 0; j < y; j++)
	{

		getline(inFile, input, ' ');
	
		arr11[j] = stoi(input);

		getline(inFile, input, ' ');
		arr22[j] = stoi(input);

		getline(inFile, input, ' ');
		arr33[j] = stoi(input);
	

		getline(inFile, input, ' ');
		arr44[j] = stoi(input);
		
		

		getline(inFile, input, ' ');
		arr55[j] = stoi(input);
		
		getline(inFile, input);
		arr66[j] = stoi(input);
		
		

		GraphicsInfo* pGInfo = new GraphicsInfo(2);
		pGInfo->PointsList[0].x = arr33[j];
		pGInfo->PointsList[0].y = arr44[j];

		pGInfo->PointsList[1].x = arr55[j];
		pGInfo->PointsList[1].y = arr66[j];


		comp01 = pManager->GetComponentByCordinates(arr33[j] , arr44[j]);
		comp02 = pManager->GetComponentByCordinates(arr55[j] , arr66[j]);
		Connection* pR = new Connection(pGInfo, comp01, comp02);
		pManager->AddConnection(pR);
		

		TerminalNum comp1conn, comp2conn;
		if (arr33[j] < comp01->getCompCenterx(pUI))
		{
		

			//comp1->addTerm1Connection();
			comp1conn = TERM1;
		}
		else
		{
		
			comp1conn = TERM2;
		}
		if (arr55[j] < comp02->getCompCenterx(pUI))
		{
			comp2conn = TERM1;
			//comp2->addTerm1Connection();
		}
		else
		{
			comp2conn = TERM2;
		}

		Connection* pCON = new Connection(pGInfo, comp01, comp02);
		if (comp1conn == TERM1)
			comp01->addTerm1Connection(pCON);
		else
			comp01->addTerm2Connection(pCON);
		if (comp2conn == TERM1)
			comp02->addTerm1Connection(pCON);
		else
			comp02->addTerm2Connection(pCON);
		




		/*Connection* pR = new Connection(pGInfo, nullptr, nullptr); 
		pManager->AddConnection(pR);
		comp01 = pManager->GetComponentByCordinates(arr33[j], arr44[j]);
		comp02 = pManager->GetComponentByCordinates(arr55[j], arr66[j]);*/

		arrCOMP1[j] = comp01;
		arrCOMP2[j] = comp02; 

	} 
	inFile.close();
	pManager->load(arrLABELS, arrVALUEcorr, arrCOMP1, arrCOMP2);  

}


void ActionLoad::Undo() {

}
void ActionLoad::Redo() {

}
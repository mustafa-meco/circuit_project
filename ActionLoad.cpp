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
	//int i=0;
	UI* pUI = pManager->GetUI();
	fstream inFile;
	//pUI->PrintMsg("Enter the file name : "); 
	//file = pUI->Getstring(); 
	pUI->PrintMsg("Enter the file name : ");
	filename = pUI->GetSrting();
	//inFile.open(filename);
	inFile.open(filename);
	while (!inFile)
	{
		pUI->PrintMsg("Enter the file name : ");
		filename = pUI->GetSrting();
	}
	//do
	//{
	   //  
	   // pUI->PrintMsg("Enter the file name : ");
	   // filename = pUI->GetSrting(); 
	   // while (!inFile) 
	   // {
	   //	 pUI->PrintMsg("File open failure! ");
	   //	 filename = pUI->GetSrting();
	   // }
	//} while (!inFile); 
	getline(inFile, input);
	int x = stoi(input);

	//int j ;
	//char arrch[6];
	 //getline(inFile, arr[i],' ');
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
	// for (int i = 0; i < 6; i++)
	// {

	for (int j = 0; j < x; j++)
	{
		// for (int z = 0; z < 6; z++)
		// {


		getline(inFile, arrName[j], ' ');




		//pUI->PrintMsg(arrName[j]);
		//pUI->GetPointClicked(dump, dump2); 
		getline(inFile, arrID[j], ' ');
		/*	pUI->PrintMsg(arrID[j]);
			pUI->GetPointClicked(dump, dump2);*/
		getline(inFile, arrLABELS[j], ' ');
		//pUI->PrintMsg(arrLABELS[j]);
		//pUI->GetPointClicked(dump, dump2);
		getline(inFile, arrVALUE[j], ' ');
		//pUI->PrintMsg(arrVALUE[j]);
		//pUI->GetPointClicked(dump, dump2);
		getline(inFile, arrCOORDINATES1[j], ' ');
		//pUI->PrintMsg(arrCOORDINATES1[j]);
		//pUI->GetPointClicked(dump, dump2);
		getline(inFile, arrCOORDINATES2[j]);
		/*	pUI->PrintMsg(arrCOORDINATES2[j]);
			pUI->GetPointClicked(dump, dump2);*/
		arrIdCorr[j] = stoi(arrID[j]);
		arrVALUEcorr[j] = stod(arrVALUE[j]);
		arrCOORDINATES1corr[j] = stoi(arrCOORDINATES1[j]);
		arrCOORDINATES2corr[j] = stoi(arrCOORDINATES2[j]);

		/*pGInfo->PointsList[0].x = stoi(arrCOORDINATES1[j]) + j;
		pGInfo->PointsList[0].y = stoi(arrCOORDINATES2[j]) + j;*/

		if (arrName[j] == "RES")
		{
			GraphicsInfo* pGInfo1 = new GraphicsInfo(1);
			pGInfo1->PointsList[0].x = stoi(arrCOORDINATES1[j]);
			pGInfo1->PointsList[0].y = stoi(arrCOORDINATES2[j]);
			Resistor* pR = new Resistor(pGInfo1, pUI);
			pManager->AddComponent(pR);
		}
		else if (arrName[j] == "SWT")
		{
			GraphicsInfo* pGInfo2 = new GraphicsInfo(1);
			pGInfo2->PointsList[0].x = stoi(arrCOORDINATES1[j]);
			pGInfo2->PointsList[0].y = stoi(arrCOORDINATES2[j]);
			Switch* pR = new Switch(pGInfo2, pUI);
			pManager->AddComponent(pR);

		}
		else if (arrName[j] == "BAT")
		{
			GraphicsInfo* pGInfo3 = new GraphicsInfo(1);
			pGInfo3->PointsList[0].x = stoi(arrCOORDINATES1[j]);
			pGInfo3->PointsList[0].y = stoi(arrCOORDINATES2[j]);
			Battery* pR = new Battery(pGInfo3, pUI);
			pManager->AddComponent(pR);

		}
		else if (arrName[j] == "BLB")
		{
			GraphicsInfo* pGInfo4 = new GraphicsInfo(1);
			pGInfo4->PointsList[0].x = stoi(arrCOORDINATES1[j]);
			pGInfo4->PointsList[0].y = stoi(arrCOORDINATES2[j]);
			Bulb* pR = new Bulb(pGInfo4, pUI);
			pManager->AddComponent(pR);

		}
		else if (arrName[j] == "GND")
		{
			GraphicsInfo* pGInfo5 = new GraphicsInfo(1);
			pGInfo5->PointsList[0].x = stoi(arrCOORDINATES1[j]);
			pGInfo5->PointsList[0].y = stoi(arrCOORDINATES2[j]);
			Ground* pR = new Ground(pGInfo5, pUI);
			pManager->AddComponent(pR);

		}
		else if (arrName[j] == "FUS")
		{
			GraphicsInfo* pGInfo6 = new GraphicsInfo(1);
			pGInfo6->PointsList[0].x = stoi(arrCOORDINATES1[j]);
			pGInfo6->PointsList[0].y = stoi(arrCOORDINATES2[j]);
			Fues* pR = new Fues(pGInfo6, pUI);
			pManager->AddComponent(pR);

		}
		else // (arrName[j] == "BUZ")
		{
			GraphicsInfo* pGInfo7 = new GraphicsInfo(1);
			pGInfo7->PointsList[0].x = stoi(arrCOORDINATES1[j]);
			pGInfo7->PointsList[0].y = stoi(arrCOORDINATES2[j]);
			Buzzer* pR = new Buzzer(pGInfo7, pUI);
			pManager->AddComponent(pR);
		}
		/*		 pUI->PrintMsg(arr[j]);
				 pUI->GetPointClicked(dump, dump2);*/
				 /*	 arrName[z] = arr[0];
					  arrID[z] = stoi(arr[1]);
					  arrLABELS[z] = arr[2];
					  arrVALUE[z] = stoi(arr[3]);
					  arrCOORDINATES1[z] = stoi( arr[4]);
					  arrCOORDINATES2[z] = stoi(arr[5]);*/
					  // }
	}

	/*     pUI->PrintMsg(arr[i]);
		 pUI->GetPointClicked(dump, dump2);*/
		 //char * arr1 = new char[arr[i].size()+1];   
		 //strcpy(arrch,arr[i].c_str()); 
		 //arr1 =strtok(arrch, " ");
	 //}
	 //
	 //string* arr = new string[x];
	// int dump = 0; int dump2 = 0;
	////for (int i=0; i<x; i++)
	////{
	////
	////	 getline(inFile, arr[i]);  
	////	 string* a = &arr[i];
	////	 pUI->PrintMsg(a[i]);
	////	pUI->GetPointClicked(dump, dump2);
	////	 i++;
	//// }
		 ///////////////////////////////////////////////////////////
		 ///////////////////////////////////////////////////////////
		 //////////////////////////////////////////////////////////
		 //////////////////////////////////////////////////////////
		 //////////////////////////////////////////////////////////
		 //////////////////////////////////////////////////////////
		 // string* arr = new string[x];
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

		
	/*	pUI->PrintMsg(to_string(j));
		pUI->GetPointClicked(dump, dump2);*/
		getline(inFile, input, ' ');
	/*	pUI->PrintMsg(input);
		pUI->GetPointClicked(dump, dump2);*/
		/*if (j == 1) {
			getline(inFile, input, ' ');
			pUI->PrintMsg(input);
			pUI->GetPointClicked(dump, dump2);
			getline(inFile, input, ' ');
			pUI->PrintMsg(input);
			pUI->GetPointClicked(dump, dump2);
			getline(inFile, input, ' ');
			pUI->PrintMsg(input);
			pUI->GetPointClicked(dump, dump2);
			getline(inFile, input, ' ');
			pUI->PrintMsg("mfe4");
			pUI->GetPointClicked(dump, dump2);
		}
			*/
		arr11[j] = stoi(input);
		//pUI->PrintMsg(input);
		//pUI->GetPointClicked(dump, dump2);

	

		getline(inFile, input, ' ');
		arr22[j] = stoi(input);
		/*pUI->PrintMsg(input);
		pUI->GetPointClicked(dump, dump2);*/





		getline(inFile, input, ' ');
		arr33[j] = stoi(input);
	/*	pUI->PrintMsg(input);
		pUI->GetPointClicked(dump, dump2);

	*/

		getline(inFile, input, ' ');
		arr44[j] = stoi(input);
		/*pUI->PrintMsg(input);
		pUI->GetPointClicked(dump, dump2);*/

		

		getline(inFile, input, ' ');
		arr55[j] = stoi(input);
		//pUI->PrintMsg(input);
		//pUI->GetPointClicked(dump, dump2);


		getline(inFile, input);
		arr66[j] = stoi(input);
		
		/*pUI->PrintMsg(input); 
		pUI->GetPointClicked(dump, dump2);*/ 


		GraphicsInfo* pGInfo = new GraphicsInfo(2);
		pGInfo->PointsList[0].x = arr33[j];
		pGInfo->PointsList[0].y = arr44[j];

		pGInfo->PointsList[1].x = arr55[j];
		pGInfo->PointsList[1].y = arr66[j];







		Connection* pR = new Connection(pGInfo, nullptr, nullptr); 
		pManager->AddConnection(pR);
		comp01 = pManager->GetComponentByCordinates(arr33[j], arr44[j]);
		comp02 = pManager->GetComponentByCordinates(arr55[j], arr66[j]);

		arrCOMP1[j] = comp01;
		arrCOMP2[j] = comp02; 



		//pManager->load(arrLABELS, arrVALUEcorr);


		




	}
	inFile.close();
	pManager->load(arrLABELS, arrVALUEcorr, arrCOMP1, arrCOMP2);  

}


void ActionLoad::Undo() {

}
void ActionLoad::Redo() {

}
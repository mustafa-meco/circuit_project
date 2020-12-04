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
inFile.open("D:\\"+ filename);
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
 int * arrIdCorr = new int[x];
 string* arrLABELS = new string[x];
 string* arrVALUE = new string[x];
 int* arrVALUEcorr = new int[x];
 string* arrCOORDINATES1 = new string[x];
 int* arrCOORDINATES1corr = new int[x]; 
 string* arrCOORDINATES2 = new string[x];
 int* arrCOORDINATES2corr = new int[x];
 GraphicsInfo* pGInfo = new GraphicsInfo(1);
 int dump = 0; int dump2 = 0;
// for (int i = 0; i < 6; i++)
// {

	 for (int j = 0; j < 8;  j++)
	 {
		// for (int z = 0; z < 6; z++)
		// {


		
		if  (arrName[j]== "RES")
		{
			Resistor* pR = new Resistor(nullptr, pUI); 
			pManager->AddComponent(pR);


		}
		else if (arrName[j] == "SWT")
		{
			Switch* pR = new Switch(nullptr, pUI);		
			pManager->AddComponent(pR);

		}
		else if (arrName[j] == "BAT")
		{
			Battery* pR = new Battery(nullptr, pUI);
			pManager->AddComponent(pR);

		}
		else if (arrName[j] == "BLB")
		{
			Bulb* pR = new Bulb(nullptr, pUI);		
			pManager->AddComponent(pR);

		}
		else if (arrName[j] == "GND")
		{
			Ground* pR = new Ground(nullptr, pUI); 
			pManager->AddComponent(pR);

		}
		else if (arrName[j] == "FUS")
		{
			Fues* pR = new Fues(nullptr, pUI);		
			pManager->AddComponent(pR);

		}
		else // (arrName[j] == "BUZ")
		{
			Buzzer* pR = new Buzzer (nullptr, pUI);   
			pManager->AddComponent(pR); 
		}
		

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
		pGInfo->PointsList[0].x = arrCOORDINATES1corr[j];
		pGInfo->PointsList[0].y = arrCOORDINATES2corr[j];


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
 
 inFile.close(); 




}


void ActionLoad::Undo() {

}
void ActionLoad::Redo() {

}
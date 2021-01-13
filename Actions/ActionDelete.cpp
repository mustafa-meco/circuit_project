#include"ActionDelete.h"
#include "../ApplicationManager.h"
#include<iostream>

ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{}
ActionDelete::~ActionDelete(void)
{}


void ActionDelete::Execute()
{
	int cx = 0;
	int cy = 0;
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("choose the compounent that you want to delete");
	do
	{   pUI->GetPointClicked(cx, cy);
		comp = pManager->GetComponentByCordinates(cx, cy);
		connection = pManager->GetConnectionByCordinates(cx, cy);
	} while (connection == nullptr && comp == nullptr);

	if (comp != nullptr)
	{
		comp2 = comp->Copy();
		C1 = comp->getTermConnCount(TERM1);
		C2 = comp->getTermConnCount(TERM2);
		for (int i = 0; i < C2; i++)
		{
			undo1[i] = nullptr;
			undo2[i] = nullptr;
		}
		for (int i = 0; i < C1; i++)
		{
			undo1[i] = comp->getTermConnections(TERM1)[i]->copyconnectionAndChange(comp2);
			//the terminal of the other component is
			tt1[i] = comp->getTermConnections(TERM1)[i]->getOtherComponent(comp)->whichTerminal(comp->getTermConnections(TERM1)[i]);
		}
		for (int i = 0; i < C2; i++)
		{
			undo2[i] = comp->getTermConnections(TERM2)[i]->copyconnectionAndChange(comp2);
			//the terminal of the other component is
			tt2[i] = comp->getTermConnections(TERM2)[i]->getOtherComponent(comp)->whichTerminal(comp->getTermConnections(TERM2)[i]);
		}
		pManager->deleteCompounent(comp);
	}


	if (connection != nullptr && comp==nullptr)
	{
		connection2 = connection->copyconnection();
		Comp1 = pManager->getOne(connection2);
		Comp2 = connection2->getOtherComponent(Comp1);
		t1=Comp1->whichTerminal(connection);
		t2 = Comp2->whichTerminal(connection);
		pManager->deleteConnection(connection);
	}


	pUI->ClearStatusBar();

}



void ActionDelete::Undo() 
{
	if (connection2 != nullptr)
	{
		if (t1== TERM1)
			Comp1->addTerm1Connection(connection2);
		if (t1 == TERM2)
			Comp1->addTerm2Connection(connection2);
		if (t2 == TERM1)
			Comp2->addTerm1Connection(connection2);
		if (t2 == TERM2)
			Comp2->addTerm2Connection(connection2);

		pManager->AddConnection(connection2);
	}
	if (comp2 != nullptr)
	{
		pManager->AddComponent(comp2);

		for (int y = 0; y < C1; y++)
		{
			comp2->addTerm1Connection(undo1[y]);

			if (tt1[y] == TERM1)
				undo1[y]->getOtherComponent(comp2)->addTerm1Connection(undo1[y]);
			else if (tt1[y] == TERM2)
				undo1[y]->getOtherComponent(comp2)->addTerm2Connection(undo1[y]);

			pManager->AddConnection(undo1[y]);
		}
		for (int y = 0; y < C2; y++)
		{
			comp2->addTerm2Connection(undo2[y]);
			if (tt2[y] == TERM1)
				undo2[y]->getOtherComponent(comp2)->addTerm1Connection(undo2[y]);
			else if (tt2[y] == TERM2)
				undo2[y]->getOtherComponent(comp2)->addTerm2Connection(undo2[y]);
			pManager->AddConnection(undo2[y]);
		}
	}

}
void ActionDelete::Redo() 
{
	if (connection2 != nullptr)
	{
		temp2=connection2->copyconnection();
		pManager->deleteConnection(connection2);
		connection2 = temp2;
	}
	if (comp2 != nullptr)
	{
	
		temp1 = comp2->Copy();
		for (int i = 0; i < C1; i++)
		{
			temp3[i] = comp2->getTermConnections(TERM1)[i]->copyconnectionAndChange(temp1);
		}
		for (int i = 0; i < C2; i++)
		{
			temp4[i] = comp2->getTermConnections(TERM2)[i]->copyconnectionAndChange(temp1);
		}

		pManager->deleteCompounent(comp2);

		comp2 = temp1;

		for (int i = 0; i < 10; i++)
		{
			undo1[i] = temp3[i];
			undo2[i] = temp4[i];
		}

		
	}
	
}
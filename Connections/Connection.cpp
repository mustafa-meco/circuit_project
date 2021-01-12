#include<iostream>
#include "Connection.h"
#include "..\UI\UI.h"
#include "../Components/Component.h"
 
Connection::Connection(GraphicsInfo* r_GfxInfo, Component* cmp1, Component* cmp2)
{
	pGfxInfo = r_GfxInfo;
	Comp1 = cmp1;
	Comp2 = cmp2;
}


void Connection::Draw(UI* pUI) //draw the connection between two points 
{
	pUI->DrawConnection(*pGfxInfo, pconnection == this); 
	
}

bool Connection::IsInRegion(int x, int y, UI* pUI)
{
	 /* int x1 = pGfxInfo->PointsList[0].x;
	  int x2 = pGfxInfo->PointsList[1].x;
	  int y1 = pGfxInfo->PointsList[0].y;
	  int y2 = pGfxInfo->PointsList[1].y;
	  double slope = (y2 - y1) / (x2 - x1);
	  int Right;
	  int Left;

	  for (int r = -5; r <= 5; r++)
	  {
		  if ((x + r >= x2 && x + r <= x1) || (x + r >= x1 && x + r <= x2))
		  {
			  for (int i = -4; i <= 4; i++)
			  {
				  if (x1 != x2)
				  {
					  Right = slope * (x - (x1 + i));
						  Left = y - (y1 + i);
				  }
				  else
				  {
					  Right = x - (x1 + i);
					  Left = 0;
				  }*/

	if (pGfxInfo->PointsList[0].x <= x &&
		pGfxInfo->PointsList[1].x >= x &&
		pGfxInfo->PointsList[0].y <= y &&
		pGfxInfo->PointsList[1].y >= y ||
		pGfxInfo->PointsList[0].x == x ||
		pGfxInfo->PointsList[1].x == x ||
		pGfxInfo->PointsList[0].y == y ||
		pGfxInfo->PointsList[1].y == y)
	{
		pconnection = this;
		return true;
	}

	else
	{
		pconnection = nullptr;
		return false;
	}
}

			
  Connection* Connection::pconnection = nullptr;



//		pUI->DrawConnection(*pGfxInfo ); 



void Connection::load( Component* C1, Component* C2)  //load connection
{
	Comp1 = C1;        // the first component which the loading connection will be connected with
	Comp2 = C2;        // the second component which the loading connection will be connected with

}
 
string Connection::save() const {
	string row = to_string(Comp1->getID()) + " "+ to_string(Comp2->getID()) + " " + to_string(pGfxInfo->PointsList[0].x) + " " + to_string(pGfxInfo->PointsList[0].y) + " " + to_string(pGfxInfo->PointsList[1].x) + " " + to_string(pGfxInfo->PointsList[1].y);
	return row;
}
Component* Connection::getOtherComponent(Component* Cmpnt)
{
	if (Comp1 == Cmpnt)
	{
		return Comp2;
	}
	else if (Comp2 == Cmpnt)
	{
		return Comp1;
	}
	else {
		return nullptr;
	}
}


void Connection::EditConnection(Component* component1, Component* component2, GraphicsInfo* pGInfo,UI* pUI)
{
	pUI->DeleteConnection(*pGfxInfo);
	 if (Comp1 == this->getOtherComponent(component1))
	 {
		 
		
		 Comp1= component2;
		 pGfxInfo->PointsList[0].x = pGInfo->PointsList[0].x;
		 pGfxInfo->PointsList[0].y = pGInfo->PointsList[0].y;
	 }
	else if(Comp2 ==this->getOtherComponent(component1))
	{
		
		Comp2 = component2;
		pGfxInfo->PointsList[1].x = pGInfo->PointsList[0].x;
		pGfxInfo->PointsList[1].y = pGInfo->PointsList[0].y;

	}
	

}
Connection::~Connection()
{
	if (Comp1 != nullptr)
	{
		Comp1->removeTerm1Connection(this);
		Comp1->removeTerm2Connection(this);
	}
	if (Comp2 != nullptr)
	{
		Comp2->removeTerm1Connection(this);
		Comp2->removeTerm2Connection(this);
	}
}

Connection* Connection::copyconnection()
{

		GraphicsInfo* r_GfxInfo = new GraphicsInfo(2);
		r_GfxInfo->PointsList[0].x = pGfxInfo->PointsList[0].x;
		r_GfxInfo->PointsList[1].x = pGfxInfo->PointsList[1].x;
		r_GfxInfo->PointsList[0].y = pGfxInfo->PointsList[0].y;
		r_GfxInfo->PointsList[1].y = pGfxInfo->PointsList[1].y;
		Connection* con = new Connection(r_GfxInfo, Comp1, Comp2);
		return con;
}

Connection* Connection::copyconnectionAndChange(Component* com)
{
	GraphicsInfo* r_GfxInfo = new GraphicsInfo(2);
	r_GfxInfo->PointsList[0].x = pGfxInfo->PointsList[0].x;
	r_GfxInfo->PointsList[1].x = pGfxInfo->PointsList[1].x;
	r_GfxInfo->PointsList[0].y = pGfxInfo->PointsList[0].y;
	r_GfxInfo->PointsList[1].y = pGfxInfo->PointsList[1].y;

	if (Comp1->getm_pGfxInfo()->PointsList[0].y == com->getm_pGfxInfo()->PointsList[0].y
		&& Comp1->getm_pGfxInfo()->PointsList[1].y == com->getm_pGfxInfo()->PointsList[1].y
		&& Comp1->getm_pGfxInfo()->PointsList[0].x == com->getm_pGfxInfo()->PointsList[0].x
		&& Comp1->getm_pGfxInfo()->PointsList[1].x == com->getm_pGfxInfo()->PointsList[1].x)
	{
		Connection* con = new Connection(r_GfxInfo, com, Comp2);
		return con;
	}

	if (Comp2->getm_pGfxInfo()->PointsList[0].y == com->getm_pGfxInfo()->PointsList[0].y
		&& Comp2->getm_pGfxInfo()->PointsList[1].y == com->getm_pGfxInfo()->PointsList[1].y
		&& Comp2->getm_pGfxInfo()->PointsList[0].x == com->getm_pGfxInfo()->PointsList[0].x
		&& Comp2->getm_pGfxInfo()->PointsList[1].x == com->getm_pGfxInfo()->PointsList[1].x)
	{
		Connection* con = new Connection(r_GfxInfo, Comp1, com);
		return con;
	}
	
	return nullptr;
}

/* Deletes the component */

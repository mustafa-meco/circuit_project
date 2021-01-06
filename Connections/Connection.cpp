
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
	if (this->Comp1 == Cmpnt)
	{
		return Comp2;
	}
	else if (Comp2 == Cmpnt)
	{
		return Comp1;
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
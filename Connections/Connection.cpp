#include "Connection.h"
#include "../Components/Component.h"
 
Connection::Connection(GraphicsInfo* r_GfxInfo, Component* cmp1, Component* cmp2)
{
	pGfxInfo = r_GfxInfo;      // the coordinates of components
	Comp1 = cmp1;              // the first component of the connection
	Comp2 = cmp2;              // the second component of the connetion
	
}
void Connection::Draw(UI* pUI) //draw the connection between two points 
{
		pUI->DrawConnection(*pGfxInfo ); 
}
void Connection::load( Component* C1, Component* C2)  //load connection
{
	Comp1 = C1;        // the first component which the loading connection will be connected with
	Comp2 = C2;        // the second component which the loading connection will be connected with

}
 
string Connection::save() const {
	string row = to_string(Comp1->getID()) + " "+ to_string(Comp2->getID()) + " " + to_string(pGfxInfo->PointsList[0].x) + " " + to_string(pGfxInfo->PointsList[0].y) + " " + to_string(pGfxInfo->PointsList[1].x) + " " + to_string(pGfxInfo->PointsList[1].y);
	return row;
}

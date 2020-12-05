#include "Connection.h"
#include "../Components/Component.h"
 
Connection::Connection(GraphicsInfo* r_GfxInfo, Component* cmp1, Component* cmp2)
{
	pGfxInfo = r_GfxInfo;
	Comp1 = cmp1;
	Comp2 = cmp2;
	
}
void Connection::Draw(UI* pUI)
{
		pUI->DrawConnection(*pGfxInfo ); 
}
void Connection::load( Component* C1, Component* C2)
{
	Comp1 = C1;
	Comp2 = C2;

}
 
string Connection::save() const {
	string row = to_string(Comp1->getID()) + " "+ to_string(Comp2->getID()) + " " + to_string(pGfxInfo->PointsList[0].x) + " " + to_string(pGfxInfo->PointsList[0].y) + " " + to_string(pGfxInfo->PointsList[1].x) + " " + to_string(pGfxInfo->PointsList[1].y);
	return row;
}

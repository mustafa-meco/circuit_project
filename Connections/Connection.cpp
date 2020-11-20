#include "Connection.h"

Connection::Connection(GraphicsInfo* r_GfxInfo, Component* cmp1, Component* cmp2)
{
	pGfxInfo = r_GfxInfo;
	Comp1 = cmp1;
	Comp2 = cmp2;
}
void Connection::Draw(UI* pUI)
{
	pUI->DrawConnection(*pGfxInfo);
}

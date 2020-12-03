#include "Bulb.h"

Bulb::Bulb(GraphicsInfo* r_GfxInfo, UI* pUI) :Component(r_GfxInfo)
{
	pUI->PrintMsg("Enter the value of the resistace: ");
	resistance = stod(pUI->GetSrting()); // TODO: Take resistance from user
	pUI->ClearStatusBar();
	sourceVoltage = 0;
}

void Bulb::Draw(UI* pUI)
{
	//Call output class and pass bulb drawing info to it.
	pUI->DrawBulb(*m_pGfxInfo, pcomp == this); //update to draw bulb

}

void Bulb::Operate()
{

}

string* Bulb::save() const {
	Point p;
	p.x = m_pGfxInfo->PointsList[0].x;
	p.y = m_pGfxInfo->PointsList[0].y;
	string row[] = { "BAT" ,m_Label,to_string(sourceVoltage),to_string(p.x),to_string(p.y) };
	return row;
}
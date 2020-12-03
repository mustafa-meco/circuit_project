#include "Battery.h"
//#include "../Electric Circuit Simulator - Code Framework/Components/Component.h" 

Battery::Battery(GraphicsInfo* r_GfxInfo, UI* pUI) :Component(r_GfxInfo)
{
	//resistance = 2; // take battery from user
	//sourcevoltage = 0;
	pUI->PrintMsg("Enter the value of the internal resistance: ");
	resistance = stod(pUI->GetSrting()); // TODO: Take resistance from user
	pUI->ClearStatusBar();
	pUI->PrintMsg("Enter the value of the source voltage: ");
	sourceVoltage = stod(pUI->GetSrting());
	pUI->ClearStatusBar();
}

void Battery::Draw(UI* pUI)
{
	//Call output class and pass battery drawing info to it.
	pUI->DrawBattery(*m_pGfxInfo, pcomp == this); //update to draw battery
}

void Battery::Operate()
{

}

string* Battery::save() const {
	Point p;
	p.x = m_pGfxInfo->PointsList[0].x;
	p.y = m_pGfxInfo->PointsList[0].y;
	string row[] = { "BAT" ,m_Label,to_string(sourceVoltage),to_string(p.x),to_string(p.y) };
	return row;
}
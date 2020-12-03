#include"Fues.h"

Fues::Fues(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 2; // TODO: Take resistance from user
	sourceVoltage = 0;
}

void Fues::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawFues(*m_pGfxInfo); //update to draw Fues

}
void Fues::Operate()
{


}

string* Fues::save() const {
	Point p;
	p.x = m_pGfxInfo->PointsList[0].x;
	p.y = m_pGfxInfo->PointsList[0].y;
	string row[] = { "BAT" ,m_Label,to_string(sourceVoltage),to_string(p.x),to_string(p.y) };
	return row;
}
#include "Bulb.h"

Bulb::Bulb(GraphicsInfo* r_GfxInfo/*, double R*/) :Component(r_GfxInfo)
{
	

		resistance = 2;
		//sourceVoltage = 0;

		/*pUI->PrintMsg("Enter the label: ");
		m_Label = pUI->GetSrting();*/
		
		//sourceVoltage = 0;
}

void Bulb::Draw(UI* pUI)
{
	//Call output class and pass bulb drawing info to it.
	pUI->DrawBulb(*m_pGfxInfo, pcomp == this); //update to draw bulb

}

void Bulb::Operate()
{

}

string Bulb::save() const {
	Point p;
	p.x = m_pGfxInfo->PointsList[0].x;
	p.y = m_pGfxInfo->PointsList[0].y;
	string row =  "BLB " + to_string(ID) + " " + m_Label+ " "+to_string((int)resistance) + " "+to_string(p.x)+" "+ to_string(p.y) ;
	return row;
}
void Bulb::load(int id,string LABELi, double VALUE)
{
	ID = id;
	m_Label = LABELi;
	resistance = VALUE;
}
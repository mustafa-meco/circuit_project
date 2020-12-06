#include "Bulb.h"

Bulb::Bulb(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	
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
void Bulb::load(int id,string LABELi, double VALUE)  //load bulb
{
	ID = id;                  //id for bulb 
	m_Label = LABELi;         // new label for bulb
	resistance = VALUE;       // the resistance of the bulb 
}
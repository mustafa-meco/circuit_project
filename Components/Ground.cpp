#include "Ground.h"

Ground::Ground(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 0;
	sourceVoltage = 0;

}



void Ground::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawGround(*m_pGfxInfo, pcomp == this); //update to draw resistor

} 

void Ground::Operate()
{

}

string Ground::save() const {
	Point p;
	p.x = m_pGfxInfo->PointsList[0].x;
	p.y = m_pGfxInfo->PointsList[0].y;
	string row =  "GND " + to_string(ID) + " " + m_Label + " " + to_string((int)sourceVoltage) + " " + to_string(p.x) + " " + to_string(p.y);
	return row;
}
void Ground::load(int id,string LABELi, double VALUE)         //load if there is a Ground in the saved file 
{
	ID = id;               //id for the ground 
	m_Label = LABELi;      // label for the ground 
	//resistance = VALUE;    // the value of the ground resistance 
}
Component* Ground::Copy()                                    //Copy the component information 
{
	Component* B;
	B = new Ground(m_pGfxInfo);                  // create a new Component and save the previous info in the new one
	B->SetComponentlabel(m_Label);
	return B;

}
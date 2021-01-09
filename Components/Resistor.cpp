#include "Resistor.h"
#include <string>

Resistor::Resistor(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	
}

void Resistor::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo, pcomp == this); //update to draw resistor

}


void Resistor::Operate()
{

}

string Resistor::save() const {
	Point p;
	p.x = m_pGfxInfo->PointsList[0].x;
	p.y = m_pGfxInfo->PointsList[0].y;
	string row =  "RES " + to_string(ID) + " " + m_Label + " " +to_string((int)resistance)+" "+to_string(p.x)+" "+to_string(p.y) ;
	return row;
}
void Resistor::load(int id,string LABELi, double VALUE)        // load the resistance 
{
	ID= id,                             // id for the resistance
	m_Label = LABELi;                  //label for the resistance .
	resistance = VALUE;                //the value of the resitance 
}
void Resistor::Copy(Component* &B)
{
	B = new Resistor(m_pGfxInfo);
	B->setResistance(resistance);
	B->Setlabel(m_Label);
}
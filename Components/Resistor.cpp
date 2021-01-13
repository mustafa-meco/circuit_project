#include "Resistor.h"
#include <string>

Resistor::Resistor(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 1;
	sourceVoltage = 0;
	m_Label = ("Resistor");
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
void Resistor::load(int id,string LABELi, double VALUE)        //load if there is a Resistor in the saved file 
{
	ID= id,                             // id for the resistance
	m_Label = LABELi;                  //label for the resistance .
	resistance = VALUE;                //the value of the resitance 
}
Component* Resistor::Copy()                                    //Copy the component information 
{
	Component* B;
	B = new Resistor(m_pGfxInfo);                 // create a new Component and save the previous info in the new one
	B->setResistance(resistance);
	B->Setlabel(m_Label);
	return B;
}
int Resistor::GetOutStatus()
{
	return -1;
}
int Resistor::GetInputStatus()
{
	return -1;
}

void Resistor::setInputStatus(STATUS s)
{
}
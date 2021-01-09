#include "Module.h"
#include <string>

Module::Module(GraphicsInfo* r_GfxInfo, Resistor** r) :Component(r_GfxInfo)
{
	ResArr = r;
}

void Module::Draw(UI* pUI)
{
	//Call output class and pass Module drawing info to it.
	//pUI->DrawModule(*m_pGfxInfo, pcomp == this); //update to draw Module

}


void Module::Operate()
{

}

string Module::save() const {
	Point p;
	p.x = m_pGfxInfo->PointsList[0].x;
	p.y = m_pGfxInfo->PointsList[0].y;
	string row = "RES " + to_string(ID) + " " + m_Label + " " + to_string((int)resistance) + " " + to_string(p.x) + " " + to_string(p.y);
	return row;
}
void Module::load(int id, string LABELi, double VALUE)        // load the resistance 
{
	ID = id,                             // id for the resistance
		m_Label = LABELi;                  //label for the resistance .
	resistance = VALUE;                //the value of the resitance 
}
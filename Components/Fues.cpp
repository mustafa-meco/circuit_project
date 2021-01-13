#include"Fues.h"

Fues::Fues(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo) 
{
	resistance = 0;
	sourceVoltage = 0;
	m_Label = ("Fues");
	
}

void Fues::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawFues(*m_pGfxInfo, pcomp == this); //update to draw Fues

}
void Fues::Operate()
{


}

string Fues::save() const {
	Point p;
	p.x = m_pGfxInfo->PointsList[0].x;
	p.y = m_pGfxInfo->PointsList[0].y;
	string row =  "FUS " + to_string(ID) + " " + m_Label + " "+to_string((int)sourceVoltage)+" "+to_string(p.x)+" "+to_string(p.y) ;
	return row;
}
void Fues::load(int id,string LABELi, double VALUE)
{
	ID=id;                //id for the fuse 
	m_Label = LABELi;     //new label for the fuse
	resistance = VALUE;   // the value of the fuse resistance
}
Component* Fues::Copy()
{
	Component* B;
	B = new Fues(m_pGfxInfo);
	B->Setlabel(m_Label);
	return B;
}

int Fues::GetOutStatus()
{
	return -1;
}
int Fues::GetInputStatus()
{
	return -1;
}

void Fues::setInputStatus(STATUS s)
{
}
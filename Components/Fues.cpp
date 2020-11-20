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
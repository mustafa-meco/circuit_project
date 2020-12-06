#include "Component.h"
#include <iostream>
#include "..\UI\UI.h"
using namespace std;
Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;	
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;
	ID = ++gID;
}


Component::~Component()
{
}
bool Component::isInRegion(int x, int y, UI* pUI)
{
	if (m_pGfxInfo->PointsList[0].x < x && m_pGfxInfo->PointsList[1].x > x&& m_pGfxInfo->PointsList[0].y < y && m_pGfxInfo->PointsList[1].y > y)
	{
		pcomp = this;
		return true;
	}
}
//Connection** getTermConnections(TerminalNum Term)
//{
//
//}
void Component::addTerm1Connection(Connection* pConn)
{
	term1_conns[term1_conn_count++] = pConn;
}

void Component::addTerm2Connection(Connection* pConn)
{
	term2_conns[term2_conn_count++] = pConn; 
}

void Component::setResistance(double R) {
	resistance = R;
}
void Component::setSourceVoltage(double V) {
	sourceVoltage = V;
}
void Component::setStatus(bool S) {
	status = S;
}

int Component::getCompCenterx(UI*)
{
	int Xcenter = ((m_pGfxInfo->PointsList[1].x + m_pGfxInfo->PointsList[0].x) / 2); 
	return Xcenter;
}
int Component::getCompCentery(UI*)
{
	int Ycenter = ((m_pGfxInfo->PointsList[1].y + m_pGfxInfo->PointsList[0].y) / 2); 
	return Ycenter;
}
//TerminalNum Component::whichTerminal(Connection* Conn)
//{
//
//}

double Component::getResistance() {
	return resistance;
}

string Component::save() const {
	string row =  " ";
	return row;
}
 
int Component::getID() const {
	return ID;
}
void Component::load(int ,string, double)
{
	
}


Component* Component::pcomp = nullptr;
int Component::gID = 0;

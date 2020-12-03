#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\UI\UI.h"
#include "..\Connections\Connection.h"

//Base class for all components (resistor, capacitor,....etc) .
class Component
{
private:
	
protected:
	//Each component has two ending terminals (term1, term2)
	double term1_volt, term2_volt;	//voltage at terminals 1&2
	double resistance, sourceVoltage; // internal resistance and voltage jump introduced by source
	bool status;
	//Each terminal is connected to set of connections
	Connection *term1_conns[MAX_CONNS]; //list of pointers to connections
	Connection *term2_conns[MAX_CONNS];

	int term1_conn_count;	//actual no. of connections to each terminal
	int term2_conn_count;

	string m_Label;

	GraphicsInfo *m_pGfxInfo;	//The parameters required to draw a component
	static Component* pcomp;
public:
	Component(GraphicsInfo *r_GfxInfo);
	Component();
	//void setTerm1Volt(double v);		//sets the voltage at terminal1
	//void setTerm2Volt(double v);		//sets the voltage at terminal2
	//double getTerm1Volt();				//returns the voltage at terminal1
	//double getTerm2Volt();				//returns the voltage at terminal2
	double getResistance();
	//double getSourceVoltage(TerminalNum Term); // entering from terminal Term. Returns voltage jump/drop for battery, 0 otherwise
	Connection** getTermConnections(TerminalNum Term); 

	//double CalculateTermVoltage(TerminalNum term, double voltAtTerm, double currIntoTerm);	//Calculates the output voltage according to the inputs, sets terminal voltages
	virtual void Operate() = 0; // activates components such as bulb and buzzer

	virtual void Draw(UI*) = 0;	//for each component to Draw itself

	int getCompCenterx(UI*); // get horizontal/vertical centers of the component
	int getCompCentery(UI*);
	
	//virtual int GetOutStatus()=0;	//returns status of output if BULB/BUZZER, return -1
	//virtual int GetInputStatus()=0;	//returns status of SWITCH, return -1

	//virtual void setInputStatus(STATUS s)=0;	//set status of SWITCH

	bool isInRegion(int x, int y, UI* pUI); // whether this point lies inside the component
	void addTerm1Connection(Connection* pConn); //musta
	void addTerm2Connection(Connection* pConn);
	//void addTerm1Connection(Connection* pConn);
	//void addTerm2Connection(Connection* pConn);

	//TerminalNum whichTerminal(Connection* Conn); // returns the terminal to which a connection is connected
	virtual string* save() const;
	//Destructor must be virtual
	virtual ~Component();
	
	
	//static void selection();
	
};

#endif

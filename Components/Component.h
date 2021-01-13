#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\UI\UI.h"
#include "..\Connections\Connection.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
                    //Base class for all components (resistor, capacitor,....etc)//
//////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

class Component
{
private:	
protected:
	//bool mDeleted;                   
	
	//Each component has two ending terminals (term1, term2)
	double term1_volt, term2_volt;	  //voltage at terminals 1&2
	double resistance, sourceVoltage; // internal resistance and voltage jump introduced by source
	bool status;                      //check the status of wssome components
	bool polarity;                    //check the polarity of the circuit 
	//Each terminal is connected to set of connections
	Connection *term1_conns[MAX_CONNS]; //list of pointers to connections (term1)
	Connection *term2_conns[MAX_CONNS]; //list of pointers to connections (term2)

	
	struct demo
	{
		Connection* arr[MAX_CONNS]; 	   //array declared inside structure
	};

	int term1_conn_count;          	       //actual no. of connections to each terminal
	int term2_conn_count;

	int ID;                                // variable to take id for component
	static int gID;                        //counter for the id
	string m_Label;                        // variable to take the label
	//int choose;                         
	GraphicsInfo *m_pGfxInfo;              //The parameters required to draw a component
	static Component* pcomp;               //pointer to a component
public:
	
	Component(GraphicsInfo *r_GfxInfo);    //constructor to intialize data of the class
	
	void setTerm1Volt(double v);		//sets the voltage at terminal1 tayil
	
	void setTerm2Volt(double v);		//sets the voltage at terminal2 tayil 
	double getTerm1Volt();				//returns the voltage at terminal1
	double getTerm2Volt();				//returns the voltage at terminal2
	double getResistance();             //getter for the resistance 
	double getSourceVoltage();          //getter for the voltage value 
	//double getSourceVoltage(TerminalNum Term); // entering from terminal Term. Returns voltage jump/drop for battery, 0 otherwise
	Connection** getTermConnections(TerminalNum Term); 
	
	void setResistance(double);         // Setter for the resistance 
	void setSourceVoltage(double);      // getter for the source voltage value 
	void setStatus(bool);               //Setter for the status of some components 
	//double CalculateTermVoltage(TerminalNum term, double voltAtTerm, double currIntoTerm);	//Calculates the output voltage according to the inputs, sets terminal voltages
	virtual void Operate() = 0; // activates components such as bulb and buzzer

	virtual void Draw(UI*) = 0;	//for each component to Draw itself

	int getCompCenterx(UI*); // get horizontal/vertical centers of the component
	int getCompCentery(UI*);
	
	virtual int GetOutStatus()=0;	//returns status of output if BULB/BUZZER, return -1
	virtual int GetInputStatus()=0;	//returns status of SWITCH, return -1

	virtual void setInputStatus(STATUS s)=0;	//set status of SWITCH

	int getTermConnCount(TerminalNum) const;    //return the number of connection in the term

	int getID() const;                          //return the component id 

	bool isInRegion(int x, int y, UI* pUI);     // whether this point lies inside the component
	void addTerm1Connection(Connection* pConn); //icrease the number of connections (term 1)
	void addTerm2Connection(Connection* pConn); //icrease the number of connections (term 2)

	void removeTerm1Connection(Connection* pConn);  //decrease the number of connections (term 1)
	void removeTerm2Connection(Connection* pConn);  //decrease the number of connections (term 2)
	
	string Setlabel(string input);                  //setter for the component label 
	string getlabel();                              //getter for the component label 

	void SetGinfo(GraphicsInfo* G);                 //setter for the graphics info     

	void setm_pGfxInfo(int cx, int cy);             //change the graphics info of the component to use it for moving 

	TerminalNum whichTerminal(Connection* Conn);    //returns the terminal to which a connection is connected
	virtual string save() const;                    //save function 
	//Destructor must be virtual
	virtual ~Component();                           //destructor 
	virtual void load( int, string, double );       //load function 
	virtual Component* Copy() = 0;                  //pure virtual copy function
	
	//static void selection();
	GraphicsInfo* getm_pGfxInfo() ;                 //Getter for the new graphics info to use it for moving
	//void DeleteImage(GraphicsInfo* m_pGfxInfo, UI*);
	//virtual void setPolarity(BatPolarity p)= 0 ;
	//virtual BatPolarity GetPolarity() = 0;
};
#endif

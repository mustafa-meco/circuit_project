#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//Terminals
enum TerminalNum { TERM1, TERM2 };

//All possible actions
enum ActionType 
{
	ADD_RESISTOR,		//Add Resistor
	ADD_SWITCH,			//Add Switch
	ADD_BULB,			//Add Bulb
	ADD_GROUND,
	ADD_BATTERY,
	ADD_BUZZER,
	ADD_FUES,
	ADD_COPY,           //Add Copy
	ADD_CUT,            //Add Cut
	ADD_MOD,
	MOD_MODE,
	
 	ADD_PASTE,          //Add Paste 

	ADD_CONNECTION,		//Add Wire Connection 
	ADD_REALISTIC,
	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection

	FLIP_SWITCH,		//Change Switch status in Simulation Mode
	DEL,        //Delete a Component OR Connection
	SELECT,		//Select a Component, a Connection
	MDEL,		//Multiple Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled
	
	AMM,
	VOL,

	DSN_MODE,	//Switc	h to Design mode
	SIM_MODE,	//Switch to Simulatiom mode

	EXIT,		//Exit the application

	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar

};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION,
	MODULATION
};
enum BatPolarity 
{
	RTL, LTR
};
	
//enum BatPolarity {
//	RTL, LTR
//};

////////////////////////////////////////////////////////////////
//Maximum number of connections that can be connected to any output components
#define MAX_CONNS 20


#endif
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
	ADD_GROUND,         //Add Ground 
	ADD_BATTERY,        //Add Battery 
	ADD_BUZZER,         //Add Buzzer  
	ADD_FUES,           //Add fues
	ADD_COPY,           //Add Copy
	ADD_CUT,            //Add Cut
	ADD_MOD,            //Add module
	MOD_MODE,           //Add modulation  
	
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
	
	AMM,        //Ammeter
	VOL,        //voltameter  

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode

	EXIT,		//Exit the application
	TestSwitch,
	STATUS_BAR,		//A click on the status bar
	DSN_TOOL	//A click on an empty place in the design tool bar

};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION,
	MODULATION
};
enum BatPolarity  //direction of the battery which will used to calculate the voltage   
{
	RTL, LTR
};

enum STATUS
{
	open,
	close,

};


	
//enum BatPolarity {
//	RTL, LTR
//};

////////////////////////////////////////////////////////////////
//Maximum number of connections that can be connected to any output components
#define MAX_CONNS 20


#endif
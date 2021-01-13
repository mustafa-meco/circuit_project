#ifndef __UI_H_
#define __UI_H_

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include <string>
#include <vector>
using namespace std;

struct Point   // the location on the x axis and y axis for the point 
{
	int x,y;
};


//A structure to contain drawing parameters for each component/connection
//Each component stores its drawing points in this struct 
//For example, a resistor can store points of the rectangluar area it occupies
//The Connection can store the points of its line segments
//this structure can be extended if desired
struct GraphicsInfo
{
	int PointsCount;
	Point* PointsList;
	GraphicsInfo(int PtsCnt)
	{
		PointsCount = PtsCnt;
		PointsList = new Point[PointsCount];	//allocate required points
	}

};


class UI
{
	

	enum DsgnMenuItem //The items of the design menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in the menu
		//If you want to change the menu items order, just change the order here
		ITM_RES,		//Resistor item in menu
		//TODO: Add more items names here
		ITM_BULB,          //Bulb item in menu
		ITM_SWI,           //Switch item
		ITM_BAT,           //Battery item 
		ITM_GRO,           //Ground item
		ITM_BUZ,           //Buzzer item 
		ITM_FUE,           //fues item 
	 	ITM_MOD,           //Modulation item 
		ITM_CON,           //Connection item 
		ITM_SIM,           //simulation item 
		ITM_MODU,          //designed modulation item
		/*ITM_COPY,
		ITM_CUT,
		ITM_PASTE,
		ITM_EDIT,*/
		ITM_LABEL,         // label item  
		ITM_LOAD,          //Load item
		//ITM_SAVE,
		//ITM_MDELETE,
		ITM_EXIT,		//Exit item
	
		ITM_DSN_CNT	    //no. of design menu items ==> This should be the last line in this enum
	};
	enum ActionsToolBarItem
	{
		ITMA_Edit,          //Edit item in the menu  
		ITMA_Move,          //move item 
		ITMA_Save,          //save item
		ITMA_Undo,          //undo item
		ITMA_Redo,          //Redo item 
		ITMA_Copy,          //Copy item 
		ITMA_Cut,           //Cut item  
		ITMA_Paste,         //Paste item 
		ITMA_Delete,        //Delete item 
		ITMA_MDel,          // Modul item
		Itm_ACT_Num        
	};


	enum SimMenuItem //The items of the simulation menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in menu
		ITM_CIRC_SIM,	//Circuit Simulate menu item
		
		//TODO:Add more items names here
		ITM_AMM,          // Ammeter item
		ITM_VOL,          //voltmeter item
		ITM_DSN,          //design area item  
		ITM_SIM_CNT		 //no. of simulation menu items ==> This should be the last line in this enum
	
	};
	enum ModMenuItem { // items in modulation 
		MITM_RES,  //Resistance item 
		MITM_BULB, //Bulb item 
		MITM_BUZ,  //Buzzeer item 
		MITM_FUE,  //fues item
		MITM_MOD,  //the saved module item
		MITM_ADD_MOD, // Modulation item
		MITM_CON,   //connection item

		MITM_LOAD,  // laod item 
		MITM_DSN,   // design item
		ITM_MOD_CNT  //counter 

	};
		MODE AppMode;		//Application Mode (design or simulation)
	
	static const int	width = 1200, height = 650,	//Window width and height
		wx = 15, wy = 15,			//Window starting coordinates
		StatusBarHeight = 50,	//Status Bar Height
		ToolBarHeight = 80,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		ToolItemWidth = 80,		//Width of each item in toolbar menu


		ActionBarWidth = 65,


		//Arbitrary values, you can change as you wish
		COMP_WIDTH = 50,		//Component Image width
		COMP_HEIGHT = 50;		//Component Image height

	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color

	bool IsRealV;
	window* pWind;
	
public:
	
	UI();
	int getWidth()const;            //returns window width
	int getHeight()const;           //returns Component width
	int getCompWidth() const;	    //returns Component width
	int getCompHeight() const;	    //returns Component height
	int getStatusBarHeight() const; //returns Status Bar Height
	int getToolBarHeight() const;   //returns Tool Bar Height
	int getToolItemWidth() const;   //returns Tool Item Width
	

	
	// Input Functions  ---------------------------
	void GetPointClicked(int &, int &);	//Get coordinate where user clicks
	string GetSrting();		//Returns a string entered by the user

	ActionType GetUserAction() const; //Reads the user click and maps it to an action
	void detectMouse(int&, int&);      //detect the mouse click
	buttonstate getbuttonstate(button b, int& x, int& y); //Getter where the user clicks
	// Output Functions  ---------------------------
	void ChangeTitle(string Title) const; //change the title of the window

	void CreateErrorWind(string);          // create a window to show a message
	void DrawActionBar() const;            //draw a tool bar
	void DrawConfirm() const;              //

	void CreateDesignToolBar();	           //Tool bar of the design mode
	void CreateSimulationToolBar();        //Tool bar of the simulation mode
	void CreateStatusBar() const;	       //Create Status bar
	void ClearToolBar()const;              // clear the tool bar
	void ClearStatusBar() const;		   //Clears the status bar
	void ClearDrawingArea() const;	       //Clears the drawing area
	void ClearAll()const;                  //Clear all 
	void CreateModulationToolBar();
	void DrawReal() const;
	void DrawRealistic();
	// Draws a resistor
	void DrawResistor(const GraphicsInfo &r_GfxInfo, bool selected = false) const;
	//Draw a Bulb
	void DrawBulb(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	// Draw a switch
	void DrawSwitch(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawBattery(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	//Draw a ground 
	void DrawGround(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	//Draws a buzzer
	void DrawBuzzer(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	//Draws a fues
	void DrawFues(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	void DrawON(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	//void DrawEdit(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	// Draws Connection
	//void DrawConnection1(const GraphicsInfo &r_GfxInfo, bool selected = false) const;
	//void DrawConnection1(const GraphicsInfo& r_GfxInfo, bool selected = false) const; 
	void PrintMsg(string msg) const;	//Print a message on Status bar
	//void PrintLabel(string msg)const;
	//Draw A connection
	void DrawConnection(const GraphicsInfo& r_GfxInfo, bool selected) const;   //,bool selected
 
	
	void DrawWhite(const GraphicsInfo& r_GfxInfo);
	//void PrintLabel(string msg)const;
    // Draws Connection
	//void DrawConnection(const GraphicsInfo& r_GfxInfo ) const;      //Mustafa Mahmoud Tayel 
    //void DrawConnection(const GraphicsInfo& r_GfxInfo ) const;   	// Draws Connection
	//Draw a Module 
	void DrawModule(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	bool IsReal();
	~UI();
};

#endif
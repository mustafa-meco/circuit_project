#ifndef __UI_H_
#define __UI_H_

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include <string>
using namespace std;

struct Point
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
		ITM_BULB,
		ITM_SWI,           //Switch item in menu
		ITM_BAT,
		ITM_GRO,           //Ground item in menu
		ITM_BUZ,
		ITM_FUE,
		ITM_LOAD,        //Load item 
		ITM_CON,         //connection item 
		ITM_SIM,
		ITM_COPY,
		ITM_CUT,
		ITM_PASTE,
		ITM_EDIT,
		ITM_LABEL,
		ITM_SAVE,
		
		ITM_EXIT,		//Exit item
	
		ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum
	};
	enum Select 
	{A


	};

	enum SimMenuItem //The items of the simulation menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in menu
		ITM_CIRC_SIM,	//Circuit Simulate menu item
		
		//TODO:Add more items names here
		ITM_AMM,
		ITM_VOL,
		ITM_DSN,
		ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
	
	};


	MODE AppMode;		//Application Mode (design or simulation)
	
	static const int	width = 1200, height = 650,	//Window width and height
						wx = 15 , wy = 15,			//Window starting coordinates
						StatusBarHeight = 50,	//Status Bar Height
						ToolBarHeight = 80,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
						ToolItemWidth = 80,		//Width of each item in toolbar menu

						//Arbitrary values, you can change as you wish
						COMP_WIDTH = 50,		//Component Image width
						COMP_HEIGHT = 50;		//Component Image height

	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color


	window *pWind;
	
public:
	
	UI();
	int getCompWidth() const;	//returns Component width
	int getCompHeight() const;	//returns Component height
	
	
	// Input Functions  ---------------------------
	void GetPointClicked(int &, int &);	//Get coordinate where user clicks
	string GetSrting();		//Returns a string entered by the user

	ActionType GetUserAction() const; //Reads the user click and maps it to an action

	
	// Output Functions  ---------------------------
	void ChangeTitle(string Title) const;

	void CreateErrorWind(string);

	void CreateDesignToolBar();	//Tool bar of the design mode
	void CreateSimulationToolBar();//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar
	void ClearToolBar()const;
	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area
	void ClearAll()const;  //Clear all 
		
	// Draws a resistor
	void DrawResistor(const GraphicsInfo &r_GfxInfo, bool selected = false) const;
	///TODO: Make similar functions for drawing all other components, connections, .. etc
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

	//void DrawEdit(const GraphicsInfo& r_GfxInfo, bool selected = false) const;
	// Draws Connection
	//void DrawConnection1(const GraphicsInfo &r_GfxInfo, bool selected = false) const;
	//void DrawConnection1(const GraphicsInfo& r_GfxInfo, bool selected = false) const; 
	void PrintMsg(string msg) const;	//Print a message on Status bar
	//void PrintLabel(string msg)const;

	void DrawConnection(const GraphicsInfo& r_GfxInfo, bool selected) const;   //,bool selected
	void DeleteConnection(const GraphicsInfo& r_GfxInfo);





	//void PrintLabel(string msg)const;

	// Draws Connection
	void DrawConnection(const GraphicsInfo& r_GfxInfo ) const;   


	
	~UI();
};

#endif
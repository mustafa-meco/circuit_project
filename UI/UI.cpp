#include "UI.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\CMUgraphicsLib\auxil.h"
UI::UI()
{
	AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	DrawColor = BLACK;
	SelectColor = BLUE;
	ConnColor = RED;
	MsgColor = BLUE;
	BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = new window(width, height, wx, wy);	


	ChangeTitle("Circuit Simulator Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar
}
void UI::CreateErrorWind(string s) {
	window* pErWind;
	pErWind = new window(width/4, height/4, (wx+width/2)-width/8, (wy+height/2)-height/8);
	//pErWind->SetBuffering(false);
	pErWind->SetPen(BLACK);
	pErWind->SetBrush(RED);
	pErWind->DrawRectangle(0, 0, width /5, height/5);
	char key;
	pErWind->DrawString(width / 10, height / 10, s+"\npress any key");
	pErWind->WaitKeyPress(key);
	delete pErWind;
}

int UI::getCompWidth() const
{
	return COMP_WIDTH;
}

int UI::getCompHeight() const
{
	return COMP_HEIGHT;
}
int UI::getStatusBarHeight() const
{
	return StatusBarHeight;
}
int UI::getToolBarHeight() const
{
	return ToolBarHeight;
}
int UI::getToolItemWidth() const
{
	return ToolItemWidth;
}
int UI::getWidth() const
{
	return width;
}
int UI::getHeight() const
{
	return height;
}

//======================================================================================//
//								Input Functions 										//
//======================================================================================//

void UI::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string UI::GetSrting()
{
	//Reads a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" is also supported
	//User should see what he is typing at the status bar


	string userInput;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);

		switch(Key)
		{
		case 27: //ESCAPE key is pressed
			PrintMsg("");
			return ""; //returns nothing as user has cancelled the input
		
		case 13:		//ENTER key is pressed
			return userInput;
		
		case 8:		//BackSpace is pressed
			if(userInput.size() > 0)
				userInput.resize(userInput.size() -1 );
			break;
		
		default:
			userInput+= Key;
		};
		
		PrintMsg(userInput);
		//PrintLabel(userInput);
	}

}




//This function reads the position where the user clicks to determine the desired action
ActionType UI::GetUserAction() const
{	
	int x,y;
	clicktype v;
	v = pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < ToolBarHeight && v == 1)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RES:	return ADD_RESISTOR;
			case ITM_BULB:	return ADD_BULB;
			case ITM_SWI:	return ADD_SWITCH;
			case ITM_BAT:   return ADD_BATTERY;
			case ITM_GRO:   return ADD_GROUND;
			case ITM_BUZ:   return ADD_BUZZER;
			case ITM_FUE:   return ADD_FUES;
			case ITM_CON:   return ADD_CONNECTION;
			case ITM_SIM:	return SIM_MODE;
			/*case ITM_COPY:   return ADD_COPY;
			case ITM_CUT:   return ADD_CUT;
			case ITM_PASTE:   return ADD_PASTE;
			case ITM_EDIT:  return EDIT_Label;*/
			case ITM_LABEL: return ADD_Label;
			case ITM_SAVE:  return SAVE;
			case ITM_LOAD:	return LOAD; 
			/*case ITM_DELETE:return DEL;*/
			case ITM_EXIT:	return EXIT;	
			
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
	
		//[2] User clicks on the drawing area
		if ( y >= ToolBarHeight && y < height - StatusBarHeight )
		{
			if (v == 2)
				DrawActionBar();
			else
				return SELECT;	//user wants to select/unselect a component
		}
	
		if (y >= ToolBarHeight && y < height - StatusBarHeight )
		{
			int x1, y1;
			PrintMsg("Click on action to execute");
			pWind->WaitMouseClick(x1, y1);
			pWind->SetPen(WHITE);
			pWind->DrawRectangle(1135, 80, 1200, 600, FILLED);
			ClearStatusBar();
			int ClickedItemOrder = (y1 - ToolBarHeight) / 50;
			if (x1 > width - ActionBarWidth && x1 < width)
			{
				switch (ClickedItemOrder)
				{
				case ITMA_Edit:		return EDIT_Label;
				case ITMA_Move:		return MOVE;
				case ITMA_Load:		return LOAD;
				case ITMA_Save:		return SAVE;
				case ITMA_Undo:		return UNDO;
				case ITMA_Redo:		return REDO;
				case ITMA_Copy:		return ADD_COPY;
				case ITMA_Cut:		return ADD_CUT;
				case ITMA_Paste:	return ADD_PASTE;
				case ITMA_Delete:	return DEL;
				default:			return DSN_TOOL;
				}
			}
		}
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		
		if (y >= 0 && y < ToolBarHeight)
		{
			
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_DSN:	return DSN_MODE;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return SELECT;	//user wants to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;	//This should be changed after creating the compelete simulation bar 
	}

}

buttonstate UI::getbuttonstate(button b, int& x, int& y)
{
	return	pWind->GetButtonState(b, x, y);
}

void UI::detectMouse(int& x, int& y)
{
	pWind->GetMouseCoord(x, y);

}

//======================================================================================//
//								Output Functions										//
//======================================================================================//

//////////////////////////////////////////////////////////////////////////////////
void UI::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, height-StatusBarHeight, width, height-StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(MsgColor); 
	pWind->DrawString(MsgX, height - MsgY, msg);
}





/*void UI::PrintLabel(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(200, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(MsgColor);
	pWind->DrawString(MsgX, height - MsgY, msg);
}*/
//////////////////////////////////////////////////////////////////////////////////
void UI::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(MsgX, height - MsgY, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void UI::ClearToolBar()const
{
	// Set the Message offset from the Status Bar


	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, 0, width, ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void UI::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);
}
///////////////////////////////////////////////////////////////////////////////////////////
void UI::ClearAll()const
{
	ClearDrawingArea();
	ClearToolBar();
	ClearStatusBar();
	pWind->SetPen(WHITE,1000000);
	pWind->DrawLine(0, height - StatusBarHeight, width, height - StatusBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void UI::CreateDesignToolBar() 
{
	ClearToolBar();
	AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_RES] = "images\\Menu\\Menu_Resistor.jpg";
	MenuItemImages[ITM_BULB] = "images\\Menu\\Menu_Bulb.jpg";
	MenuItemImages[ITM_SWI] = "images\\Menu\\Menu_switch.jpeg";			 //Add image for switch
	MenuItemImages[ITM_GRO] = "images\\Menu\\Menu_Ground.jpg"; 			 //Add image for ground 
	MenuItemImages[ITM_BAT] = "images\\Menu\\Menu_Battery.jpg";
	MenuItemImages[ITM_BUZ] = "Images\\Menu\\Menu_buzzer.jpg";
	MenuItemImages[ITM_FUE] = "Images\\Menu\\Menu_Fues.jpg";
	MenuItemImages[ITM_CON] = "Images\\Menu\\Menu_Connection.jpg";		 //Add image for connection
	MenuItemImages[ITM_LOAD] = "Images\\Menu\\Menu_Load.jpg";			 //Add image for Load
	MenuItemImages[ITM_SIM] = "Images\\Menu\\sim.jpg";
	MenuItemImages[ITM_SAVE] = "Images\\Menu\\save.jpg";
	/*MenuItemImages[ITM_COPY] = "Images\\Menu\\Menu_Copy.jpeg";
	MenuItemImages[ITM_CUT] = "Images\\Menu\\Menu_Cut.jpeg";
	MenuItemImages[ITM_PASTE] = "Images\\Menu\\Menu_Paste.jpeg";	
	MenuItemImages[ITM_EDIT] = "images\\Menu\\Menu_Edit.jpg";*/
	MenuItemImages[ITM_LABEL] = "images\\Menu\\Menu_Label.jpg";

	MenuItemImages[ITM_SAVE] = "Images\\Menu\\save.jpg";
	/*MenuItemImages[ITM_DELETE] = "Images\\Menu\\Menu_Delete.jpg";*/
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*ToolItemWidth,0,ToolItemWidth, ToolBarHeight);
	
	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void UI::CreateSimulationToolBar()
{
	
	ClearToolBar();
	AppMode = SIMULATION;	//Simulation Mode
	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[ITM_CIRC_SIM] = "images\\Menu\\simulate.jPG";
	MenuItemImages[ITM_AMM] = "images\\Menu\\ammeter.jpg";
	MenuItemImages[ITM_VOL] = "images\\Menu\\voltmeter.jpg";
	MenuItemImages[ITM_DSN] = "images\\Menu\\design.jpg";

	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * ToolItemWidth, 0, ToolItemWidth, ToolBarHeight);

	
}
void UI::DrawActionBar()const
{
	//Delete, Num;
	string ActionsImages[Itm_ACT_Num];
	ActionsImages[ITMA_Edit] = "images\\Choice\\Edit.jpg";
	ActionsImages[ITMA_Move] = "images\\Choice\\Move.jpg";
	ActionsImages[ITMA_Load] = "images\\Choice\\Load.jpg";
	ActionsImages[ITMA_Save] = "images\\Choice\\Save.jpg";
	ActionsImages[ITMA_Undo] = "images\\Choice\\Undo.jpg";
	ActionsImages[ITMA_Redo] = "images\\Choice\\Redo.jpg";
	ActionsImages[ITMA_Copy] = "images\\Choice\\Copy.jpg";
	ActionsImages[ITMA_Cut] = "images\\Choice\\Cut.jpg";
	ActionsImages[ITMA_Paste] = "images\\Choice\\Paste.jpg";
	ActionsImages[ITMA_Delete] = "images\\Choice\\Delete.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < Itm_ACT_Num; i++)
		pWind->DrawImage(ActionsImages[i], width-ActionBarWidth, i * 52 + 80, 50, 50);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(1134, 80, 1134, 600);
}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void UI::DrawResistor(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	string ResImage;
	if(selected)	
		ResImage ="Images\\Comp\\Resistor_HI.jpg";	//use image of highlighted resistor
	else  
		ResImage = "Images\\Comp\\Resistor.jpg";	//use image of the normal resistor

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(ResImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

//TODO: Add similar functions to draw all other components
void UI::DrawBulb(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string BulImage;
	if (selected)
		BulImage = "Images\\Comp\\Bulb_HI.jpg";	//use image of highlighted bulb
	else
		BulImage = "Images\\Comp\\Bulb.jpg";	//use image of the normal bulb

	//Draw Bulb at Gfx_Info (1st corner)
	pWind->DrawImage(BulImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

void UI::DrawSwitch(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string SwiImage;
	if (selected)
		SwiImage = "Images\\Comp\\Switch_HI.jpg";	//use image of highlighted bulb
	else
		SwiImage = "Images\\Comp\\Switch.jpeg";	//use image of the normal bulb

	//Draw Bulb at Gfx_Info (1st corner)
	pWind->DrawImage(SwiImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}
void UI::DrawBattery(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string BatImage;
	if (selected)
		BatImage = "Images\\Comp\\Battery_HI.jpg";	//use image of highlighted battery
	else
		BatImage = "Images\\Comp\\Battery.jpg";	//use image of the normal battery

	//Draw battery at Gfx_Info (1st corner)
	pWind->DrawImage(BatImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}
void UI::DrawGround(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GroImage;
	if (selected)
		GroImage = "Images\\Comp\\Ground_HI.jpg";	//use image of highlighted ground
	else
		GroImage = "Images\\Comp\\Ground.jpg";	//use image of the normal 

	//Draw ground at Gfx_Info (1st corner)
	pWind->DrawImage(GroImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}
void UI::DrawBuzzer(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string ResImage;
	
	
		if (selected)
		{
			ResImage = "Images\\Comp\\buzzer_HI.jpg";	//use image of highlighted buzzer

		}
		else
		{
			ResImage = "Images\\Comp\\buzzer.jpg";	//use image of the normal buzzer

		}
	
	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(ResImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}
void UI::DrawFues(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string ResImage;
	if (selected)
	{
		ResImage = "Images\\Comp\\Fues_HI.jpg";	//use image of highlighted fues

	}
	else
	{
		ResImage = "Images\\Comp\\Fues.jpg";	//use image of the normal fues

	}
	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(ResImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}


void UI::DrawConnection(const GraphicsInfo& r_GfxInfo, bool selected) const //bool selected
{
	if (selected==true)
	//if (AppMode == DESIGN)	//application is in design mode
	{
		//if (r_GfxInfo.PointsList[0].y > ToolBarHeight && r_GfxInfo.PointsList[0].y < height - StatusBarHeight && r_GfxInfo.PointsList[1].y > ToolBarHeight && r_GfxInfo.PointsList[1].y < height - StatusBarHeight)
		pWind->SetPen(PINK, 3);
		pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
	}
	else
	{
		pWind->SetPen(BLACK, 3);
		pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
	}	
}
void UI::DeleteConnection(const GraphicsInfo& r_GfxInfo) 
{
	pWind->SetPen(WHITE, 3);
	pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
}

void UI::DrawWhite(const GraphicsInfo& r_GfxInfo)
{
	pWind->SetPen(WHITE);
	pWind->DrawRectangle(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[0].x+ COMP_WIDTH, r_GfxInfo.PointsList[0].y+ COMP_HEIGHT);
}






UI::~UI()
{
	// TODO
}
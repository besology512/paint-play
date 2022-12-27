#pragma once
#include <vector>

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"
#include<cmath>

#include <vector>
#include <string>
using namespace std;

struct Point // To be used for shapes points
{
	int x, y;
};

struct GfxInfo // Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	 // Draw color of the shape
	color FillClr;	 // Fill color of the shape
	bool isFilled;	 // shape Filled or not
	int BorderWdth;	 // Width of shape borders
	bool isSelected; // true if the shape is selected.
	//bool isSaved = false;
};


class GUI
{
	enum GUI_MODE // Graphical user interface mode
	{
		MODE_DRAW, // Drawing mode (startup mode)
		MODE_PLAY  // Playing mode
	};

	enum DrawMenuIcon // The icons of the Draw menu (you should add more icons)
	{
		// Note: Icons are ordered here as they appear in menu
		// If you want to change the menu icons order, change the order here
		ICON_UNDO,
		ICON_REDO,
		ICON_LINE,
		ICON_SQUARE,	//Square icon in menu
		ICON_RECT, // Recangle icon in menu
		ICON_TRIANGLE,
		ICON_CIRC, // Circle icon in menu
		ICON_OVAL,
		ICON_REGULAR_POLYGON,
		ICON_IRR_POLYGON,
		ICON_PICKER,
		ICON_FILL,
		ICON_BORDER_CLR,
		ICON_BORDER_WIDTH,
		ICON_RESIZE,
		ICON_ROTATE,
		ICON_DELETE,
		ICON_SAVE,
		ICON_LOAD,
		ICON_STICKIMAGE,
		ICON_SWITCH,

		//TODO: Add more icons names here

		ICON_EXIT, // Exit icon

		DRAW_ICON_COUNT // no. of menu icons ==> This should be the last line in this enum

	};

	
	enum PlayMenuIcon // The icons of the Play menu (you should add more icons)
	{
		// Note: Icons are ordered here as they appear in menu
		// If you want to change the menu icons order, change the order here

		ICON_START,
		ICON_RESTART,
		// TODO: Add more icons names here
		ICON_EXIT_PLAYMODE,
		

		PLAY_ICON_COUNT // no. of menu icons ==> This should be the last line in this enum

	};

	GUI_MODE InterfaceMode = MODE_DRAW;

	int width, height,	 // Window width and height
		wx, wy,			 // Window starting coordinates
		StatusBarHeight, // Status Bar Height
		ToolBarHeight,	 // Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth;	 // Width of each icon in toolbar menu

	color DrawColor;	  // Drawing color
	color FillColor;	  // Filling color
	color HighlightColor; // Highlighting color
	color MsgColor;		  // Messages color
	color BkGrndColor;	  // Background color
	color StatusBarColor; // Status bar color
	int PenWidth;		  // width of the pen that draws shapes

	/// Add more members if needed

	window *pWind;

public:
	GUI();

	// Input Functions  ---------------------------

	void GetPointClicked(int& , int&) const;//Get coordinate where user clicks
	void GetMousCoord(int& , int&) const;//Get the current mouse Coord
	void GetKeyClicked(char& cKey) const; //Get the keyboard buttons where user clicks
	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation() const; //Read the user click and map to an operation
  
	// Output Functions  ---------------------------
	window *CreateWind(int, int, int, int) const; // creates the application window
	void CreateDrawToolBar();					  // creates Draw mode toolbar & menu
	void CreatePlayToolBar();					  // creates Play mode toolbar & menu
	void CreateStatusBar() const;				  // create the status bar

	void ClearStatusBar() const; // Clears the status bar
	void ClearToolBar() const;	// clear the toolbar
	void ClearDrawArea() const;	 // Clears the drawing area
	void DrawColorPicker();
	void PickColor(int, int, double&, double&, double&);
	void setFillcolor(color);
	void setDrawColor(color);
	void setBorderWidth(int);


	// -- shapes Drawing functions

	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a rectangle
	void DrawTriangle(Point P1, Point P2,Point P3 ,GfxInfo TriaGfxInfo) const;
	void DrawCircle(Point P1, Point P2,GfxInfo CirclGfxInfo) const;
	void DrawOval(Point P1, Point P2, GfxInfo OvalGfxInfo) const;  //Draw an Oval
	void DrawSquare(Point P1, Point P2, GfxInfo SquareGfxInfo) const;  //Draw a Square
	void DrawRegularPolygon(Point center, double numOfVertices, double radius, GfxInfo RegularPolygonGfxInfo) const; // Draw a regular Polygon
	void DrawIrrPolygon(vector<Point> allPoints, int vericies, GfxInfo IrrPolGfxInfo) const; //Draw Irregular Polygon
	void DrawLine(Point P1, Point P2, GfxInfo LineGfcInfo) const;  // Draw a Line 
	void DrawImage(Point P1, double width, double height,GfxInfo ImageInfo);
	//DrawImage(const image *imgThis, const int iX, const int iY, const int iWidth, const int iHeight)
	
	


	///Make similar functions for drawing all other shapes.

	/// Make similar functions for drawing all other shapes.

	void PrintMessage(string msg) const; // Print a message on Status bar

	color getCrntDrawColor() const; // get current drwawing color
	color getCrntFillColor() const; // get current filling color
	int getCrntPenWidth() const;	// get current pen width

	~GUI();
};

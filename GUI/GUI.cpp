#include<cmath>
#include "GUI.h"
#include<ctime>
#include<iostream>

GUI::GUI()
{
	// Initialize user interface parameters
	InterfaceMode = MODE_DRAW;
	//InterfaceMode = MODE_DRAW
	if (InterfaceMode == MODE_DRAW) {
		width = 1400;
		height = 600;
		wx = 5;
		wy = 5;

		StatusBarHeight = 50;
		ToolBarHeight = 50;
		MenuIconWidth = 40;

		DrawColor = BLUE;		  // default Drawing color
		FillColor = GREEN;		  // default Filling color
		MsgColor = BLACK;		  // Messages color
		BkGrndColor = WHITE;	  // Background color
		HighlightColor = MAGENTA; // This color should NOT be used to draw shapes. use if for highlight only
		StatusBarColor = LIGHTSEAGREEN;
		PenWidth = 3; // default width of the shapes frames

		// Create the output window
		pWind = CreateWind(width, height, wx, wy);
		// Change the title
		pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

		CreateDrawToolBar();
		CreateStatusBar();
	}

	
	else{
		//InterfaceMode = MODE_PLAY;

		width = 900;
		height = 770;
		wx = 5;
		wy = 5;

		StatusBarHeight = 50;
		ToolBarHeight = 50;
		MenuIconWidth = 50;

		MsgColor = BLACK;		  // Messages color
		BkGrndColor = WHITE;	  // Background color
		StatusBarColor = LIGHTSEAGREEN;

		// Create the output window
		pWind = CreateWind(width, height, wx, wy);
		// Change the title
		pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

		CreatePlayToolBar();
		CreateStatusBar();
		
	}
}

//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int &x, int &y) const
{
	pWind->FlushMouseQueue();
	pWind->WaitMouseClick(x, y); // Wait for mouse click	
}

void GUI::GetMousCoord(int &x, int &y) const
{
	pWind->FlushMouseQueue();
	pWind->GetMouseCoord(x,y);
}

void GUI::GetKeyClicked(char &Key) const
{
	pWind->FlushKeyQueue();
	pWind->WaitKeyPress(Key); // Get the keyboard button clicked
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE) // ESCAPE key is pressed
			return "";		 // returns nothing as user has cancelled label
		if (Key == 13)		 // ENTER key is pressed
			return Label;
		if (Key == 8) // BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		PrintMessage(Label);
	}
}

// This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	// put the shortcuts here
	while (GetKeyState(VK_LCONTROL) < 0)
	{
		PrintMessage("L CTRL + ...");
		char CharAfterControl;
		GetKeyClicked(CharAfterControl);
		if (CharAfterControl == 'c')
		{
			PrintMessage("Copy");
			return COPY;
		}
		else if (CharAfterControl == 'v') {
			PrintMessage("Paste");
			return PASTE;
		}
		else if (CharAfterControl == 'x') {
			PrintMessage("Cut");
			return CUT;
		}
	}
	int x, y;
	pWind->WaitMouseClick(x, y); // Get the coordinates of the user click

	if (InterfaceMode == MODE_DRAW) // GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			// Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			// Divide x coord of the point clicked by the menu icon width (int division)
			// if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_UNDO: return UNDO;
			case ICON_REDO: return REDO;
			case ICON_RECT: return DRAW_RECT;
			case ICON_CIRC: return DRAW_CIRC;
			case ICON_TRIANGLE: return DRAW_TRI;
			case ICON_OVAL: return DRAW_OVAL;
			case ICON_SQUARE: return DRAW_SQUARE;
			case ICON_REGULAR_POLYGON: return DRAW_REGULAR_POLYGON;
			case ICON_IRR_POLYGON: return DRAW_IRR_POLYGON;
			case ICON_LINE: return DRAW_LINE;
			case ICON_COPY: return COPY;
			case ICON_PASTE: return PASTE;
			case ICON_CUT: return CUT;
			case ICON_SAVE: return SAVE;
			case ICON_LOAD: return LOAD;
			case ICON_STICKIMAGE: return STICK_IMAGE;
			case ICON_PICKER: return PICK_COLOR;
			case ICON_FILL: return CHNG_FILL_CLR;
			case ICON_BORDER_CLR: return CHNG_BORDER_CLR;
			case ICON_BORDER_WIDTH: return CHNG_BORDER_WIDTH;
			case ICON_ZOOM_IN: return ZOOM_IN;
			case ICON_ZOOM_OUT: return ZOOM_OUT;
			case ICON_DRAG: return DRAG;
			case ICON_RESIZE: return RESIZE;
			case ICON_ROTATE: return ROTATE;
			case ICON_SENDBACK: return SEND_BACK;
			case ICON_DELETE: return DEL;
			case ICON_SCRAMBLE: return SCRAMBLE;
			case ICON_SWITCH: return SWITCH;
			case ICON_DUPLICATE: return DUPLICATE_GRAPH;
			case ICON_EXIT: return EXIT;
			

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	
	else // GUI is in PLAY mode
	{
		/// TODO:
		// perform checks similar to Draw mode checks above
		// and return the correspoding operation
		if (y >= 0 && y < ToolBarHeight) {
			
			// Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			// Divide x coord of the point clicked by the menu icon width (int division)
			// if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on
			
			switch (ClickedIconOrder) {
			
			case ICON_START: return START;
			case ICON_RESTART: return RESTART;
			case ICON_EXIT_PLAYMODE: return EXIT;
			case ICON_HIDE: return HIDE;
			case ICON_UNHIDE: return UNHIDE;


			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the playing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return PLAYING_AREA;
		}

		return TO_PLAY; // just for now. This should be updated
	}
}
int GUI::getWidth()
{
	int h = width;
	return h;
}
int GUI::getHeight()
{
	return height-100;
}
////////////////////////////////////////////////////

//======================================================================================//
//								Output Functions										//
//======================================================================================//

window *GUI::CreateWind(int w, int h, int x, int y) const
{
	window *pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	// Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearToolBar() const
{
	// Clear Tool bar by drawing a filled white rectangle
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(5, 5, width, -ToolBarHeight);
	pWind->DrawRectangle(5, 5, width, ToolBarHeight);
}
/////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreateDrawToolBar()
{
	InterfaceMode = MODE_DRAW;

	// You can draw the tool bar icons in any way you want.
	// Below is one possible way

	// First prepare List of images for each menu icon
	// To control the order of these images in the menu,
	// reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_REDO] = "images\\MenuIcons\\Menu_Redo.jpg";
	MenuIconImages[ICON_UNDO] = "images\\MenuIcons\\Menu_Undo.jpg";
	MenuIconImages[ICON_LINE] = "images\\MenuIcons\\Menu_Line.jpg";
	MenuIconImages[ICON_SQUARE] = "images\\MenuIcons\\Menu_Square.jpg";
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\Menu_Rect.jpg";
	MenuIconImages[ICON_TRIANGLE] = "images\\MenuIcons\\Menu_Triangle.jpg";
	MenuIconImages[ICON_CIRC] = "images\\MenuIcons\\Menu_Circ.jpg";
	MenuIconImages[ICON_OVAL] = "images\\MenuIcons\\Menu_Oval.jpg";
	MenuIconImages[ICON_REGULAR_POLYGON] = "images\\MenuIcons\\Menu_RegShape.jpg";
	MenuIconImages[ICON_SAVE] = "images\\MenuIcons\\Menu_Save.jpg";
	MenuIconImages[ICON_IRR_POLYGON] = "images\\MenuIcons\\Menu_IrrPolygon.jpg";
	MenuIconImages[ICON_COPY] = "images\\MenuIcons\\Menu_Copy.jpg";
	MenuIconImages[ICON_CUT] = "images\\MenuIcons\\Menu_Cut.jpg";
	MenuIconImages[ICON_PASTE] = "images\\MenuIcons\\Menu_Paste.jpg";
	MenuIconImages[ICON_PICKER] = "images\\MenuIcons\\Menu_ColorPicker.jpg";
	MenuIconImages[ICON_FILL] = "images\\MenuIcons\\Menu_Fill.jpg";
	MenuIconImages[ICON_BORDER_CLR] = "images\\MenuIcons\\Menu_changePenColor.jpg";
	MenuIconImages[ICON_BORDER_WIDTH] = "images\\MenuIcons\\Menu_ChangeBorderWidth.jpg";
	MenuIconImages[ICON_ZOOM_IN] = "images\\MenuIcons\\Menu_zoomin.jpg";
	MenuIconImages[ICON_ZOOM_OUT] = "images\\MenuIcons\\Menu_zoomout.jpg";
	MenuIconImages[ICON_DRAG] = "images\\MenuIcons\\Menu_Drag.jpg";
	MenuIconImages[ICON_RESIZE] = "images\\MenuIcons\\Menu_Resize.jpg";
	MenuIconImages[ICON_ROTATE] = "images\\MenuIcons\\Menu_Rotate.jpg";
	MenuIconImages[ICON_SWITCH] = "images\\MenuIcons\\Menu_Switch.jpg";
	MenuIconImages[ICON_DUPLICATE] = "images\\MenuIcons\\Duplicate_Graph.jpg";
	MenuIconImages[ICON_SENDBACK] = "images\\MenuIcons\\Menu_SendBack.jpg";
	MenuIconImages[ICON_DELETE] = "images\\MenuIcons\\Menu_Delete.jpg";
	MenuIconImages[ICON_SAVE] = "images\\MenuIcons\\Menu_Save.jpg";
	MenuIconImages[ICON_LOAD] = "images\\MenuIcons\\Menu_Load.jpg";
	MenuIconImages[ICON_STICKIMAGE] = "images\\MenuIcons\\Menu_StickImage.jpg";
	MenuIconImages[ICON_SCRAMBLE] = "images\\MenuIcons\\Menu_Scramble.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";
	

	

	// TODO: Prepare images for each menu icon and add it to the list

	// Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);

	// Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreatePlayToolBar()
{
	InterfaceMode = MODE_PLAY;
	
	//ClearToolBar();
	string MenuIconImages[PLAY_ICON_COUNT];
	MenuIconImages[ICON_START] = "images\\MenuIcons\\Menu_Start.jpg";
	MenuIconImages[ICON_RESTART] = "images\\MenuIcons\\Menu_Restart.jpg";
	MenuIconImages[ICON_EXIT_PLAYMODE] = "images\\MenuIcons\\Menu_Exit.jpg";
	MenuIconImages[ICON_HIDE] = "images\\MenuIcons\\Menu_Hide.jpg";
	MenuIconImages[ICON_UNHIDE] = "images\\MenuIcons\\Menu_Unhide.jpg";

	/// TODO: write code to create Play mode menu

	for (int i = 0; i < PLAY_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);

	// Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const // Prints a message on status bar
{
	ClearStatusBar(); // First clear the status bar
	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const // get current drwawing color
{
	return DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::DrawColorPicker() {
	string path = "images\\MenuIcons\\Menu_Pellet.jpg";
	pWind->DrawImage(path, 400, 50, 610, 500);
}

void GUI::PickColor(int x,int y,double &dRed, double& dGreen, double& dBlue) {
	pWind->GetColor(x, y, dRed, dGreen, dBlue);
}

//////////////////////////////////////////////////////////////////////////////////////////
color GUI::getCrntFillColor() const // get current filling color
{
	return FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const // get current pen width
{
	return PenWidth;
}

void GUI::setFillcolor(color newColor)
{
	FillColor = newColor;
	pWind->SetBrush(newColor);
}

void GUI::setDrawColor(color newColor)
{
	DrawColor = newColor;
}

void GUI::setBorderWidth(int w)
{
	PenWidth = w;
}

buttonstate GUI::Dragging(int &xx, int &yy) {
	 pWind->FlushMouseQueue();
	return pWind->GetButtonState(LEFT_BUTTON,xx,yy);
	 
}

//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)		 // shape is selected
		DrawingClr = HighlightColor; // shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth); // Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

	if (RectGfxInfo.isHidden == true) {
		drawstyle styleRect;
		styleRect = FILLED;
		/*Point cr1, cr2;
		cr1.x = min(P1.x, P2.x) - 2;
		cr1.y = min(P1.y, P2.y) - 2;
		cr2.x = max(P1.x, P2.x) + 2;
		cr2.y = max(P1.y, P2.y) + 2;*/

		pWind->SetBrush(GREEN);
		pWind->SetPen(GREEN, 1);

		pWind->DrawRectangle(P1.x-9, P1.y-9, P2.x+9, P2.y+9, styleRect);
	}
}



void GUI::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriaGfxInfo) const
{
	color DrawingClr;
	if (TriaGfxInfo.isSelected)		 // shape is selected
		DrawingClr = HighlightColor; // shape should be drawn highlighted
	else
		DrawingClr = TriaGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriaGfxInfo.BorderWdth); // Set Drawing color & width

	drawstyle style;
	if (TriaGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriaGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
	if (TriaGfxInfo.isHidden == true) {
		drawstyle styleTriangle;
		styleTriangle = FILLED;
		int arrayX[3] = { P1.x, P2.x, P3.x };
		int arrayY[3] = { P1.y, P2.y, P3.y };
		int max_X = arrayX[0];
		int max_Y = arrayY[0];
		int min_X = arrayX[0];
		int min_Y = arrayY[0];
		for (int i = 0; i < 3; i++) {
			if (arrayX[i] > max_X) {
				max_X = arrayX[i];
			}
			if (arrayY[i] > max_Y) {
				max_Y = arrayY[i];
			}
			if (arrayX[i] < min_X) {
				min_X = arrayX[i];
			}
			if (arrayY[i] < min_Y) {
				min_Y = arrayY[i];
			}
		}
		pWind->SetBrush(GREEN);
		pWind->SetPen(GREEN, 1);
		pWind->DrawRectangle(max_X+5, max_Y+5, min_X-2, min_Y-2, styleTriangle);
	}
}

void GUI::DrawCircle(Point P1, Point P2, GfxInfo CirclGfxInfo) const
{
	color DrawingClr;
	if (CirclGfxInfo.isSelected)	 // shape is selected
		DrawingClr = HighlightColor; // shape should be drawn highlighted
	else
		DrawingClr = CirclGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CirclGfxInfo.BorderWdth); // Set Drawing color & width

	drawstyle style;
	if (CirclGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CirclGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int radius = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));

	pWind->DrawCircle(P1.x, P1.y, radius, style);
	
	if (CirclGfxInfo.isHidden == true) {
		drawstyle styleCircle;
		styleCircle = FILLED;
		Point cr1, cr2;
		cr1.x = P1.x - radius + 1;
		cr1.y = P1.y - radius;
		cr2.x = P1.x + radius + 9;
		cr2.y = P1.y + radius + 9;

		pWind->SetBrush(GREEN);
		pWind->SetPen(GREEN, 1);
		pWind->DrawRectangle(cr1.x, cr1.y, cr2.x, cr2.y, styleCircle);
	}
}

void GUI::DrawOval(Point P1, Point P2, GfxInfo OvalGfxInfo) const
{
	color DrawingClr;
	if (OvalGfxInfo.isSelected)		 // shape is selected
		DrawingClr = HighlightColor; // shape should be drawn highlighted
	else
		DrawingClr = OvalGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, OvalGfxInfo.BorderWdth); // Set Drawing color & width

	drawstyle style;
	if (OvalGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(OvalGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);

	if (OvalGfxInfo.isHidden == true) {
		drawstyle styleOval;
		styleOval = FILLED;
		Point cr1, cr2;
		cr1.x = min(P1.x,P2.x);
		cr1.y = min(P1.y, P2.y);
		cr2.x = max(P1.x, P2.x);
		cr2.y = max(P1.y, P2.y);

		pWind->SetBrush(GREEN);
		pWind->SetPen(GREEN, 1);
		pWind->DrawRectangle(cr1.x, cr1.y, cr2.x, cr2.y, styleOval);
	}
}

void GUI::DrawSquare(Point P1, Point P2, GfxInfo SquareGfxInfo) const {
	color DrawingClr;
	
	if (SquareGfxInfo.isSelected)
		
		DrawingClr = HighlightColor;
	else
		
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, SquareGfxInfo.BorderWdth);

	drawstyle style;
	
	if (SquareGfxInfo.isFilled)
	{	
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else 
	{
		style = FRAME;
	}

	int diffx = P1.x - P2.x;						//get difference between X coordinates
	int diffy = P1.y - P2.y;						//get difference between Y coordinates
	Point P3;
	P3.x = P1.x + diffy;
	P3.y = P1.y - diffx;
	Point P4;
	P4.x = P2.x + diffy;						//add differences of y to x to get p4
	P4.y = P2.y - diffx;

	int xPoints[] = {P1.x,P3.x,P4.x,P2.x};
	int yPoints[] = {P1.y,P3.y,P4.y,P2.y};
	int max_X = xPoints[0];
	int max_Y = yPoints[0];
	int min_X = xPoints[0];
	int min_Y = yPoints[0];

	pWind->DrawPolygon(xPoints, yPoints, 4, style);
	if (SquareGfxInfo.isHidden == true) {
		drawstyle styleSquare;
		styleSquare = FILLED;
		for (int i = 0; i < 3; i++) {
			if (xPoints[i] > max_X) {
				max_X = xPoints[i];
			}
			if (yPoints[i] > max_Y) {
				max_Y = yPoints[i];
			}
			if (xPoints[i] < min_X) {
				min_X = xPoints[i];
			}
			if (yPoints[i] < min_Y) {
				min_Y = yPoints[i];
			}
		}

		pWind->SetBrush(GREEN);
		pWind->SetPen(GREEN, 5);
		pWind->DrawRectangle(max_X + 90, max_Y+90, min_X-5, min_Y-5, styleSquare);
	}
}

void GUI::DrawRegularPolygon(std::vector<Point> regularPolygonPoints, double numOfVertices, GfxInfo RegularPolygonGfxInfo) const
{
	color DrawingClr;
	if (RegularPolygonGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RegularPolygonGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RegularPolygonGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RegularPolygonGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RegularPolygonGfxInfo.FillClr);
	}
	else
		style = FRAME;
		std::vector<int> xPointsV;
		std::vector<int> yPointsV;
		for (int i = 0; i <int(numOfVertices); i++)
		{
			int x = regularPolygonPoints[i].x;
			int y = regularPolygonPoints[i].y;
			xPointsV.push_back(regularPolygonPoints[i].x);
			yPointsV.push_back(regularPolygonPoints[i].y);
		}
		int* xPoints = &xPointsV[0];
		int* yPoints = &yPointsV[0];
		pWind->DrawPolygon(xPoints, yPoints, int(numOfVertices), style);


		if (RegularPolygonGfxInfo.isHidden == true) {
			drawstyle styleRegularpolygon;
			styleRegularpolygon = FILLED;

			int max_X = xPointsV[0];
			int max_Y = yPointsV[0];
			int min_X = xPointsV[0];
			int min_Y = yPointsV[0];

			for (int i = 0; i < numOfVertices; i++)
			{
				if (xPointsV[i] > max_X) {
					max_X = xPointsV[i];
				}
				if (yPointsV[i] > max_Y) {
					max_Y = yPointsV[i];
				}
				if (xPointsV[i] < min_X) {
					min_X = xPointsV[i];
				}
				if (yPointsV[i] < min_Y) {
					min_Y = yPointsV[i];
				}
			}

			pWind->SetBrush(GREEN);
			pWind->SetPen(GREEN, 1);
			pWind->DrawRectangle(max_X + 3, max_Y + 3, min_X-3, min_Y-3, styleRegularpolygon);
		}
}

void GUI::DrawLine(Point P1, Point P2, GfxInfo LineGfcInfo) const
{
	color DrawingClr;
	if (LineGfcInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = LineGfcInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfcInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (LineGfcInfo.isFilled)
	{
		style = FRAME;
	}
	else
		style = FRAME;

  pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

  if (LineGfcInfo.isHidden == true) {
	  drawstyle styleLine;
	  styleLine = FILLED;
	  Point cr1, cr2;
	  cr1.x = min(P1.x, P2.x)-2;
	  cr1.y = min(P1.y, P2.y)-2;
	  cr2.x = max(P1.x, P2.x)+2;
	  cr2.y = max(P1.y, P2.y)+2;

	  pWind->SetBrush(GREEN);
	  pWind->SetPen(GREEN, 1);
	  pWind->DrawRectangle(cr1.x, cr1.y, cr2.x, cr2.y, styleLine);
  }
  }


  
void GUI::DrawIrrPolygon(vector<Point> allPoints, int verticies, GfxInfo IrrPolGfxInfo) const
{
	color DrawingClr;
	if (IrrPolGfxInfo.isSelected)	 // shape is selected
		DrawingClr = HighlightColor; // shape should be drawn highlighted
	else
		DrawingClr = IrrPolGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, IrrPolGfxInfo.BorderWdth); // Set Drawing color & width

	drawstyle style;
	if (IrrPolGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(IrrPolGfxInfo.FillClr);
	}
	else
		style = FRAME;
	vector<int> xPointsV;
	vector<int> yPointsV;
	for (int i = 0; i < verticies; i++)
	{
		xPointsV.push_back(allPoints[i].x);
		yPointsV.push_back(allPoints[i].y);
	}
	int *xPoints = &xPointsV[0];
	int *yPoints = &yPointsV[0];
	pWind->DrawPolygon(xPoints, yPoints, verticies, style);

	if (IrrPolGfxInfo.isHidden == true) {
		drawstyle styleIrregular;
		styleIrregular = FILLED;
		
		int max_X = xPointsV[0];
		int max_Y = yPointsV[0];
		int min_X = xPointsV[0];
		int min_Y = yPointsV[0];

		for (int i = 0; i < verticies; i++)
		{
			if (xPointsV[i] > max_X) {
				max_X = xPointsV[i];
			}
			if (yPointsV[i] > max_Y) {
				max_Y = yPointsV[i];
			}
			if (xPointsV[i] < min_X) {
				min_X = xPointsV[i];
			}
			if (yPointsV[i] < min_Y) {
				min_Y = yPointsV[i];
			}
		}

		pWind->SetBrush(GREEN);
		pWind->SetPen(GREEN, 1);
		pWind->DrawRectangle(max_X+3, max_Y+3, min_X-3, min_Y-3, styleIrregular);
	}

}
void GUI::DrawImage(image I,Point P1, double width, double height)
{
	pWind->DrawImage(I, P1.x, P1.y, width, height);
}

GUI::~GUI()
{
	delete pWind;
}

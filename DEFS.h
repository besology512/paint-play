#ifndef DEFS_H
#define DEFS_H


//This file contais some global constants and definitions to be used in the project.
enum operationType //The operations supported (you can add more if needed)
{
	UNDO,
	REDO,
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	DRAW_OVAL,		//Draw Oval
	DRAW_SQUARE,	//Draw Square
	DRAW_IRR_POLYGON, //Draw Irregular Polygon
	DRAW_REGULAR_POLYGON,	//Draw Regular Polygon
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BORDER_CLR,	//Change the border color
	CHNG_BORDER_WIDTH,  //Change the border width
	PICK_COLOR,
	COPY,
	PASTE,
	CUT,
	DEL,			//Delete a shape(s)
	MOVE,			//Move a shape(s)
	ZOOM_IN,		//zoom the shape in
	ZOOM_OUT,		//zoom the shape out
	RESIZE,			//Resize a shape(s)
	ROTATE,			//Rotate a shape(s)
	SEND_BACK,		//Send a shape to the back of all shapes
	BRNG_FRNT,		//Bring a shape to the front of all shapes
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	STICK_IMAGE,
	SCRAMBLE,
	DRAG,			//Drag a single shape
	START,			//start the play mode
	RESTART,		//restart the play mode
	HIDE,			// Hide the shape in play mode
	UNHIDE,			// unhide the shape in play mode
	SWITCH,			//switch the two modes
	DUPLICATE_GRAPH,		//duplicate the graph
	EXIT,			//Exit the application
	

	DRAWING_AREA,			//A click on the drawing area
	STATUS,					//A click on the status bar
	EMPTY,					//A click on empty place in the toolbar

	PLAYING_AREA,
	TO_DRAW,				//Switch interface to Draw mode
	TO_PLAY					//Switch interface to Play mode

	///TODO: Add more operation types (if needed)
};

#endif
#pragma once
#include "..\defs.h"
#include "..\GUI\GUI.h"
#include <cstdlib>
#include <vector>

#include"../CMUgraphicsLib/colors.h"
#include<stack>
//Base class for all shapes
class shape
{
protected:
	int ID;		//Each shape has an ID
	GfxInfo ShpGfxInfo;	//shape graphis info
	GUI* pUI;
	//Point arrayPoints[10];
	
	
	
	/// Add more parameters if needed.

public:
	stack<color> prevFillClrs; //all fill colors for all shapes types
	stack<color> undoFillCLrs;
	stack<color> prevBorderClrs;// all border color for all shapes types
	stack<color> undoBorderClrs;
	stack<int> undoBorderWidth;
	stack<int> prevBorderWidth; // all border widths for all shapes types
	shape(GfxInfo shapeGfxInfo);
	virtual ~shape() {}
	void SetSelected(bool s);	//select/unselect the shape
	bool IsSelected() const;	//check whether fig is selected
	bool isSticked = false;
	virtual bool inShape(int, int) const = 0;		 //check whether a point in the shape or not
	virtual string shapeInfo() = 0;						//give some info about the shape


	virtual void Draw(GUI* pUI) const  = 0 ;		//Draw the shape
	void setisHidden(bool h);						//use it to make the flag of hidden is true/false
	//bool getisHidden();
	void ChngDrawClr(color Dclr);	//changes the shape's drawing color
	void ChngFillClr(color Fclr);	//changes the shape's filling color
	void setIsfilled(bool);
	void ChngBorderWidth(int);
	virtual double getWidth() = 0;
	virtual double getHeight() = 0;
	virtual void resize(float factor) = 0;
	virtual void Rotate() = 0;
	virtual shape* clone() = 0;
	virtual void Move(int x,int y) = 0;		//Move the shape
	virtual Point getUpperLeftPoint() = 0;
	virtual Point getCenter() = 0;
	

	virtual void zoom(double scale, int x, int y) = 0;		//Zoom the shape(s) in
	virtual void stickImage(image, GUI* pUI) = 0;
	virtual int getDuplicateID() = 0; 
	virtual void setDuplicateID(int) = 0;





	///The following functions should be supported by the shape class
	///It should be overridden by each inherited shape

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the shape
	//virtual void Resize() = 0;	//Resize the shape
	//virtual void Move() = 0;		//Move the shape

	virtual void SAVE(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	virtual void LOAD(ifstream &Infile) = 0;	//Load the shape parameters to the file
	virtual void SCRAMBLE(Point randomPoint) = 0;				//scramble function according each shape 

	//virtual void PrintInfo(Output* pOut) = 0;	//print all shape info on the status bar
};


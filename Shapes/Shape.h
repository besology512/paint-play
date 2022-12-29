#pragma once
#include "..\defs.h"
#include "..\GUI\GUI.h"


//Base class for all shapes
class shape
{
protected:
	int ID;		//Each shape has an ID
	GfxInfo ShpGfxInfo;	//shape graphis info
	
	
	/// Add more parameters if needed.

public:
	shape(GfxInfo shapeGfxInfo);
	virtual ~shape() {}
	void SetSelected(bool s);	//select/unselect the shape
	bool IsSelected() const;	//check whether fig is selected
	bool isSticked = false;
	virtual bool inShape(int, int) const = 0;		 //check whether a point in the shape or not
	virtual string shapeInfo() = 0;						//give some info about the shape


	virtual void Draw(GUI* pUI) const  = 0 ;		//Draw the shape
	
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
	virtual void stickImage(image, GUI* pUI) = 0;



	///The following functions should be supported by the shape class
	///It should be overridden by each inherited shape

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the shape
	//virtual void Resize() = 0;	//Resize the shape
	//virtual void Move() = 0;		//Move the shape

	virtual void SAVE(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	virtual void LOAD(ifstream &Infile) = 0;	//Load the shape parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all shape info on the status bar
};


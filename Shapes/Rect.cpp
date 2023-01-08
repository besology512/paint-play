#include "Rect.h"
#include <iostream>
using namespace std;

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3.x = Corner2.x;
	Corner3.y = Corner1.y;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}

void Rect::SCRAMBLE(Point randomPoint)
{	
	int x = randomPoint.x;
	int y = randomPoint.y;
	Move(x, y);
	int area = area = sqrt(pow(Corner1.x - Corner2.x, 2)) * sqrt(pow(Corner1.y - Corner2.y, 2));
	if (area > 60000)
	{
		resize(0.5);
	}
}



void Rect::SAVE(ofstream& OutFile)
{
	ID = 3;
	OutFile << "Rect " << " "
		<< ID << " "
		<< Corner1.x << " "
		<< Corner1.y << " "
		<< Corner2.x << " "
		<< Corner2.y << " "
		<< (int)ShpGfxInfo.DrawClr.ucBlue << " "
		<< (int)ShpGfxInfo.DrawClr.ucGreen << " "
		<< (int)ShpGfxInfo.DrawClr.ucRed << " ";
	if (ShpGfxInfo.isFilled)
	{
		OutFile << "FILL" << " "
			<< (int)ShpGfxInfo.FillClr.ucBlue << " "
			<< (int)ShpGfxInfo.FillClr.ucGreen << " "
			<< (int)ShpGfxInfo.FillClr.ucRed << " ";
	}
	else
	{
		OutFile << "NO_FILL ";
	}
	OutFile << ShpGfxInfo.BorderWdth << "\n";//color ; // Put data into file
}
void Rect::LOAD(ifstream& Infile)
{
	string isFilled;
	int ID;
	int x, y, z;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> x >> y >> z >> isFilled;
	ShpGfxInfo.DrawClr.ucBlue = x;
	ShpGfxInfo.DrawClr.ucGreen = y;
	ShpGfxInfo.DrawClr.ucRed = z;
	if (isFilled == "FILL")
	{
		Infile >> x >> y >> z;
		ShpGfxInfo.FillClr.ucBlue = x;
		ShpGfxInfo.FillClr.ucGreen = y;
		ShpGfxInfo.FillClr.ucRed = z;
	}
	else
	{
		ShpGfxInfo.isFilled = 0;
	}
	Infile >> ShpGfxInfo.BorderWdth;
}



bool Rect::inShape(int x, int y) const
{

	// Ordering x and y from the corners
	int firstX;
	int secondX;
	int firstY;
	int secondY;

	if (Corner1.x < Corner2.x) { firstX = Corner1.x; secondX = Corner2.x;}
	else{ firstX = Corner2.x; secondX = Corner1.x; }
	if (Corner1.y < Corner2.y) { firstY = Corner1.y; secondY = Corner2.y;}
	else{ firstY = Corner2.y; secondY = Corner1.y; }


	if (((x >= firstX) && (x <= secondX)) && ((y >= firstY) && (y <= secondY)))
	{
		return true;
	}
	else return false;
}

string Rect::shapeInfo()
{
	int area;
	Point center;
	string msg;

	area = sqrt(pow(Corner1.x - Corner2.x, 2)) * sqrt(pow(Corner1.y - Corner2.y, 2));
	center.x = sqrt(pow(Corner1.x - Corner2.x,2)) / 2;
	center.y = sqrt(pow(Corner1.y - Corner2.y, 2)) / 2;

	msg = "The Rectangle Area is " + to_string(area) + " The center is at (" + to_string(center.x) + "," + to_string(center.y) + ")";
	return msg;
}

double Rect::getWidth()
{
	Point Corner3;
	Corner3.x = Corner2.x;
	Corner3.y = Corner1.y;
	double width = sqrt(pow(Corner3.x - Corner1.x, 2) + pow(Corner3.y - Corner1.y, 2))-10;

	return width;
}

double Rect::getHeight()
{
	Point Corner3;
	Corner3.x = Corner2.x;
	Corner3.y = Corner1.y;
	double height = sqrt(pow(Corner3.x - Corner2.x, 2) + pow(Corner3.y - Corner2.y, 2))-10;

	return height;
}

void Rect::resize(float factor) {
		if (factor == 0.5)
		{
			Corner2.x = (Corner1.x + Corner2.x) / 2;
			Corner2.y = (Corner1.y + Corner2.y) / 2;
		}
		if (factor == 0.25) {
			Corner2.x = (Corner1.x + Corner2.x) / 2;
			Corner2.y = (Corner1.y + Corner2.y) / 2;
			//then again
			Corner2.x = (Corner1.x + Corner2.x) / 2;
			Corner2.y = (Corner1.y + Corner2.y) / 2;
		}
		if (factor == 2) {
			Corner2.x = 2 * Corner2.x - Corner1.x;
			Corner2.y = 2 * Corner2.y - Corner1.y;
		}
		if (factor == 4) {
			Corner2.x = 2 * Corner2.x - Corner1.x;
			Corner2.y = 2 * Corner2.y - Corner1.y;
			//then again
			Corner2.x = 2 * Corner2.x - Corner1.x;
			Corner2.y = 2 * Corner2.y - Corner1.y;
		}
}

void Rect::zoom(double scale, int x, int y) {

	Corner1.x = (Corner1.x * scale) - (scale * x) + x;
	Corner1.y = (Corner1.y * scale) - (scale * y) + y;
	Corner2.x = (Corner2.x * scale) - (scale * x) + x;
	Corner2.y = (Corner2.y * scale) - (scale * y) + y;

}



Point Rect::getUpperLeftPoint()
{
	Point upperLeftPoint;
	//Point center;
	//Point Corner3;
	//Corner3.x = Corner2.x;
	//Corner3.y = Corner1.y;
	//center.x = sqrt(pow(Corner1.x - Corner2.x, 2)) / 2;
	//center.y = sqrt(pow(Corner1.y - Corner2.y, 2)) / 2;
	//double y = sqrt(pow(Corner2.x - Corner3.x, 2) + pow(Corner2.y - Corner3.y, 2));
	//double x = sqrt(pow(Corner1.x - Corner3.x, 2) + pow(Corner1.y - Corner3.y, 2));
	//upperLeftPoint.x = center.x + (x/2);
	//upperLeftPoint.y = center.y + (y/2);

	upperLeftPoint.x = Corner1.x + 5;
	upperLeftPoint.y = Corner1.y + 5;
	return upperLeftPoint;
}

void Rect::stickImage(image I, GUI* pUI)
{
	pUI->DrawImage(I, getUpperLeftPoint(), getWidth(), getHeight());


}


void Rect::Rotate() {
	Point Center;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
	int tempP1X = Corner1.x;
	int tempP1Y = Corner1.y;
	int tempP2X = Corner2.x;
	int tempP2Y = Corner2.y;
	Corner1.x = -tempP1Y + Center.y + Center.x;
	Corner1.y = tempP1X - Center.x + Center.y;
	Corner2.x = -tempP2Y + Center.y + Center.x;
	Corner2.y = tempP2X - Center.x + Center.y;
}

shape* Rect::clone(){
	shape* pCloned = new Rect(*this);
	return pCloned;
}

void Rect::Move(int x,int y){
	int diffX = x - Corner1.x;
	int diffY = y - Corner1.y;
	Corner1.x = x;	Corner1.y = y;
	Corner2.x += diffX;	Corner2.y += diffY;
}

int Rect::getDuplicateID()
{
	return duplicateID;
}
void Rect::setDuplicateID(int i)
{
	duplicateID = i;
}

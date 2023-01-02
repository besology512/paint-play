
#include "Line.h"
#include<iostream>
Line::Line(Point p1, Point p2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	point1 = p1;
	point2 = p2;
}

Line::~Line()
{
}

void Line::Draw(GUI* pUI) const
{
	pUI->DrawLine(point1, point2, ShpGfxInfo);


}

void Line::SAVE(ofstream& OutFile)
{
	ID = 1;
	OutFile << "Line " << " "
		<< ID << " "
		<< point1.x << " "
		<< point1.y << " "
		<< point2.x << " "
		<< point2.y << " "
		<< (int)ShpGfxInfo.DrawClr.ucBlue << " "
		<< (int)ShpGfxInfo.DrawClr.ucGreen << " "
		<< (int)ShpGfxInfo.DrawClr.ucRed << " "
		<< ShpGfxInfo.BorderWdth << "\n";

}
	
bool Line::inShape(int x, int y) const
{
	double d = sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2)); //The distance between the two vertices of the line
	double d1 = sqrt(pow(point1.x - x, 2) + pow(point1.y - y, 2)); //The distance between one vertix and the point
	double d2 = sqrt(pow(x - point2.x, 2) + pow(y - point2.y, 2)); //The distance between the another vertix and the point

	if ((d*1.0005)  >= d1 + d2) // Because of the decimal errors I multiplied the length of the line by small factor
		return true;
	else
		return false;

}

string Line::shapeInfo()
{
	double slope;
	int length;
	string msg;

	slope = (point2.y - point1.y) / (point2.x - point1.x);
	length = sqrt(pow(point1.y - point2.y, 2) + pow(point1.x - point2.x, 2));
		

	msg = "The line slope is " + to_string(int(slope)) + " The line length is " + to_string(length);
	return msg;
}

void Line::LOAD(ifstream& Infile)
{
	int x, y, z;
	Infile >> ID >> point1.x >> point1.y >> point2.x >> point2.y >> x >> y >> z >> ShpGfxInfo.BorderWdth;
	ShpGfxInfo.DrawClr.ucBlue = x;
	ShpGfxInfo.DrawClr.ucGreen = y;
	ShpGfxInfo.DrawClr.ucRed = z;

}

double Line::getWidth()
{
	return 0.0;
}

double Line::getHeight()
{
	return 0.0;
}

void Line::resize(float factor) {
	if (factor == 0.5)
	{
		point2.x = (point1.x + point2.x) / 2;
		point2.y = (point1.y + point2.y) / 2;
	}
	if (factor == 0.25) {
		point2.x = (point1.x + point2.x) / 2;
		point2.y = (point1.y + point2.y) / 2;
		//then again
		point2.x = (point1.x + point2.x) / 2;
		point2.y = (point1.y + point2.y) / 2;
	}
	if (factor == 2) {
		point2.x = 2 * point2.x - point1.x;
		point2.y = 2 * point2.y - point1.y;
	}	
	if (factor == 4) {
		point2.x = 2 * point2.x - point1.x;
		point2.y = 2 * point2.y - point1.y;
		//then again
		point2.x = 2 * point2.x - point1.x;
		point2.y = 2 * point2.y - point1.y;
	}
}

void Line::zoom(double scale, int x, int y) {

	point1.x = (point1.x * scale) - (scale * x) + x;
	point1.y = (point1.y * scale) - (scale * y) + y;
	point2.x = (point2.x * scale) - (scale * x) + x;
	point2.y = (point2.y * scale) - (scale * y) + y;
}

void Line:: Rotate() {
	Point Center;
	Center.x = (point1.x + point2.x) / 2;
	Center.y = (point1.y + point2.y) / 2;
	int tempP1X = point1.x;
	int tempP1Y = point1.y;
	int tempP2X = point2.x;
	int tempP2Y = point2.y;
	point1.x = -tempP1Y + Center.y + Center.x;
	point1.y = tempP1X - Center.x + Center.y;
	point2.x = -tempP2Y + Center.y + Center.x;
	point2.y = tempP2X - Center.x + Center.y;
}

shape* Line::clone(){
	shape* pCloned = new Line(*this);
	return pCloned;
}

void Line::Move(int x,int y){
	int diffX = x - point1.x;
	int diffY = y - point1.y;
	point1.x = x;	point1.y = y;
	point2.x += diffX;	point2.y += diffY;
}
Point Line::getUpperLeftPoint()
{
	return Point();
}

void Line::stickImage(image, GUI* pUI)
{
}

int Line::getDuplicateID()
{
	return duplicateID;
}
void Line::setDuplicateID(int i)
{
	duplicateID = i;
}


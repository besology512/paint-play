#include "Line.h"

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

	OutFile << "Line\n"
		<< "p1 (" << point1.x << " , " << point1.y << ")\n"
		"p2 (" << point2.x << " , " << point2.y << ")\n"
		<< "BorderWdth : " << ShpGfxInfo.BorderWdth << "\n"
		<< "isFilled : " << ShpGfxInfo.isFilled << "\n"
		<< "isSelected : " << ShpGfxInfo.isSelected << "\n"
		<< "DrawClr : (" << ShpGfxInfo.DrawClr.ucBlue << " , " << ShpGfxInfo.DrawClr.ucGreen << " , " << ShpGfxInfo.DrawClr.ucRed << ")\n"
		<< "FillClr : (" << ShpGfxInfo.FillClr.ucBlue << " , " << ShpGfxInfo.FillClr.ucGreen << " , " << ShpGfxInfo.FillClr.ucRed << ")\n\n";//color ; // Put data into file


	
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
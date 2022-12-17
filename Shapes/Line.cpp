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
}

double Line::getWidth()
{
	return 0.0;
}

double Line::getHeight()
{
	return 0.0;
}


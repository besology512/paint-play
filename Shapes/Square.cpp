#include "Square.h"

Square::Square(Point P1, Point P2, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo) {
	corner1 = P1;
	corner2 = P2;
}

Square::~Square()
{}

void Square::Draw(GUI* pUI) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pUI->DrawSquare(corner1, corner2, ShpGfxInfo);
}

double Square::getTriangleArea(int x1, int y1, int x2, int y2, int x3, int y3) const
{
	double area = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
	return area;
}

void Square::SAVE(ofstream& OutFile)
{
	ID = 2;
	OutFile << "Square " << " "
		<< ID << " "
		<< corner1.x << " "
		<< corner1.y << " "
		<< corner2.x << " "
		<< corner2.y << " "
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

void Square::LOAD(ifstream& Infile){}

bool Square::inShape(int x, int y) const 
{
	int diffx = corner1.x - corner2.x;				//get difference between X coordinates
	int diffy = corner1.y - corner2.y;
	Point P3;
	P3.x = corner1.x + diffy;
	P3.y = corner1.y - diffx;
	Point P4;
	P4.x = corner2.x + diffy;						//add differences of y to x to get p4
	P4.y = corner2.y - diffx;

	double T1 = getTriangleArea(corner1.x, corner1.y, x, y, corner2.x, corner2.y);
	double T2 = getTriangleArea(corner2.x, corner2.y, x, y, P3.x, P3.y);
	double T3 = getTriangleArea(P3.x, P3.y, x, y, P4.x, P4.y);
	double T4 = getTriangleArea(P4.x, P4.y, x, y, corner1.x, corner1.y);

	double sArea = pow(sqrt(pow(corner1.x - corner2.x, 2) + pow(corner1.y - corner2.y, 2)), 2);

	if (sArea >= T1 + T2 + T3 + T4)
		return true;
	else
		return false;

}

string Square::shapeInfo() 
{ 
	int area;
	Point center;
	string msg;

	area = sqrt(pow(corner1.x - corner2.x, 2)) * sqrt(pow(corner1.y - corner2.y, 2));
	center.x = sqrt(pow(corner1.x - corner2.x, 2)) / 2;
	center.y = sqrt(pow(corner1.y - corner2.y, 2)) / 2;

	msg = "The Square Area is " + to_string(area) + " The center is at (" + to_string(center.x) + "," + to_string(center.y) + ")";
	return msg;
}

double Square::getWidth()
{
	double width = sqrt((pow(corner1.x - corner2.x, 2)) + pow(corner1.y - corner2.y, 2))-10;
	return width;
}

double Square::getHeight()
{
	double height = sqrt((pow(corner1.x - corner2.x, 2)) + pow(corner1.y - corner2.y, 2))-10;
	return height;
}

void Square::resize(float factor) {
	if (factor == 0.5)
	{
		corner2.x = (corner1.x + corner2.x) / 2;
		corner2.y = (corner1.y + corner2.y) / 2;
	}
	if (factor == 0.25) {
		corner2.x = (corner1.x + corner2.x) / 2;
		corner2.y = (corner1.y + corner2.y) / 2;
		//then again
		corner2.x = (corner1.x + corner2.x) / 2;
		corner2.y = (corner1.y + corner2.y) / 2;
	}
	if (factor == 2) {
		corner2.x = 2 * corner2.x - corner1.x;
		corner2.y = 2 * corner2.y - corner1.y;
	}
	if (factor == 4) {
		corner2.x = 2 * corner2.x - corner1.x;
		corner2.y = 2 * corner2.y - corner1.y;
		//then again
		corner2.x = 2 * corner2.x - corner1.x;
		corner2.y = 2 * corner2.y - corner1.y;
	}
}

void Square::Rotate() {
	int diffx = corner1.x - corner2.x;
	int diffy = corner1.y - corner2.y;
	Point P3;
	P3.x = (corner1.x + corner2.x) / 2;
	P3.y = (corner1.y+corner2.y)/2;
	P3.y = corner2.y - diffx;
	Point Center;
	Center.x = P3.x;
	Center.y = P3.y;
	int tempP1X = corner1.x;
	int tempP1Y = corner1.y;
	int tempP2X = corner2.x;
	int tempP2Y = corner2.y;
	corner1.x = -tempP1Y + Center.y + Center.x;
	corner1.y = tempP1X - Center.x + Center.y;
	corner2.x = -tempP2Y + Center.y + Center.x;
	corner2.y = tempP2X - Center.x + Center.y;
}
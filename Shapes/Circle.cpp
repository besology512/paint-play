#include ".//Circle.h"

Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = P1;
	PointOnCircle = P2;
}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::Draw Triangle to draw a Triangle on the screen	
	pUI->DrawCircle(Center, PointOnCircle, ShpGfxInfo);
}


void Circle::SAVE(ofstream& OutFile)
{
	OutFile << "Circle\n"
		<< "Center (" << Center.x << " , " << Center.y << ")\n"
		"PointOnCircle (" << PointOnCircle.x << " , " << PointOnCircle.y << ")\n"
		<< "BorderWdth : " << ShpGfxInfo.BorderWdth << "\n"
		<< "isFilled : " << ShpGfxInfo.isFilled << "\n"
		<< "isSelected : " << ShpGfxInfo.isSelected << "\n"
		<< "DrawClr : (" << ShpGfxInfo.DrawClr.ucBlue << " , " << ShpGfxInfo.DrawClr.ucGreen << " , " << ShpGfxInfo.DrawClr.ucRed << ")\n"
		<< "FillClr : (" << ShpGfxInfo.FillClr.ucBlue << " , " << ShpGfxInfo.FillClr.ucGreen << " , " << ShpGfxInfo.FillClr.ucRed << ")\n\n";//color ; // Put data into file

}

bool Circle::inShape(int x, int y) const
{
	double radius = sqrt(pow(Center.x - PointOnCircle.x,2) + pow(Center.y - PointOnCircle.y,2));
	double d = sqrt(pow(x - Center.x, 2) + pow(y - Center.y, 2));	 //distance formula for the circle

	if (d <= radius)
		return true;
	else
		return false;
}

string Circle::shapeInfo()
{
	double radius = sqrt(pow(Center.x - PointOnCircle.x, 2) + pow(Center.y - PointOnCircle.y, 2));
	int area = 3.14159 * radius * radius;
	string msg = "The Circle Area is " + to_string(area) + " The center is at (" + to_string(Center.x) + "," + to_string(Center.y) + ")";

	return msg ;
}

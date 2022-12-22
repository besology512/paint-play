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
	ID = 7;
	OutFile << "Circle " << " "
		<< ID << " "
		<< Center.x << " "
		<< Center.y << " "
		<< PointOnCircle.x << " "
		<< PointOnCircle.y << " "
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
	OutFile << ShpGfxInfo.BorderWdth << "\n";

}

void Circle::LOAD(ifstream& Infile)
{
	//Infile >> Center.x;


}

double Circle::getWidth()
{
	double width = sqrt(pow(Center.x - PointOnCircle.x, 2) + pow(Center.y - PointOnCircle.y, 2));
	return width;
	
}

double Circle::getHeight()
{
	double height = sqrt(pow(Center.x - PointOnCircle.x, 2) + pow(Center.y - PointOnCircle.y, 2));
	return height;
}

void Circle::resize(int factor){
	
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

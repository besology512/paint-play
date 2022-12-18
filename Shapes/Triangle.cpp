#include ".//Triangle.h"

Triangle::Triangle(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

Triangle::~Triangle()
{}

void Triangle::Draw(GUI* pUI) const
{
	//Call Output::Draw Triangle to draw a Triangle on the screen	
	pUI->DrawTriangle(Corner1, Corner2, Corner3,ShpGfxInfo);
}


void Triangle::SAVE(ofstream& OutFile)
{
	ID = 4;
	OutFile << "Triangle " << " "
		<< ID << " "
		<< Corner1.x << " "
		<< Corner1.y << " "
		<< Corner2.x << " "
		<< Corner2.y << " "
		<< Corner3.x << " "
		<< Corner3.y << " "
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

double Triangle::getArea(int x1, int y1, int x2, int y2, int x3, int y3) const
{
	double area = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
	return area;
}

bool Triangle::inShape(int x, int y) const
{
	// Get the area of our Triangle 
	double tArea = getArea(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	
	//Get area of other 3 triangles using the point (x,y)
	double t1Area = getArea(x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	double t2Area = getArea(Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y);
	double t3Area = getArea(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y);

	if (tArea == t1Area + t2Area + t3Area)
		return true;
	else
		return false;
}

string Triangle::shapeInfo()
{
	int area = getArea(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	string msg = "The Triangle Area is " + to_string(area);
	return  msg;
}

void Triangle::LOAD(ifstream& Infile)
{
}

double Triangle::getWidth()
{

	double midpoint = sqrt(pow(Corner1.x - Corner2.x, 2) + pow(Corner1.y - Corner2.y, 2))/2; // get half distance of side
	double width = midpoint * sqrt(3) / 2; // get side length of inscribed square 

	return width;
}

double Triangle::getHeight()
{
	double midpoint = sqrt(pow(Corner1.x - Corner2.x, 2) + pow(Corner1.y - Corner2.y, 2)) / 2; // get half distance of side
	double height = midpoint * sqrt(3) / 2; // get side length of inscribed square 
	return height;

}

Point Triangle::getUpperLeftPoint()
{
	return Point();
}


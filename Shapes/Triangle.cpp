#include ".//Triangle.h"
#include<iostream>
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

void Triangle::resize(float factor) {
	if (factor == 0.5) {
		//first line of the triangle
		Corner2.x = (Corner1.x + Corner2.x) / 2;
		Corner2.y = (Corner1.y + Corner2.y) / 2;
		//second line of the triangle
		Corner3.x = (Corner1.x + Corner3.x) / 2;
		Corner3.y = (Corner1.y + Corner3.y) / 2;
	}
	if (factor == 0.25) {
		//first line of the triangle
		Corner2.x = (Corner1.x + Corner2.x) / 2;
		Corner2.y = (Corner1.y + Corner2.y) / 2;
		//second line of the triangle
		Corner3.x = (Corner1.x + Corner3.x) / 2;
		Corner3.y = (Corner1.y + Corner3.y) / 2;
		//and then again
		//first line of the triangle
		Corner2.x = (Corner1.x + Corner2.x) / 2;
		Corner2.y = (Corner1.y + Corner2.y) / 2;
		//second line of the triangle
		Corner3.x = (Corner1.x + Corner3.x) / 2;
		Corner3.y = (Corner1.y + Corner3.y) / 2;
	}
	if (factor == 2) {
		Corner2.x = 2 * Corner2.x - Corner1.x;
		Corner2.y = 2 * Corner2.y - Corner1.y;
		//the second line
		Corner3.x = 2 * Corner3.x - Corner1.x;
		Corner3.y = 2 * Corner3.y - Corner1.y;
	}
	if (factor == 4) {
		Corner2.x = 2 * Corner2.x - Corner1.x;
		Corner2.y = 2 * Corner2.y - Corner1.y;
		//the second line
		Corner3.x = 2 * Corner3.x - Corner1.x;
		Corner3.y = 2 * Corner3.y - Corner1.y;
		//then do it again to both lines
		Corner2.x = 2 * Corner2.x - Corner1.x;
		Corner2.y = 2 * Corner2.y - Corner1.y;
		//the second line
		Corner3.x = 2 * Corner3.x - Corner1.x;
		Corner3.y = 2 * Corner3.y - Corner1.y;
	}
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
	int x, y, z;
	string isFilled;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y >> x >> y >> z >> isFilled;
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

void Triangle::Rotate() {
	Point Center;
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y = (Corner1.y + Corner2.y+Corner3.y) / 3;
	int tempP1X = Corner1.x;
	int tempP1Y = Corner1.y;
	int tempP2X = Corner2.x;
	int tempP2Y = Corner2.y;
	int tempP3X = Corner3.x;
	int tempP3Y = Corner3.y;
	Corner1.x = -tempP1Y + Center.y + Center.x;
	Corner1.y = tempP1X - Center.x + Center.y;
	Corner2.x = -tempP2Y + Center.y + Center.x;
	Corner2.y = tempP2X - Center.x + Center.y;
	Corner3.x = -tempP3Y + Center.y + Center.x;
	Corner3.y = tempP3X - Center.x + Center.y;
}

shape* Triangle::clone(){
	shape* pCloned = new Triangle(*this);
	return pCloned;
}

void Triangle::Move(int x,int y){
	int diffX = x - Corner1.x;
	int diffY = y - Corner1.y;
	Corner1.x = x;	Corner1.y = y;
	Corner2.x += diffX;	Corner2.y += diffY;
	Corner3.x += diffX;	Corner3.y += diffY;
}
Point Triangle::getUpperLeftPoint(){return Point();}


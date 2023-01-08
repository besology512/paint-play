#include"RegularPolygon.h"

RegularPolygon::RegularPolygon(Point c, double v, double r, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	center = c;
	numOfVertices = v;
	radius = r;
}

RegularPolygon::~RegularPolygon(){}

void RegularPolygon::Draw(GUI* pUI) const
{
	//Call Output::Draw Triangle to draw a Triangle on the screen	
	pUI->DrawRegularPolygon(regularPolygonPoints, numOfVertices,ShpGfxInfo);
}


void RegularPolygon::SAVE(ofstream& OutFile)
{
	ID = 5;
	OutFile << "RegularPolygon " << " "
		<< ID << " "
		<< center.x << " "
		<< center.y << " "
		<< numOfVertices << " "
		<< radius << " "
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
bool RegularPolygon::inShape(int x, int y) const
{

	//// Creating arrays containing the x,y coordinates of the polygon vertices
	std::vector<int> xPointsV;
	std::vector<int> yPointsV;

	const double PI = 3.141592653589;			//Defining constant PI
	double angle = (2 * PI) / numOfVertices;	//Defining the angle between two vertices

	for (int i = 0; i < int(numOfVertices); i++)
	{
		int x = center.x + radius * sin(i * angle);
		int y = center.y + radius * cos(i * angle);

		xPointsV.push_back(x);
		yPointsV.push_back(y);
	}

	int* xPoints = &xPointsV[0];
	int* yPoints = &yPointsV[0];


	int i, j, c = 0;
	for (i = 0, j = numOfVertices - 1; i < numOfVertices; j = i++) 
	{
		if (((yPoints[i] > y) != (yPoints[j] > y)) && (x < (xPoints[j] - xPoints[i]) * (y - yPoints[i]) / (yPoints[j] - yPoints[i]) + xPoints[i]))
			c = !c;
	}

	if (c)
		return true;
	else
		return false;
}

string RegularPolygon::shapeInfo()
{
	string msg = "The number of vertices is " + to_string(int(numOfVertices)) + " The center is at (" + to_string(center.x) + "," + to_string(center.y) + ")";
	return  msg;
}

void RegularPolygon::LOAD(ifstream& Infile)
{
	string isFilled;
	int x, y, z;
	Infile >> ID >> center.x >> center.y >> numOfVertices >> radius >> x >> y >> z >> isFilled;
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

double RegularPolygon::getWidth()
{
	// [l2n]/[4tan(180/n)]
	double area = (pow(radius, 2) * numOfVertices) / (4 * (tan(3.1415926 / numOfVertices)));
	double width = sqrt(area)-30;
	return width;
}

double RegularPolygon::getHeight()
{
	double area = (pow(radius, 2) * numOfVertices) / (4 * (tan(3.1415926 / numOfVertices)));
	double height = sqrt(area)-50;
	return height;
}

void RegularPolygon::resize(float factor) {
	radius *= factor;
}

void RegularPolygon::zoom(double scale, int x, int y) {
	center.x = (center.x * scale) - (scale * x) + x;
	center.y = (center.y * scale) - (scale * y) + y;
	radius *= scale;


}
#include<iostream>
void RegularPolygon:: Rotate(){
	std::cout << "In rotate";
	for (int i = 0; i < int(numOfVertices); i++)
	{
		int tempX = regularPolygonPoints[i].x;
		int tempY = regularPolygonPoints[i].y;
		std::cout << tempX << std::endl;
		regularPolygonPoints[i].x = -tempY+ center.y + center.x;
		regularPolygonPoints[i].y = tempX - center.x + center.y;
		std::cout << regularPolygonPoints[i].x << std::endl;
	}
	//int tempP1X = corner1.x;
	//int tempP1Y = corner1.y;
	//int tempP2X = corner2.x;
	//int tempP2Y = corner2.y;
	//corner1.x = -tempP1Y + Center.y + Center.x;
	//corner1.y = tempP1X - Center.x + Center.y;
	//corner2.x = -tempP2Y + Center.y + Center.x;
	//corner2.y = tempP2X - Center.x + Center.y;
}

shape* RegularPolygon::clone(){
	shape* pCloned = new RegularPolygon(*this);
	return pCloned;
}
void RegularPolygon::Move(int x,int y){
	center.x = x;	center.y = y;
}
Point RegularPolygon::getUpperLeftPoint()
{
	Point upperLeftPoint;
	upperLeftPoint.x = center.x - radius;
	upperLeftPoint.y = center.y - radius;
	return upperLeftPoint;
}

void RegularPolygon::stickImage(image I, GUI* pUI)
{
	pUI->DrawImage(I, getUpperLeftPoint(), getWidth(), getHeight());
}

int RegularPolygon::getDuplicateID()
{
	return duplicateID;
}
void RegularPolygon::setDuplicateID(int i)
{
	duplicateID = i;
}

void RegularPolygon::SCRAMBLE(Point randomPoint)
{
	int x = randomPoint.x;
	int y = randomPoint.y;
	Move(x, y);
	int area = (pow(radius, 2) * numOfVertices) / (4 * (tan(3.1415926 / numOfVertices)));
	if (area > 60000)
	{
		resize(0.5);
		if (area > 60000) { resize(0.5); }
	}

}

void RegularPolygon::addPoint(Point p)
{
	regularPolygonPoints.push_back(p);
}
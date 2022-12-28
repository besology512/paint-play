#include ".//RegularPolygon.h"

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
	pUI->DrawRegularPolygon(center, numOfVertices, radius, ShpGfxInfo);
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

void RegularPolygon:: Rotate(){
	//create the points again
	//Point Center;
	//Center.x = (P4.x + corner1.x) / 2;
	//Center.y = (P4.y + corner1.y) / 2;
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
	return Point();
}

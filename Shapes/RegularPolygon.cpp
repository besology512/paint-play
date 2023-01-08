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
	for (int i = 0; i < regularPolygonPoints.size(); i++)
	{
		if (factor == 0.5)
		{
			regularPolygonPoints[i].x = (regularPolygonPoints[i].x + center.x) / 2;
			regularPolygonPoints[i].y = (regularPolygonPoints[i].y + center.y) / 2;
		}
		if (factor == 0.25) {
			regularPolygonPoints[i].x = (regularPolygonPoints[i].x + center.x) / 2;
			regularPolygonPoints[i].y = (regularPolygonPoints[i].y + center.y) / 2;
			//then again
			regularPolygonPoints[i].x = (regularPolygonPoints[i].x + center.x) / 2;
			regularPolygonPoints[i].y = (regularPolygonPoints[i].y + center.y) / 2;
		}
		if (factor == 2) {
			regularPolygonPoints[i].x = 2 * regularPolygonPoints[i].x - center.x;
			regularPolygonPoints[i].y = 2 * regularPolygonPoints[i].y - center.y;
		}
		if (factor == 4) {
			regularPolygonPoints[i].x = 2 * regularPolygonPoints[i].x - center.x;
			regularPolygonPoints[i].y = 2 * regularPolygonPoints[i].y - center.y;
			//then again
			regularPolygonPoints[i].x = 2 * regularPolygonPoints[i].x - center.x;
			regularPolygonPoints[i].y = 2 * regularPolygonPoints[i].y - center.y;
		}
	}
}

void RegularPolygon::zoom(double scale, int x, int y) {
	center.x = (center.x * scale) - (scale * x) + x;
	center.y = (center.y * scale) - (scale * y) + y;
	radius *= scale;


}
#include<iostream>
void RegularPolygon:: Rotate(){
	for (int i = 0; i < int(numOfVertices); i++)
	{
		int tempX = regularPolygonPoints[i].x;
		int tempY = regularPolygonPoints[i].y;
		regularPolygonPoints[i].x = -tempY+ center.y + center.x;
		regularPolygonPoints[i].y = tempX - center.x + center.y;
	}
}

shape* RegularPolygon::clone(){
	shape* pCloned = new RegularPolygon(*this);
	return pCloned;
}
void RegularPolygon::Move(int x,int y){
	int diffX = x - regularPolygonPoints[0].x;
	int diffY = y - regularPolygonPoints[0].y;
	regularPolygonPoints[0].x = x;
	regularPolygonPoints[0].y = y;
	for (int i = 1; i < regularPolygonPoints.size(); i++)
	{
		regularPolygonPoints[i].x += diffX;
		regularPolygonPoints[i].y += diffY;
	}
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

void RegularPolygon::SCRAMBLE(vector <Point> v1)
{
	int random = rand() % (10 + 1);
	Point randomPoint = v1[random];
	int x = randomPoint.x;
	int y = randomPoint.y;
	v1.erase(v1.begin() + random);
	Move(x, y);
}

void RegularPolygon::addPoint(Point p)
{
	regularPolygonPoints.push_back(p);
}

Point RegularPolygon::getCenter() {
	return center;
}
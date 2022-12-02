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
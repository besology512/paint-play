#include ".//IrrPolygon.h"

IrrPolygon::IrrPolygon(std::vector<Point> allPoints, int verticies, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	this->verticies = verticies;
	this->allPoints = allPoints;
}

IrrPolygon::~IrrPolygon()
{}

void IrrPolygon::Draw(GUI* pUI) const
{
	//Call Output::DrawIrrPolygon polygon to draw an irrigular polygon on the screen	
	pUI->DrawIrrPolygon(allPoints, verticies, ShpGfxInfo);
}


void IrrPolygon::SAVE(ofstream& OutFile)
{
	
	ID = 6;
	OutFile << "IrrPolygon " << " "
		<< ID << " "
		<< verticies << " ";
		for (unsigned i = 0; i < allPoints.size(); i++)
		{
			OutFile << allPoints[i].x << " "
					<< allPoints[i].y << " ";

		}

	OutFile << (int)ShpGfxInfo.DrawClr.ucBlue << " "
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

bool IrrPolygon::inShape(int x, int y) const
{

	int i, j, c = 0;
	for (i = 0, j = verticies - 1; i < verticies; j = i++)
	{
		if (((allPoints[i].y > y) != (allPoints[j].y > y)) && (x < (allPoints[j].x - allPoints[i].x) * (y - allPoints[i].y) / (allPoints[j].y - allPoints[i].y) + allPoints[i].x))
			c = !c;
	}

	if (c)
		return true;
	else
		return false;
}

string IrrPolygon::shapeInfo()
{
	string msg = "The number of vertices is " + to_string(verticies);
	return  msg;
}

void IrrPolygon::LOAD(ifstream& Infile)
{
}

double IrrPolygon::getWidth()
{
	return 0.0;
}

double IrrPolygon::getHeight()
{
	return 0.0;
}

void IrrPolygon::resize(float factor) {}
void IrrPolygon::Rotate(){}
shape* IrrPolygon::clone(){
	shape* pCloned = new IrrPolygon(*this);
	return pCloned;
}
void IrrPolygon::Move(int x,int y){
	int diffX = x - allPoints[0].x;
	int diffY = y - allPoints[0].y;
	for (int i = 0; i < allPoints.size(); i++)
	{
		allPoints[i].x = allPoints[i].x + diffX;
		allPoints[i].y = allPoints[i].y + diffY;
	}
	
}
Point IrrPolygon::getUpperLeftPoint(){return Point();}

void IrrPolygon::SCRAMBLE()
{
	int x = 5 + rand() % (1200 - 5 + 1);
	int y = 5 + rand() % (600 - 5 + 1);
	Move(x, y);
}


#include ".//Circle.h"

Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = P1;
	PointOnCircle = P2;
	raduis = abs(P2.x - P1.x);
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
	string isFilled;
	int x, y, z;
	Infile >> ID >> Center.x >> Center.y >> PointOnCircle.x >> PointOnCircle.y >> x >> y >> z >> isFilled;
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

void Circle::resize(float factor){
	if (factor == 0.25)
	{
		PointOnCircle.x = (PointOnCircle.x + Center.x) / 2;
		PointOnCircle.y = (PointOnCircle.y + Center.y) / 2;
		PointOnCircle.x = (PointOnCircle.x + Center.x) / 2;
		PointOnCircle.y = (PointOnCircle.y + Center.y) / 2;
	}
	if (factor  == 0.5)
	{
		PointOnCircle.x = (PointOnCircle.x + Center.x) / 2;
		PointOnCircle.y = (PointOnCircle.y + Center.y) / 2;
	}
	if (factor == 2)
	{
		PointOnCircle.x = 2 * PointOnCircle.x - Center.x;
		PointOnCircle.y = 2 * PointOnCircle.y - Center.y;
	}
	if (factor == 4)
	{
		PointOnCircle.x = 2 * PointOnCircle.x - Center.x;
		PointOnCircle.y = 2 * PointOnCircle.y - Center.y;
		PointOnCircle.x = 2 * PointOnCircle.x - Center.x;
		PointOnCircle.y = 2 * PointOnCircle.y - Center.y;
	}
}

void Circle::zoom(double scale, int x, int y) {
	PointOnCircle.x = (PointOnCircle.x * scale) - (scale * x) + x;
	PointOnCircle.y = (PointOnCircle.y * scale) - (scale * y) + y;
	Center.x = (Center.x * scale) - (scale * x) + x;
	Center.y = (Center.y * scale) - (scale * y) + y;



}

Point Circle::getUpperLeftPoint()
{
	double radius = sqrt(pow(Center.x - PointOnCircle.x, 2) + pow(Center.y - PointOnCircle.y, 2));
	Point upperLeftPoint;
	upperLeftPoint.x = (Center.x - (sqrt(2) / 2) * radius) + 5;
	upperLeftPoint.y = (Center.y - (sqrt(2) / 2) * radius) ;
	return upperLeftPoint;
}

void Circle::SCRAMBLE(Point randomPoint)
{
	int x = randomPoint.x;
	int y = randomPoint.y;
	Move(x, y);
	double radius = sqrt(pow(Center.x - PointOnCircle.x, 2) + pow(Center.y - PointOnCircle.y, 2));
	int area = 3.14 * radius * radius;
	if (area > 60000)
	{
		resize(0.5);
		if (area > 60000) { resize(0.5); }
	}

}
void Circle::stickImage(image I, GUI* pUI)
{
	pUI->DrawImage(I, getUpperLeftPoint(), getWidth(), getHeight());
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

void Circle::Rotate(){
	//no function needed, the circle will be the same
}

shape* Circle::clone(){
	shape* pCloned = new Circle(*this);
	return pCloned;
}

void Circle::Move(int x,int y){
int diffX = x - Center.x;
int diffY = y - Center.y;
Center.x = x;
Center.y = y;
PointOnCircle.x += diffX;
PointOnCircle.y += diffY;
}

int Circle::getDuplicateID()
{
	return duplicateID;
}
void Circle::setDuplicateID(int i)
{
	duplicateID = i;
}

Point Circle::getCenter() {
	return Center;
}

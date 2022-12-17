#include "Oval.h"

Oval::Oval(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Oval::~Oval()
{}

void Oval::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawOval(Corner1, Corner2, ShpGfxInfo);
}


void Oval::SAVE(ofstream& OutFile)
{
	ID = 8;
	OutFile << "Oval " << " "
		<< ID << " "
		<< Corner1.x << " "
		<< Corner1.y << " "
		<< Corner2.x << " "
		<< Corner2.y << " "
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

bool Oval::inShape(int x, int y) const
{
	//Getting the center of the oval (h,k)
	double h = (Corner1.x + Corner2.x) / 2;
	double k = (Corner1.y + Corner2.y) / 2;

	//Getting the semi major axis a and semi minor axis b of the oval
	double semiMajor, semiMinor;
	double a = (Corner1.y - Corner2.y)/2; //to ensure the number is positive
	double b = (Corner1.x - Corner2.x)/2;//to ensure the number is positive

	if (a > b)
	{
		semiMajor = a;
		semiMinor = b;
	}
	else 
	{
		semiMajor = b;
		semiMinor = a;
	}


	if ((pow((x - h), 2) / pow(semiMajor, 2)) + (pow((y - k), 2) / pow(semiMinor, 2)) <=1)
		 return true;
	else 
		return false;
}


string Oval::shapeInfo()
{
	int h = (Corner1.x + Corner2.x) / 2;
	int k = (Corner1.y + Corner2.y) / 2;
	string msg = "The Oval center is at (" + to_string(h) + "," + to_string(k) + ")";
	return  msg;
}

void Oval::LOAD(ifstream& Infile)
{
}

double Oval::getWidth()
{
	Point Corner3;
	Corner3.x = (Corner1.x + Corner2.x) / 2;
	Corner3.y = (Corner1.y + Corner2.y) / 2;
	double width = sqrt(pow(Corner3.x - Corner1.x, 2) + pow(Corner3.y - Corner1.y, 2)) - 10;
	return width;
}

double Oval::getHeight()
{
	Point Corner3;
	Corner3.x = Corner2.x;
	Corner3.y = Corner1.y;
	double height = sqrt(pow(Corner3.x - Corner2.x, 2) + pow(Corner3.y - Corner2.y, 2)) - 30;
	return height;
}


#include "Line.h"

Line::Line(Point p1, Point p2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	point1 = p1;
	point2 = p2;
}

Line::~Line()
{
}

void Line::Draw(GUI* pUI) const
{
	pUI->DrawLine(point1, point2, ShpGfxInfo);


}

void Line::SAVE(ofstream& OutFile)
{

	//OutFile << "Line\n"
	//	<< "p1 (" << point1.x << " , " << point1.y << ")\n"
	//	"p2 (" << point2.x << " , " << point2.y << ")\n"
	//	<< "BorderWdth : " << ShpGfxInfo.BorderWdth << "\n"
	//	<< "isFilled : " << ShpGfxInfo.isFilled << "\n"
	//	<< "isSelected : " << ShpGfxInfo.isSelected << "\n"
	//	<< "DrawClr : (" << ShpGfxInfo.DrawClr.ucBlue << " , " << ShpGfxInfo.DrawClr.ucGreen << " , " << ShpGfxInfo.DrawClr.ucRed << ")\n"
	//	<< "FillClr : (" << ShpGfxInfo.FillClr.ucBlue << " , " << ShpGfxInfo.FillClr.ucGreen << " , " << ShpGfxInfo.FillClr.ucRed << ")\n\n";//color ; // Put data into file
	OutFile << "Line" << "\n"
		<< point1.x << "\n"
		<< point1.y << "\n"
		<< point2.x << "\n"
		<< point2.y << "\n"
		<< ShpGfxInfo.BorderWdth << "\n"
		<< ShpGfxInfo.isFilled << "\n"
		<< ShpGfxInfo.isSelected << "\n"
		<< (int)ShpGfxInfo.DrawClr.ucBlue << "\n"
		<< (int)ShpGfxInfo.DrawClr.ucGreen << "\n"
		<< (int)ShpGfxInfo.DrawClr.ucRed << "\n"
		<< ShpGfxInfo.FillClr.ucBlue << "\n"
		<< ShpGfxInfo.FillClr.ucGreen << "\n"
		<< ShpGfxInfo.FillClr.ucRed << "\n"
		<< "X\n";//color ; // Put data into file
}

void Line::LOAD(ifstream& InputFile)
{
	//Graph* pGr = new Graph;
	
	GfxInfo LineGfxInfo;
	Point l1,l2;
	l1.x = arrayL[0];
	l1.y = pGr->arrayL[1];
	l2.x = pGr->arrayL[3];
	l2.y = pGr->arrayL[4];
	LineGfxInfo.BorderWdth = pGr->arrayL[5];
	LineGfxInfo.isFilled = pGr->arrayL[6];
	LineGfxInfo.isSelected = pGr->arrayL[7];
	/*LineGfxInfo.DrawClr.ucBlue = pGr->arrayL[8];
	LineGfxInfo.BorderWdth = pGr->arrayL[9];
	LineGfxInfo.BorderWdth = pGr->arrayL[5];
	LineGfxInfo.BorderWdth = pGr->arrayL[5];*/

	Line* L = new Line(l1, l2, LineGfxInfo);
	pGr->Addshape(L);
	
}
	
bool Line::inShape(int x, int y) const
{
	double d = sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2)); //The distance between the two vertices of the line
	double d1 = sqrt(pow(point1.x - x, 2) + pow(point1.y - y, 2)); //The distance between one vertix and the point
	double d2 = sqrt(pow(x - point2.x, 2) + pow(y - point2.y, 2)); //The distance between the another vertix and the point

	if ((d*1.0005)  >= d1 + d2) // Because of the decimal errors I multiplied the length of the line by small factor
		return true;
	else
		return false;

}

string Line::shapeInfo()
{
	double slope;
	int length;
	string msg;

	slope = (point2.y - point1.y) / (point2.x - point1.x);
	length = sqrt(pow(point1.y - point2.y, 2) + pow(point1.x - point2.x, 2));
		

	msg = "The line slope is " + to_string(int(slope)) + " The line length is " + to_string(length);
	return msg;
}
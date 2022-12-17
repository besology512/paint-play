#include ".//ColorPallet.h"
ColorPallet::ColorPallet(GfxInfo shapeGfxInfo):shape(shapeGfxInfo){}
ColorPallet::~ColorPallet()
{}

void ColorPallet::Draw(GUI* pUI) const
{
	//call the function of draw color picker
	pUI->DrawColorPicker();
}

bool ColorPallet::inShape(int x, int y) const
{
	return false;
}

string ColorPallet::shapeInfo()
{
	return "";
}

void ColorPallet::SAVE(ofstream& OutFile)
{
}

void ColorPallet::LOAD(ifstream& Infile)
{
}
double ColorPallet::getWidth()
{
	return 0.0;
}

double ColorPallet::getHeight()
{
	return 0.0;
}


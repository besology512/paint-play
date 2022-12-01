#include "Rect.h"

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}

bool Rect::inShape(int x, int y) const
{

	// Ordering x and y from the corners
	int firstX;
	int secondX;
	int firstY;
	int secondY;

	if (Corner1.x < Corner2.x) { firstX = Corner1.x; secondX = Corner2.x;}
	else{ firstX = Corner2.x; secondX = Corner1.x; }
	if (Corner1.y < Corner2.y) { firstY = Corner1.y; secondY = Corner2.y;}
	else{ firstY = Corner2.y; secondY = Corner1.y; }


	if (((x >= firstX) && (x <= secondX)) && ((y >= firstY) && (y <= secondY)))
	{
		return true;
	}
	else return false;
}

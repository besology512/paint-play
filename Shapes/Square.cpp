#include "Square.h"

Square::Square(Point P1, Point P2, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo) {
	corner1 = P1;
	corner2 = P2;
}

Square::~Square()
{}

void Square::Draw(GUI* pUI) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pUI->DrawSquare(corner1, corner2, ShpGfxInfo);
}
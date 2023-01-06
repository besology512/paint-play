#include "shape.h"

shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
	prevBorderWidth.push(3); //default border width
	undoBorderWidth.push(3); //default border width
}
 
void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected; }

//bool shape::isSticked()
//{
//	return false;
//}

void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

void shape::ChngFillClr(color Fclr)
{	
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr;
}

void shape::ChngBorderWidth(int w)
{	
	ShpGfxInfo.BorderWdth = w;
}


void shape::setIsfilled(bool a) {
	ShpGfxInfo.isFilled = a;
}


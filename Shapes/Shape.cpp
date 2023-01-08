#include "shape.h"

shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
	prevBorderWidth.push(3); //default border width
	undoBorderWidth.push(3); //default border width
	prevBorderClrs.push(color(0, 0, 225));
	undoBorderClrs.push(color(0, 0, 225));
	prevFillClrs.push(color(225, 225, 225));
	undoFillCLrs.push(color(225, 225, 225));
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


//void shape::fillArray()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		if (i < 5)
//		{
//			arrayPoints[i].x = i * 240;
//			arrayPoints[i].y = 50;
//		}
//		else
//		{
//			arrayPoints[i].x = (i-5) * 240;
//			arrayPoints[i].y = 250;
//		}
//		
//	}
//}

void shape::setisHidden(bool h) {
	ShpGfxInfo.isHidden = h;
}

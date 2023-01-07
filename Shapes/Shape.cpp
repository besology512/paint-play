#include "shape.h"

shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
}
 
void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected; }

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


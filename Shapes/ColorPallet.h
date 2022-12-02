#pragma once

#include "../Shapes/Shape.h"
//this class is only made so I can add the color pallet to the ShapeList and loop to draw them.
class ColorPallet : public shape
{
public:
	ColorPallet(GfxInfo shapeGfxInfo);
	virtual ~ColorPallet();
	virtual void Draw(GUI* pUI) const;
};
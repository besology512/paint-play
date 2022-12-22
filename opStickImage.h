#pragma once
#include "operations/operation.h"
#include "controller.h"
#include "GUI/GUI.h"
#include ".//Shapes/StickImage.h"

class opStickImage : public operation
{
private:
	Point P1;
	double width, height;
public:
	opStickImage(controller* pCont);
	virtual ~opStickImage();

	//Add Image to the controller
	virtual void Execute();
};


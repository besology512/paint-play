#pragma once

#include "operation.h"

//Add Irrigular Polygon operation class
class opAddIrrPolygon: public operation
{
public:
	opAddIrrPolygon(controller* pCont);
	virtual ~opAddIrrPolygon();

	//Add IrrPolygon to the controller
	virtual void Execute();

};
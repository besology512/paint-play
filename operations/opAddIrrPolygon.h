#pragma once

#include "operation.h"

//Add Circle operation class
class opAddIrrPolygon: public operation
{
public:
	opAddIrrPolygon(controller* pCont);
	virtual ~opAddIrrPolygon();

	//Add Circle to the controller
	virtual void Execute();

};
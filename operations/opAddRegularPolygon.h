#pragma once

#include "operation.h"


//Add Regular Shape operation class

class opAddRegularPolygon : public operation
{
public:
	opAddRegularPolygon(controller* pCont);
	virtual ~opAddRegularPolygon();

	//Add Triangle to the controller
	virtual void Execute();


};


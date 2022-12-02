#pragma once
#include"\Zewailcity Year 2\project c++\Project Startup Code\paint-play\operations\operation.h"

class opAddSquare :public operation {
public:

	opAddSquare(controller* pCont);
	virtual ~opAddSquare();

	//Add square to the controller
	virtual void Execute();

};
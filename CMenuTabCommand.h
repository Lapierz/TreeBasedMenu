#pragma once
#ifndef CMenuTabCommand_h
#define CMenuTabCommand_h

#include "CCommand.h"
#include <vector>

class CMenuTabCommand :public CCommand
{
public:
	virtual ~CMenuTabCommand() {}
protected:
	string sUserInput();
	int iUserInput(int iLeft, int iRight);
};
#endif 
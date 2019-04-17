#pragma once
#ifndef CCommand_h
#define CCommand_h

#include <iostream>
#include <string>
#include "CTable.h"
#include <vector>
#include "CCONS_h.h"

using namespace std;

class CCommand 
{
public:
	virtual void vRunCommand();
};

#endif

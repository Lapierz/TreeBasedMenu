#pragma once
#ifndef CChangeLength_h
#define CChangeLength_h

#include "CMenuTabCommand.h"
#include "CPrintAllTab.h"
#include "CMenuItem.h"
#include "CCONS_h.h"

class CChangeLength : public CMenuTabCommand
{
public:
	CChangeLength(vector <CTable*> *v_vector);
	~CChangeLength();
	void vRunCommand();
private:
	vector <CTable*> * v_vector;
};

#endif 
#pragma once
#ifndef CChangeName_h
#define CChangeName_h

#include "CMenuTabCommand.h"
#include "CPrintAllTab.h"
#include "CCONS_h.h"

class CChangeName : public CMenuTabCommand
{
public:
	CChangeName(vector <CTable*> *v_vector);
	~CChangeName();
	void vRunCommand();
private:
	vector <CTable*> *v_vector;
};

#endif 
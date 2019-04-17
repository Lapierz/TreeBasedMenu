#pragma once
#ifndef CDeleteTab_h
#define CDeleteTab_h

#include"CMenuTabCommand.h"
#include "CPrintAllTab.h"
#include "CCONS_h.h"

class CDeleteTab:public CMenuTabCommand
{
public:
	CDeleteTab(vector <CTable*> *v_vector);
	~CDeleteTab();
	void vRunCommand();
private:
	vector <CTable*> *v_vector;
};
#endif
#pragma once
#ifndef CPrintAllTab_h
#define CPrintAllTab_h

#include"CMenuTabCommand.h"
#include "CCONS_h.h"


class CPrintAllTab : public CMenuTabCommand
{
public:
	CPrintAllTab(vector <CTable*> *v_vector);
	~CPrintAllTab();
	void vRunCommand();
private:
	vector <CTable*> *v_vector;
};
#endif 
#pragma once
#ifndef  CTable_h
#define  CTable_h

#include <iostream>
#include <string>
#include <algorithm>
#include "CCONS_h.h"

using namespace std;

class CTable {
private:
	int *pi_tab;
	int i_size;
	string s_name;
public:
	CTable();
	CTable(string sName, int iLength);
	CTable(CTable &pcOther);
	~CTable();
	void vSetName(string sName);
	void vSetValue(int iAdress, int iValue);
	int iReadValue(int iAdress);
	string sToString();
	void vChangeLength(int iLength);
	void vSetTable(CTable cSecondObject);
	int iReadSize();
};

#endif 

//Plik : CTable.cpp
#include "pch.h"
#include "CTable.h"

CTable::CTable() {
	s_name = S_DEFAULT_TABLE_NAME;
	pi_tab = new int[I_DEFAULT_TABLE_SIZE];
	i_size = I_DEFAULT_TABLE_SIZE;
}

CTable::CTable(string sName, int iLength) {
	s_name = sName;
	pi_tab = new int[iLength];
	i_size = iLength;
}

CTable::CTable(CTable &pcOther) {
	s_name = pcOther.s_name + S_COPPY_END;
	i_size = pcOther.i_size;
	pi_tab = new int[i_size];
	memcpy(pi_tab,pcOther.pi_tab,sizeof(int)*i_size);
}

CTable::~CTable() {
	delete pi_tab;
}

void CTable::vSetName(string sName) {
	s_name = sName;
}

void CTable::vSetValue(int iAdress,int iValue) {
	if (0<=iAdress && iAdress <=i_size-1) {
		pi_tab[iAdress] = iValue;
	}
}

int CTable::iReadValue(int iAdress) {
	if (0 <= iAdress&& iAdress<= i_size - 1) {
		return pi_tab[iAdress];
	}
	return -1;
}

string CTable::sToString() {
	string s_values;
	for (int i = 0; i < i_size; i++) {
		s_values += (to_string(pi_tab[i])+S_COMMA);
	}
	return s_name + S_SPACE + S_LEN +to_string(i_size)+S_SPACE+ s_values;
}

void CTable::vChangeLength(int iLength) {
	int *pi_tab_new;
	pi_tab_new = new int[iLength];
	for (int i = 0; i <min(iLength,i_size); i++){
		pi_tab_new[i] = pi_tab[i];
	}
	delete	 pi_tab;
	i_size = iLength;
	pi_tab = pi_tab_new;
}

void CTable::vSetTable(CTable cSecondObject) {
	int *pi_tab_new;
	int i_size_second=cSecondObject.i_size;
	pi_tab_new = new int[i_size_second];
	memcpy(pi_tab_new, cSecondObject.pi_tab, sizeof(int)*i_size_second);
	i_size = i_size_second;
	delete pi_tab;
	pi_tab = pi_tab_new;
}

int CTable::iReadSize() {
	return i_size;
}

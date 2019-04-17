#include "pch.h"
#include "CChangeLength.h"

CChangeLength::CChangeLength(vector <CTable*> *v_vector) {
	this->v_vector = v_vector;
} 

CChangeLength::~CChangeLength() {
	delete v_vector;
}

void CChangeLength::vRunCommand() {
	if (v_vector->empty()) {
		cout << S_EMPTY_TAB << endl;
		return;
	}
	else {
		cout << S_WHAT_TAB_INPUT << endl;
		int i_input = iUserInput(0, v_vector->size() - 1); 
		cout << S_ENTER_LEN_INPUT << endl;
		int i_length = iUserInput(1, INT_MAX);
		v_vector->at(i_input)->vChangeLength(i_length);
	}
}
#include "pch.h"
#include "CPrintTab.h"

CPrintTab::CPrintTab(vector <CTable*> *v_vector) {
	this->v_vector = v_vector;
}

CPrintTab::~CPrintTab() {
	delete v_vector;
}

void CPrintTab::vRunCommand() {
	if (!v_vector->empty()) {
		cout << S_WHAT_TAB_INPUT << endl;
		int i_input = iUserInput(0, v_vector->size() - 1);
		cout << v_vector->at(i_input)->sToString() << endl;
	}
	else {
		cout << S_EMPTY_TAB << endl;
	}
}
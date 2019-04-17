// Plik: CPrintAllTab.cpp  

#include "pch.h"
#include "CPrintAllTab.h"

CPrintAllTab::CPrintAllTab(vector <CTable*> *v_vector) {
	this->v_vector = v_vector;
}

CPrintAllTab::~CPrintAllTab() {
	delete v_vector;
}

void CPrintAllTab::vRunCommand() {
	int i_size = v_vector->size();
	cout << S_PART << endl;
	for (int i = 0; i < i_size; i++) {
		cout << S_SPACE + to_string(i) + S_DOT + v_vector->at(i)->sToString() << endl << endl;
	}
	cout << S_PART << endl;
}
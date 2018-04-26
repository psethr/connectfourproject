//Seth Perts
//CPSC 444
//Project Connect 4
//Class where the data is stored for each box of the board including
//who it is controlled by.
#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Box {

public:
	Box();
	Box(string controlledBy);
	string getControlledBy();
	void setControlledBy(string newControlledBy);

private:
	string controlledBy;
};


#endif //BOX_H
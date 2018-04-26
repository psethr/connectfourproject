//Seth Perts
//CPSC 444
//Project Connect 4
//Class where the data is stored for each box of the board including
//who it is controlled by.
#ifndef BOX_CPP
#define BOX_CPP

#include "Box.h"


Box::Box()
{
	this->controlledBy = "";
}


Box::Box(string controlledBy)
{
	this->controlledBy = controlledBy;
}


string Box::getControlledBy()
{
	return this->controlledBy;
}


void Box::setControlledBy(string newControlledBy)
{
	this->controlledBy = newControlledBy;
}
#endif // BOX_CPP
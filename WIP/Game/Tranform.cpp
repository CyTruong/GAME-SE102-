#include "Tranform.h"



Tranform::Tranform()
{
	position = new Position();
	size = new Size();
}

Tranform::Tranform(int x, int y) {
	position = new Position(x, y);
}


#include "Viewport.h"



Viewport::Viewport(RectI port)
{
	this->port = port;
}

int Viewport::getHeight() {
	return port.height;
}

int Viewport::getWidth() {
	return port.width;
}


#pragma once
#include "Direction.h"
#include "Rect.h"

class Viewport
{
private:
	RectI port;
public:
	Viewport(RectI port);
	int getWidth();
	int getHeight();
	RectI getPort() { return port; }
};


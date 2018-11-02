#include "Position.h"


Position::Position() {

}

Position::Position(int x, int y) {
	this->pX = x;
	this->pY = y;
}

Position::Position(Position* p) {
	this->pX = p->pX;
	this->pY = p->pY;
}


#include "Gameobject.h"


Gameobject::Gameobject()
{

}

void Gameobject::Start() {
	if (this->animation != NULL) {

	}
	if (this->control != NULL) {
		
	}
}

void Gameobject::Update() {
	this->control->Poll_input();
}
void Gameobject::Stop(){}



Gameobject::~Gameobject()
{
	delete this->control;
	delete this->animation;
}

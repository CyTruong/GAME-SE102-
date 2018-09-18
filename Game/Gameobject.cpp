#include "Gameobject.h"


void Gameobject::OnreciveControl(char keys[256]) {

}

Gameobject::Gameobject()
{
	__hook(&IControlEventSender::TriggerEvent, &Esource, &Gameobject::OnreciveControl);
}

void Gameobject::Start() {
	if (this->animation != NULL) {

	}
	if (this->control != NULL) {
		
	}
}



Gameobject::~Gameobject()
{
	delete this->control;
	delete this->animation;
}

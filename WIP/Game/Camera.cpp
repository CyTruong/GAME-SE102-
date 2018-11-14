#include "Camera.h"



Camera::Camera()
{
	position = new Position();
}

void Camera::setTarget(Gameobject* gobj) {
	this->targetObj = gobj;
}

void Camera::Update() {
	this->position->pX = targetObj->tranform->position->pX - SCREEN_WIDTH/2 + targetObj->colider->width;
	this->position->pY = targetObj->tranform->position->pY - SCREEN_HEIGHT*2/3 + targetObj->colider->height;
}

Camera::~Camera()
{
}

#include "Camera.h"



Camera::Camera()
{
	position = new Position();
}

void Camera::setTarget(Gameobject* gobj) {
	this->targetObj = gobj;
}

void Camera::Update() {
	this->position->pX = targetObj->tranform->position->pX - SCREEN_WIDTH + targetObj->colider->width;
	this->position->pY = targetObj->tranform->position->pY - SCREEN_HEIGHT + targetObj->colider->height;
}

Camera::~Camera()
{
}

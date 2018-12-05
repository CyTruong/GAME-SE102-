#include "MegamanSprite.h"

MegamanSprite::MegamanSprite(int index, float respawnX, float respawnY, Direction movedir) 
{
	this->pData = new MegamanData();

}

void MegamanSprite::loadResources()
{

	TextureArray* temp = new TextureArray("Resources\\Sprites", "Megaman", "stand", 1, 60);

	delete temp;

	// add more 

}

void MegamanSprite::setCameraRect(RectF r)
{
	pData->cameraRect = r;
}

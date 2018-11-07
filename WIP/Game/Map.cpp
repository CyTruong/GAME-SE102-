#include "Map.h"



Map::Map()
{
}

Map::Map(HWND hwnd,char* source)
{
	this->jsFileSource = dxgraphics::getInstance()->standardizedSourceName(source);
	this->hWnd = hWnd;
}

int Map::Creat() {
	try
	{
		jsMapDocument = dxgraphics::LoadJSonDocument(this->jsFileSource);
	}
	catch (const std::exception&)
	{
		return 0;
	}
	const rapidjson::Value& titlesheet = jsMapDocument["tilesets"];
	char* jsMapSource = _strdup(titlesheet[0]["source"].GetString());
	LoadTexture(jsMapSource);
	
	HRESULT result = D3DXCreateSprite(dxgraphics::getInstance()->getDevice(), &sprite_handler);
	if (result != D3D_OK)
	{
		MessageBox(hWnd, "Somthing wrong when creat sprite handler", "error", MB_OK);
		return 0;
	}
}

vector<Gameobject*> Map::getObjList(Camera* cam) {
	vector<Gameobject*> gobj;
	const rapidjson::Value& tileLayer = jsMapDocument["layers"];
	for (int i = 0; i < tileLayer.Size(); i++) {
		if (tileLayer[i].HasMember("objects")) {
			char* name = _strdup(tileLayer[i]["name"].GetString());
			const rapidjson::Value& objlist = tileLayer[i]["objects"];

			for (int j = 0 ; j < objlist.Size(); j++) {
				Gameobject *obj = new Gameobject();
				obj->tag = name;
				obj->colider->position->pX = (int)(objlist[j]["x"].GetFloat());
				obj->colider->position->pY = (int)(objlist[j]["y"].GetFloat());
				obj->colider->width = (int)(objlist[j]["width"].GetFloat());
 				obj->colider->height = (int)(objlist[j]["height"].GetFloat());
				gobj.push_back(obj);
			}
		}
	}

	//return all obj

	return gobj;
}


void Map::LoadTexture(char* source) {
	Document tiledoc;
	try
	{
		tiledoc = dxgraphics::LoadJSonDocument(dxgraphics::getInstance()->standardizedSourceName(source));
	}
	catch (const std::exception&)
	{

	}
	char* map = _strdup(tiledoc["image"].GetString());
	this->mapFile.mapTexture = dxgraphics::getInstance()->LoadTexture(dxgraphics::getInstance()->standardizedSourceName(map), D3DCOLOR_XRGB(0, 0, 0));
	this->mapFile.height = tiledoc["imageheight"].GetInt();
	this->mapFile.width = tiledoc["imagewidth"].GetInt();
	this->mapFile.name = _strdup(tiledoc["name"].GetString());
}


void Map::DrawScene(Camera* cam) {
	
	sprite_handler->Begin(D3DXSPRITE_ALPHABLEND);
	
	RECT viewport = { cam->position->pX,cam->position->pY,cam->position->pX + SCREEN_WIDTH,cam->position->pY + SCREEN_HEIGHT };
	sprite_handler->Draw(
		this->mapFile.mapTexture,
		&viewport,
		NULL,
		NULL,
		TRANSCOLOR
	);

	sprite_handler->End();
}

Map::~Map()
{
}

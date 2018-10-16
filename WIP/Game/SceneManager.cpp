#include "SceneManager.h"




SceneManager* SceneManager::GetInstance()
{
	if (Instance==nullptr)
		Instance = new SceneManager();

	return Instance;
}

Scene* SceneManager::GetCurScene()
{
	return CurScene;
}

void SceneManager::createScene(Scene * scene)
{
	if (scene)
	{
		if (CurScene!=nullptr)
		{
			delete CurScene; 

			CurScene = scene; 
			 
		}
		 
	}

}

//void SceneManager::createScene(Scene * scene)
//{
//
//
//}

SceneManager::SceneManager()
{
	CurScene = nullptr;
}

SceneManager::~SceneManager()
{
}

void SceneManager::Update(float dt)
{
	SceneManager::GetCurScene()->onUpdate(); 

}

void SceneManager::ReplaceScene(Scene *scene)
{
	delete CurScene;

	CurScene = scene;
}
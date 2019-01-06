#pragma once
#include "EnemyState.h"
class ZuliaShoot2State :
	public EnemyState
{
private:
	RectF range;
	int counterFrame;
public:
	ZuliaShoot2State(EnemyData *enemydata, RectF Range);
	void onUpdate();
	void createBee();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void onDead() override;
	~ZuliaShoot2State();
};


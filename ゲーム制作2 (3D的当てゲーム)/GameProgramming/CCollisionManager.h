#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "CTaskManager.h"

class CCollisionManager :public CTaskManager
{
	//マネージャのインスタンス
	static CCollisionManager*mpInstance;
public:
	//インスタンスの取得
	static CCollisionManager*Get();
	//衝突処理
	void Collision();
};

#endif
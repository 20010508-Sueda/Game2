#ifndef CENEMY3_H
#define CENEMY3_H
//キャラクタクラスのインクルード
#include "CCharacter.h"
//コライダクラスのインクルード
#include "CCollider.h"

class CEnemy3 :public CCharacter{
public:
	//モデルデータ
	static CModel mModel;
	//コンストラクタ
	CEnemy3();
	//CEnemy(位置、回転、拡縮)
	CEnemy3(const CVector& position, const CVector& rotation, const CVector& scale);

	//コライダ
	CCollider mCollider;

	void Collision(CCollider*m, CCollider*o);
	void TaskCollision();

	int mHp;  //ヒットポイント
};

#endif
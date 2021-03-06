#ifndef CENEMY2_H
#define CENEMY2_H
//キャラクタクラスのインクルード
#include "CCharacter.h"
//コライダクラスのインクルード
#include "CCollider.h"

class CEnemy2 :public CCharacter{
public:
	//モデルデータ
	static CModel mModel;
	//コンストラクタ
	CEnemy2();
	//CEnemy(位置、回転、拡縮)
	CEnemy2(const CVector& position,const CVector& rotation,const CVector& scale);

	//コライダ
	CCollider mCollider;

	void Collision(CCollider*m, CCollider*o);
	void TaskCollision();

	int mHp;  //ヒットポイント
};

#endif
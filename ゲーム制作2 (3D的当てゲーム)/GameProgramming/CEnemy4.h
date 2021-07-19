#ifndef CENEMY4_H
#define CENEMY4_H
//キャラクタクラスのインクルード
#include "CCharacter.h"
//コライダクラスのインクルード
#include "CCollider.h"

class CEnemy4 :public CCharacter{
public:
	//モデルデータ
	static CModel mModel;
	//コンストラクタ
	CEnemy4();
	//CEnemy(位置、回転、拡縮)
	CEnemy4(const CVector& position, const CVector& rotation, const CVector& scale);

	//コライダ
	CCollider mCollider;

	void Collision(CCollider*m, CCollider*o);
	void TaskCollision();
	void Update();

	int mHp;  //ヒットポイント
	int CountFrame = 0;    //敵の動きの反転
};

#endif
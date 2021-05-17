#ifndef CBULLET_H
#define CBULLET_H
//キャラクタクラスのインクルード
#include "CCharacter.h"
//三角形クラスのインクルード
#include "CTriangle.h"
//コライダクラスのインクルード
#include "CCollider.h"

class CBullet :public CCharacter{
public:
	//三角形
	CTriangle mT;
	//幅と奥行きの設定
	//Set(幅、奥行)
	void Set(float w, float d);
	//更新
	void Update();
	//描画
	void Render();

	//生存時間
	int mLife;

	CBullet();

	//コライダ
	CCollider mCollider;

	//衝突処理
	//Collision(コライダ1、コライダ2)
	void Collision(CCollider*m, CCollider*o);
};

#endif
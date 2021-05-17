#ifndef CCOLLIDER_H
#define CCOLLIDER_H
//キャラクタクラスのインクルード
#include "CCharacter.h"
//トランスフォームクラスのインクルード
#include "CTransform.h"
/*
コライダクラス
衝突判定データ
*/
class CCollider :public CTransform,public CTask{
public:
	CCharacter*mpParent; //親
	CMatrix*mpMatrix; //親行列
	float mRadius; //半径
	//コンストラクタ
	//CCollider(親、親行列、位置、回転、拡縮、半径)
	CCollider(CCharacter*parent, CMatrix*matrix, CVector position, float radius);
	//描画
	void Render();
	//デストラクタの宣言
	~CCollider();
	//衝突判定
	//Collision(コライダ1、コライダ2)
	//return:true(衝突している)false(衝突していない)
	static bool Collision(CCollider*m, CCollider*o);
};

#endif
#ifndef CCHARACTER_H
#define CCHARACTER_H
//変換行列クラスのインクルード
#include "CTransform.h"
//モデルクラスのインクルード
#include "CModel.h"
#include "CTask.h"

//コライダクラスの宣言
class CCollider;

class CCharacter :public CTransform,public CTask{
public:
	CModel*mpModel; //モデルのポインタ
	//描画処理
	void Render();
	//デストラクタ
	~CCharacter();
	//コンストラクタ
	CCharacter();
	//衝突処理
	virtual void Collision(CCollider*m, CCollider*o){}
};

#endif
#ifndef CENEMY_H
#define CENEMY_H
//キャラクタクラスのインクルード
#include "CCharacter.h"
//コライダクラスのインクルード
#include "CCollider.h"
//テキストクラスのインクルード
#include "CText.h"

class CEnemy :public CCharacter{
public:
	//コンストラクタ
	//CEnemy(モデル、位置、回転、拡縮)
	CEnemy(CModel*model, CVector position, CVector rotation, CVector scale);
	//更新処理
	void Update();
	//描画処理
	void Render();

	CText mText;
	//コライダ
	CCollider mCollider;

	void Collision(CCollider*m, CCollider*o);

	int mHp;  //ヒットポイント
};

#endif
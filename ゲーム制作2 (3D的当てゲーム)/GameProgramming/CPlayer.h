#ifndef CPLAYER_H
#define CPLAYER_H
//キャラクタクラスのインクルード
#include "CCharacter.h"
#include "CBullet.h"
#include "CText.h"

class CPlayer :public CCharacter{
public:
	CText mText;
	//更新処理
	void Update();
	//描画処理
	void Render();

	//デフォルトコンストラクタ
	CPlayer::CPlayer()
	{
		//テクスチャファイルの読み込み(1行64列)
		mText.LoadTexture("font.tga", 1, 64);
	}
};

#endif
#ifndef CPLAYER_H
#define CPLAYER_H
//キャラクタクラスのインクルード
#include "CCharacter.h"
#include "CBullet.h"

class CPlayer :public CCharacter{
public:
	//更新処理
	void Update();
};

#endif
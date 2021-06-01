#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CVector.h"
#include "CModel.h"
#include "CCharacter.h"
#include "CPlayer.h"
#include "CText.h"

/*
ゲームのシーン
*/
class CSceneGame : public CScene {
public:
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

	void Render();

	static int EnemyCount;

	CVector mEye;

	//モデルクラスのインスタンス作成
	CModel mModel;

	CModel mBackGround; //背景モデル

	CPlayer mPlayer;

	CText mText;

	CSceneGame();
};

#endif

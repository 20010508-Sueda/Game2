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

	static int Time;

	static int EnemyCount;

	static int Score;

	int Count;

	CVector mEye;

	//モデルクラスのインスタンス作成
	CModel mModel;

	CModel mBackGround; //背景モデル

	CPlayer*mPlayer;

	CText mText;

	CSceneGame();

	~CSceneGame();

	//次のシーンの取得
	EScene GetNextScene();
};

#endif

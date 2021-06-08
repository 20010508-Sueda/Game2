#ifndef CSCENEGAME2_H
#define CSCENEGAME2_H
#include "CScene.h"
#include "CVector.h"
#include "CModel.h"
#include "CCharacter.h"
#include "CPlayer.h"
#include "CText.h"

/*
ゲームのシーン
*/
class CSceneGame2 : public CScene {
public:
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

	void Render();

	static int Time2;

	static int EnemyCount2;

	static int Score2;

	int Count2;

	CVector mEye;

	//モデルクラスのインスタンス作成
	CModel mModel;

	CModel mBackGround; //背景モデル

	CPlayer mPlayer;

	CText mText;

	CSceneGame2();

	//次のシーンの取得
	EScene GetNextScene();
};

#endif
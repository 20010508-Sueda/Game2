#ifndef CSCENETITLE_H
#define CSCENETITLE_H
#include "CScene.h"
#include "CKey.h"
#include "CText.h"

class CSceneTitle :public CScene{
public:
	CText mText;

	CSceneTitle();

	//描画処理
	void Render();

	//初期化のオーバーライド
	void Init(){
		//シーンの設定
		mScene = ETITLE;
	}
	//更新処理のオーバーライド
	void Update(){
		//親の描画処理
		CSceneTitle::Render();
	}

	//次のシーンの取得
	EScene GetNextScene();
};

#endif
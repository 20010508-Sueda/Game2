#ifndef CSCENETITLE_H
#define CSCENETITLE_H
#include "CScene.h"
#include "CKey.h"
#include "CText.h"
#include "CSound.h"

extern CSound Se1;

class CSceneTitle :public CScene{
public:
	CText mText;

	CSceneTitle();

	//描画処理
	void Render();

	//初期化のオーバーライド
	void Init(){
		//サウンド(wav)ファイルの読み込み
		Se1.Load("se_chun1 (online-audio-converter.com).wav");
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
#include "CSceneTitle.h"
#include "CUtil.h"

//次のシーンの取得
CScene::EScene CSceneTitle::GetNextScene(){
	return mScene;
}

CSceneTitle::CSceneTitle()
{
	//テクスチャファイルを読み込む
	//フォントの設定
	mText.LoadTexture("FontWhite.tga", 1, 64);
}

void CSceneTitle::Render(){
	//2Dの描画開始
	CUtil::Start2D(-400, 400, -300, 300);
	//描画色の設定(白)
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	//文字編集エリアの作成
	char buf[64];

	//文字列の描画
	mText.DrawString("TITLE", -200, 0, 50, 50);
	mText.DrawString("PUSH ENTER KEY", -200, -100, 16, 16);
	if (CKey::Once(VK_RETURN)){
		//次のシーンはゲーム
		mScene = EGAME;
	}

	//2Dの描画終了
	CUtil::End2D();
}
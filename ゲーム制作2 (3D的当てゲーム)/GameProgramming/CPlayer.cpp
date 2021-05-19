//プレイヤークラスのインクルード
#include "CPlayer.h"
//キークラスのインクルード
#include "CKey.h"
#include "CTaskManager.h"
#include "CUtil.h"

int Time = 120 * 60;

//更新処理
void CPlayer::Update(){
	//Aキー入力で回転
	if (CKey::Push('A')){
		//Y軸の回転値を増加
		mRotation.mY += 1;
	}
	//変換行列の更新
	CTransform::Update();

	if (CKey::Push('D')){
		mRotation.mY -= 1;
	}
	//Sキー入力で上向き
	if (CKey::Push('S')){
		//X軸の回転値を減算
		mRotation.mX -= 1;
	}
	//Wキー入力で上向き
	if (CKey::Push('W')){
		//X軸の回転値を加算
		mRotation.mX += 1;
	}
	//CCharacterの更新
	CTransform::Update();

	//スペースキー入力で弾発射
	if (CKey::Push(VK_SPACE)){
		CBullet*bullet = new CBullet();
		bullet->Set(0.1f, 1.5f);
		bullet->mPosition = CVector(0.0f, 0.0f, 10.0f)*mMatrix;
		bullet->mRotation = mRotation;
		bullet->Update();
//		TaskManager.Add(bullet);
	}

	if (Time > 0){
		Time--;
	}
}

void CPlayer::Render()
{
	//親の描画処理
	CCharacter::Render();

	//2Dの描画開始
	CUtil::Start2D(-400, 400, -300, 300);
	//描画色の設定(白)
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	//文字編集エリアの作成
	char buf[64];

	//残り時間の表示
	//文字列の設定
	sprintf(buf, "TIME %d", Time / 60);
	//文字列の描画
	mText.DrawString(buf, 150, -250, 16, 16);

	//スコアの表示
	//文字列の設定


	//ゲーム終了の表示
	if (Time == 0){
		mText.DrawString("FINISH!!", -200, 0, 32, 32);
		mText.DrawString("NEXT STAGE", -130, -60, 15, 15);
	}

	//2Dの描画終了
	CUtil::End2D();
}
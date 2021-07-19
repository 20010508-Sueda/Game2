//プレイヤークラスのインクルード
#include "CPlayer.h"
//キークラスのインクルード
#include "CKey.h"
#include "CTaskManager.h"
#include "CSound.h"

//外部変数の参照の作成
extern CSound Se2;

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
	if (CKey::Once(VK_SPACE)){
		CBullet*bullet = new CBullet();
		bullet->Set(0.1f, 1.5f);
		bullet->mPosition = CVector(0.0f, 0.0f, 10.0f)*mMatrix;
		bullet->mRotation = mRotation;
		bullet->Update();
		//サウンド再生
		Se2.Play();
//		TaskManager.Add(bullet);
	}
}
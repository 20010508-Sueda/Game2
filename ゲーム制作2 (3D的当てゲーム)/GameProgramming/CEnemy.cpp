#include "CEnemy.h"
#include "CEffect.h"
#include "CUtil.h"
#define HP 1  //耐久値

int Time = 120 * 60;

//コンストラクタ
//CEnemy(モデル、位置、回転、拡縮)
CEnemy::CEnemy(CModel*model, CVector position, CVector rotation, CVector scale)
:mCollider(this, &mMatrix, CVector(0.0f,0.0f,0.0f),0.4f)
, mHp(HP)
{
	//モデル、位置、回転、拡縮を設定する
	mpModel = model;        //モデルの設定
	mPosition = position;   //位置の設定
	mRotation = rotation;   //回転の設定
	mScale = scale;         //拡縮の設定
	//テクスチャファイルの読み込み(1行64列)
	mText.LoadTexture("FontWhite.tga", 1, 64);
}

//更新処理
void CEnemy::Update(){
	if (Time > 0){
		Time--;
	}
	//行列を更新
	CTransform::Update();
	//位置を移動
//	mPosition = CVector(0.0f, 0.0f, 0.9f)*mMatrix;
	//HPが0以下の時　撃破
	if (mHp <= 0)
	{
		mHp--;
		//15フレーム毎にエフェクト
		if (mHp % 15 == 0)
		{
			//エフェクト生成
			new CEffect(mPosition, 1.0f, 1.0f, "exp.tga", 4, 4, 2);
		}
	}
}

void CEnemy::Collision(CCollider*m, CCollider*o){
	if (CCollider::Collision(m, o)){
		//エフェクト生成
		new CEffect(o->mpParent->mPosition, 1.0f, 1.0f, "exp.tga", 4, 4, 2);
		//削除mEnabled = false;
		mHp--; //ヒットポイントの減算
		if (mHp <= 0){
			mEnabled = false;
		}
	}
}

void CEnemy::Render()
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
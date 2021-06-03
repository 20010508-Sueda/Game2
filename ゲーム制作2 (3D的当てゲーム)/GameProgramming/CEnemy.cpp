#include "CEnemy.h"
#include "CEffect.h"
#include "CSceneGame.h"
#define HP 1  //耐久値

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
}

//更新処理
void CEnemy::Update(){
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
			CSceneGame::EnemyCount--;
			CSceneGame::Score += 50;
			mEnabled = false;
		}
	}
}
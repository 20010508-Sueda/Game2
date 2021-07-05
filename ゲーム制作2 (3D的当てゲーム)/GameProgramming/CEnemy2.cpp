#include "CEnemy2.h"
#include "CEffect.h"
#include "CTaskManager.h"
#include "CSceneGame.h"
#include "CSceneGame2.h"
#define HP 2  //耐久値
#define OBJ "sphere.obj"  //モデルのファイル
#define MTL "sphere2.mtl"  //モデルのマテリアルファイル

CModel CEnemy2::mModel;   //モデルデータ作成

//デフォルトコンストラクタ
CEnemy2::CEnemy2()
:mCollider(this, &mMatrix, CVector(0.0f,0.0f,0.0f),0.5f)
, mHp(HP)
{
	//モデルがないときは読み込む
	if (mModel.mTriangles.size() == 0)
	{
		mModel.Load(OBJ, MTL);
	}
	//モデルのポインタ設定
	mpModel = &mModel;
}

//コンストラクタ
//CEnemy(位置、回転、拡縮)
CEnemy2::CEnemy2(const CVector& position,const CVector& rotation,const CVector& scale)
:CEnemy2()
{
	//位置、回転、拡縮を設定する
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	CTransform::Update();
	//優先度を1に変更する
	mPriority = 1;
	CTaskManager::Get()->Remove(this); //削除して
	CTaskManager::Get()->Add(this); //追加する
}

void CEnemy2::Collision(CCollider*m, CCollider*o){
	if (CCollider::Collision(m, o)){
		//エフェクト生成
		new CEffect(o->mpParent->mPosition, 1.0f, 1.0f, "exp.tga", 4, 4, 2);
		//削除mEnabled = false;
		mHp--; //ヒットポイントの減算
		if (mHp <= 0){
			CSceneGame::EnemyCount--;
			CSceneGame::Score += 100;
			CSceneGame2::EnemyCount2--;
			CSceneGame2::Score2 += 100;
			mEnabled = false;
		}
	}
}
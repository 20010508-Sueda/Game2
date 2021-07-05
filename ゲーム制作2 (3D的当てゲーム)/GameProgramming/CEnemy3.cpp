#include "CEnemy3.h"
#include "CEffect.h"
#include "CTaskManager.h"
#include "CSceneGame2.h"
#define HP 1  //耐久値
#define OBJ "sphere.obj"  //モデルのファイル
#define MTL "sphere.mtl"  //モデルのマテリアルファイル

CModel CEnemy3::mModel;   //モデルデータ作成

//デフォルトコンストラクタ
CEnemy3::CEnemy3()
:mCollider(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), 0.5f)
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
CEnemy3::CEnemy3(const CVector& position, const CVector& rotation, const CVector& scale)
:CEnemy3()
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

void CEnemy3::Update(){
	mPosition.mX -= 0.1;
	if (-mPosition.mX > 5){
		mPosition = CVector(0.0f, 5.0f, -25.0f), CVector(), CVector(0.5f, 0.5f, 0.5f);
	}
	CTransform::Update();
}

void CEnemy3::Collision(CCollider*m, CCollider*o){
	if (CCollider::Collision(m, o)){
		//エフェクト生成
		new CEffect(o->mpParent->mPosition, 1.0f, 1.0f, "exp.tga", 4, 4, 2);
		//削除mEnabled = false;
		mHp--; //ヒットポイントの減算
		if (mHp <= 0){
			CSceneGame2::EnemyCount2--;
			CSceneGame2::Score2 += 50;
			mEnabled = false;
		}
	}
}
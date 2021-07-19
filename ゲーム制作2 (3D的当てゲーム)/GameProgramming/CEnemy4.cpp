#include "CEnemy4.h"
#include "CEffect.h"
#include "CTaskManager.h"
#include "CSceneGame2.h"
#include "CSound.h"
#define HP 2  //耐久値
#define OBJ "sphere.obj"  //モデルのファイル
#define MTL "sphere2.mtl"  //モデルのマテリアルファイル

CModel CEnemy4::mModel;   //モデルデータ作成
extern CSound Se3;

//デフォルトコンストラクタ
CEnemy4::CEnemy4()
:mCollider(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), 0.5f)
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
CEnemy4::CEnemy4(const CVector& position, const CVector& rotation, const CVector& scale)
:CEnemy4()
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

void CEnemy4::Update(){
	CountFrame++;
	if (CountFrame > 120){
		CountFrame = 0;
	}
	if (CountFrame <= 60){
		mPosition.mY += 0.1f;
	}
	else{
		mPosition.mY -= 0.1f;
	}
	CTransform::Update();
}

void CEnemy4::Collision(CCollider*m, CCollider*o){
	if (CCollider::Collision(m, o)){
		//エフェクト生成
		new CEffect(o->mpParent->mPosition, 1.0f, 1.0f, "exp.tga", 4, 4, 2);
		//削除mEnabled = false;
		mHp--; //ヒットポイントの減算
		//サウンド再生
		Se3.Play();
		if (mHp <= 0){
			CSceneGame2::EnemyCount2--;
			CSceneGame2::Score2 += 100;
			mEnabled = false;
		}
	}
}
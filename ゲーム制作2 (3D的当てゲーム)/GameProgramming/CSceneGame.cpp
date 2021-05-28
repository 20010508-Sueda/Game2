#include "CSceneGame.h"
#include "glut.h"
#include "CVector.h"
#include "CTriangle.h"
#include "CKey.h"
#include "CMatrix.h"
#include "CTransform.h"
#include "CTaskManager.h"
#include "CEnemy.h"
#include "CCollisionManager.h"
#include "CBillBoard.h"
#include "CCamera.h"
#include "CUtil.h"

//Sphereモデル
CModel mModelSphere;
int Time = 120 * 60;

CSceneGame::CSceneGame()
{
	//テクスチャファイルの読み込み(1行64列)
	mText.LoadTexture("FontWhite.tga", 1, 64);
}

void CSceneGame::Init() {
	mEye = CVector(1.0f, 2.0f, 3.0f);

	//モデルファイルの入力
	mModel.Load("f14.obj", "f14.mtl");

	mBackGround.Load("sky.obj", "sky.mtl");

	CMatrix matrix;
	matrix.Print();

	mPlayer.mpModel = &mModel;
	mPlayer.mScale = CVector(0.1f, 0.1f, 0.1f);
	mPlayer.mPosition = CVector(0.0f, 0.0f, -3.0f);
	mPlayer.mRotation = CVector(0.0f, 180.0f, 0.0f);

	//F16モデルの読み込み
	mModelSphere.Load("sphere.obj", "sphere.mtl");

	//敵機のインスタンス作成
	new CEnemy(&mModelSphere, CVector(0.0f, 5.0f, -50.0f), CVector(), CVector(0.5f, 0.5f, 0.5f));
	new CEnemy(&mModelSphere, CVector(30.0f, 10.0f, -30.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));
	new CEnemy(&mModelSphere, CVector(-30.0f, 3.0f, -20.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));
	new CEnemy(&mModelSphere, CVector(-10.0f, 3.5f, -15.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));
	new CEnemy(&mModelSphere, CVector(10.0f, 4.0f, -40.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));
	new CEnemy(&mModelSphere, CVector(0.0f, 5.0f, 30.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));
	new CEnemy(&mModelSphere, CVector(10.0f, 3.0f, 20.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));
	new CEnemy(&mModelSphere, CVector(-10.0f, 7.0f, 10.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));
	new CEnemy(&mModelSphere, CVector(-40.0f, 5.0f, -10.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));
	new CEnemy(&mModelSphere, CVector(-20.0f, 4.5f, 5.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));
	new CEnemy(&mModelSphere, CVector(30.0f, 4.5f, 10.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));
	new CEnemy(&mModelSphere, CVector(40.0f, 5.0f, -10.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));
}

void CSceneGame::Update() {
	//タスクマネージャの更新
	CTaskManager::Get()->Update();
	//コリジョンマネージャの衝突処理
	CCollisionManager::Get()->Collision();

	//頂点1,頂点2,頂点3,法線データの作成
	CVector v0, v1, v2, n;
	//法線を上向きで設定する
	n.mX = 0.0f; n.mY = 1.0f; n.mZ = 0.0f;
	//頂点1の座標を設定する
	v0.mX = 0.0f; v0.mY = 0.0f; v0.mZ = 0.5f;
	//頂点2の座標を設定する
	v1.mX = 1.0f; v1.mY = 0.0f; v1.mZ = 0.0f;
	//頂点3の座標を設定する
	v2.mX = 0.0f; v2.mY = 0.0f; v2.mZ = -0.5f;

	if (CKey::Push('J'))
	{
		mEye.mX -= 0.1f;
	}
	if (CKey::Push('L'))
	{
		mEye.mX += 0.1f;
	}
	if (CKey::Push('I'))
	{
		mEye.mZ -= 0.1f;
	}
	if (CKey::Push('K'))
	{
		mEye.mZ += 0.1f;
	}
	if (CKey::Push('M'))
	{
		mEye.mY -= 0.1f;
	}
	if (CKey::Push('O'))
	{
		mEye.mY += 0.1f;
	}

	//カメラのパラメータを作成する
	CVector e, c, u; //視点、注視点、上方向
	//視点を求める
	e = CVector(0, 10, -30)*mPlayer.mMatrix;
	//注視点を求める
	c = mPlayer.mPosition;
	//上方向を求める
	u = CVector(0, 1, 0)*mPlayer.mMatrixRotate;
	//カメラの設定
//	gluLookAt(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);
	//カメラクラスの設定
	Camera.Set(e, c, u);
	Camera.Render();

	mBackGround.Render();

	//タスクリストの削除
	CTaskManager::Get()->Delete();
	//タスクマネージャの描画
	CTaskManager::Get()->Render();

	//コリジョンマネージャの描画
	CCollisionManager::Get()->Render();
}

void CSceneGame::Render(){
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

	if (Time > 0){
		Time--;
	}

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
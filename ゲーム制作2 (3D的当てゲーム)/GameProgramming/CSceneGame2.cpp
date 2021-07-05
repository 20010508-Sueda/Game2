#include "CSceneGame2.h"
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
#include "CEnemy2.h"
#include "CEnemy3.h"

//Sphere���f��
CModel mModelSphere2;
int CSceneGame2::Time2 = 120 * 60;
int CSceneGame2::Score2 = 0;
int CSceneGame2::EnemyCount2 = 0;

CSceneGame2::CSceneGame2()
{
	//�e�N�X�`���t�@�C���̓ǂݍ���(1�s64��)
	mText.LoadTexture("FontWhite.tga", 1, 64);

	Count2 = 1;
}

CSceneGame2::~CSceneGame2(){
	CTaskManager::Get()->Destory();
}

void CSceneGame2::Init() {
	mEye = CVector(1.0f, 2.0f, 3.0f);

	//���f���t�@�C���̓���
	mModel.Load("f14.obj", "f14.mtl");

	mBackGround.Load("sky.obj", "sky.mtl");

	Time2 = 120 * 60;
	Score2 = 0;
	EnemyCount2 = 0;

	CMatrix matrix;
	matrix.Print();

	mPlayer = new CPlayer();
	mPlayer->mpModel = &mModel;
	mPlayer->mScale = CVector(0.1f, 0.1f, 0.1f);
	mPlayer->mPosition = CVector(0.0f, 0.0f, -3.0f);
	mPlayer->mRotation = CVector(0.0f, 180.0f, 0.0f);

	//sphere���f��(�G1)�̓ǂݍ���
	mModelSphere2.Load("sphere.obj", "sphere.mtl");

	//�G�@�̃C���X�^���X�쐬
	new CEnemy(&mModelSphere2, CVector(0.0f, 5.0f, -50.0f), CVector(), CVector(0.5f, 0.5f, 0.5f));
	EnemyCount2++;
	new CEnemy(&mModelSphere2, CVector(40.0f, 5.0f, -10.0f), CVector(), CVector(0.5f, 0.5f, 0.5f));
	EnemyCount2++;
	new CEnemy(&mModelSphere2, CVector(-30.0f, 3.0f, -20.0f), CVector(), CVector(0.5f, 0.5f, 0.5f));
	EnemyCount2++;
	new CEnemy(&mModelSphere2, CVector(-10.0f, 3.5f, -15.0f), CVector(), CVector(0.5f, 0.5f, 0.5f));
	EnemyCount2++;
	new CEnemy(&mModelSphere2, CVector(10.0f, 3.0f, 20.0f), CVector(), CVector(0.5f, 0.5f, 0.5f));
	EnemyCount2++;
	new CEnemy(&mModelSphere2, CVector(-10.0f, 7.0f, 10.0f), CVector(), CVector(0.5f, 0.5f, 0.5f));
	EnemyCount2++;
	new CEnemy(&mModelSphere2, CVector(-20.0f, 4.5f, 5.0f), CVector(), CVector(0.5f, 0.5f, 0.5f));
	EnemyCount2++;
	new CEnemy(&mModelSphere2, CVector(30.0f, 4.5f, 10.0f), CVector(), CVector(0.5f, 0.5f, 0.5f));
	EnemyCount2++;
	new CEnemy2(CVector(10.0f, 4.0f, -40.0f), CVector(), CVector(0.5f, 0.5f, 0.5f));
	EnemyCount2++;
	new CEnemy2(CVector(0.0f, 5.0f, 30.0f), CVector(), CVector(0.5f, 0.5f, 0.5f));
	EnemyCount2++;
	new CEnemy2(CVector(-40.0f, 5.0f, -10.0f), CVector(), CVector(0.5f, 0.5f, 0.5f));
	EnemyCount2++;
	new CEnemy2(CVector(30.0f, 10.0f, -30.0f), CVector(), CVector(0.5f, 0.5f, 0.5f));
	EnemyCount2++;

	//�V�[���̐ݒ�
	mScene = EGAME2;
}

void CSceneGame2::Update() {
	//�^�X�N�}�l�[�W���̍X�V
	CTaskManager::Get()->Update();
	//�R���W�����}�l�[�W���̏Փˏ���
	CCollisionManager::Get()->Collision();

	//���_1,���_2,���_3,�@���f�[�^�̍쐬
	CVector v0, v1, v2, n;
	//�@����������Őݒ肷��
	n.mX = 0.0f; n.mY = 1.0f; n.mZ = 0.0f;
	//���_1�̍��W��ݒ肷��
	v0.mX = 0.0f; v0.mY = 0.0f; v0.mZ = 0.5f;
	//���_2�̍��W��ݒ肷��
	v1.mX = 1.0f; v1.mY = 0.0f; v1.mZ = 0.0f;
	//���_3�̍��W��ݒ肷��
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

	//�J�����̃p�����[�^���쐬����
	CVector e, c, u; //���_�A�����_�A�����
	//���_�����߂�
	e = CVector(0, 10, -30)*mPlayer->mMatrix;
	//�����_�����߂�
	c = mPlayer->mPosition;
	//����������߂�
	u = CVector(0, 1, 0)*mPlayer->mMatrixRotate;
	//�J�����̐ݒ�
	//	gluLookAt(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);
	//�J�����N���X�̐ݒ�
	Camera.Set(e, c, u);
	Camera.Render();

	mBackGround.Render();

	//�^�X�N���X�g�̍폜
	CTaskManager::Get()->Delete();
	//�^�X�N�}�l�[�W���̕`��
	CTaskManager::Get()->Render();

	//�R���W�����}�l�[�W���̕`��
	CCollisionManager::Get()->Render();

	//�e�̕`�揈��
	CSceneGame2::Render();
}

void CSceneGame2::Render(){
	//2D�̕`��J�n
	CUtil::Start2D(-400, 400, -300, 300);
	//�`��F�̐ݒ�(��)
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	//�����ҏW�G���A�̍쐬
	char buf[64];

	//�c�莞�Ԃ̕\��
	//������̐ݒ�
	sprintf(buf, "TIME %d", Time2 / 60);

	if (Time2 > 0){
		Time2--;
	}
	//������̕`��
	mText.DrawString(buf, 150, -250, 16, 16);

	//�X�R�A�̕\��
	//������̐ݒ�
	char buf2[5000];
	sprintf(buf2, "SCORE %d", Score2);
	//������̕`��
	mText.DrawString(buf2, -375, -250, 16, 16);

	//�Q�[���I��(���ԓ��ɑS�Ă̓I�������Ȃ������ꍇ)�̕\��
	if (Time2 == 0){
		mText.DrawString("FINISH!!", -230, 0, 32, 32);
		mText.DrawString("PUSH ENTER KEY", -190, -60, 15, 15);
		if (CKey::Once(VK_RETURN)){
			mScene = ETITLE;
		}
	}

	//�Q�[���I��(���ԓ��ɑS�Ă̓I���������ꍇ)�̕\��
	if (EnemyCount2 == 0){
		mText.DrawString("FINISH!!", -200, 0, 32, 32);
		mText.DrawString("PUSH ENTER KEY", -190, -60, 15, 15);
		Time2++;
		if (CKey::Once(VK_RETURN)){
			mScene = ETITLE;
		}
	}

	//�N���A���ɃX�R�A�Z�o
	if (EnemyCount2 == 0){
		if (Count2 > 0){
			CSceneGame2::Score2 += Time2 / 10;
			Count2--;
		}
	}

	//2D�̕`��I��
	CUtil::End2D();
}

//���̃V�[���̎擾
CScene::EScene CSceneGame2::GetNextScene(){
	return mScene;
}
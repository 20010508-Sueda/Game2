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

//Sphere���f��
CModel mModelSphere;
int Time = 120 * 60;

CSceneGame::CSceneGame()
{
	//�e�N�X�`���t�@�C���̓ǂݍ���(1�s64��)
	mText.LoadTexture("FontWhite.tga", 1, 64);
}

void CSceneGame::Init() {
	mEye = CVector(1.0f, 2.0f, 3.0f);

	//���f���t�@�C���̓���
	mModel.Load("f14.obj", "f14.mtl");

	mBackGround.Load("sky.obj", "sky.mtl");

	CMatrix matrix;
	matrix.Print();

	mPlayer.mpModel = &mModel;
	mPlayer.mScale = CVector(0.1f, 0.1f, 0.1f);
	mPlayer.mPosition = CVector(0.0f, 0.0f, -3.0f);
	mPlayer.mRotation = CVector(0.0f, 180.0f, 0.0f);

	//F16���f���̓ǂݍ���
	mModelSphere.Load("sphere.obj", "sphere.mtl");

	//�G�@�̃C���X�^���X�쐬
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
	e = CVector(0, 10, -30)*mPlayer.mMatrix;
	//�����_�����߂�
	c = mPlayer.mPosition;
	//����������߂�
	u = CVector(0, 1, 0)*mPlayer.mMatrixRotate;
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
}

void CSceneGame::Render(){
	//�e�̕`�揈��
	CCharacter::Render();

	//2D�̕`��J�n
	CUtil::Start2D(-400, 400, -300, 300);
	//�`��F�̐ݒ�(��)
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	//�����ҏW�G���A�̍쐬
	char buf[64];

	//�c�莞�Ԃ̕\��
	//������̐ݒ�
	sprintf(buf, "TIME %d", Time / 60);

	if (Time > 0){
		Time--;
	}

	//������̕`��
	mText.DrawString(buf, 150, -250, 16, 16);

	//�X�R�A�̕\��
	//������̐ݒ�


	//�Q�[���I���̕\��
	if (Time == 0){
		mText.DrawString("FINISH!!", -200, 0, 32, 32);
		mText.DrawString("NEXT STAGE", -130, -60, 15, 15);
	}

	//2D�̕`��I��
	CUtil::End2D();
}
#include "CEnemy3.h"
#include "CEffect.h"
#include "CTaskManager.h"
#include "CSceneGame2.h"
#define HP 1  //�ϋv�l
#define OBJ "sphere.obj"  //���f���̃t�@�C��
#define MTL "sphere.mtl"  //���f���̃}�e���A���t�@�C��

CModel CEnemy3::mModel;   //���f���f�[�^�쐬

//�f�t�H���g�R���X�g���N�^
CEnemy3::CEnemy3()
:mCollider(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), 0.5f)
{
	//���f�����Ȃ��Ƃ��͓ǂݍ���
	if (mModel.mTriangles.size() == 0)
	{
		mModel.Load(OBJ, MTL);
	}
	//���f���̃|�C���^�ݒ�
	mpModel = &mModel;
}

//�R���X�g���N�^
//CEnemy(�ʒu�A��]�A�g�k)
CEnemy3::CEnemy3(const CVector& position, const CVector& rotation, const CVector& scale)
:CEnemy3()
{
	//�ʒu�A��]�A�g�k��ݒ肷��
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	CTransform::Update();
	//�D��x��1�ɕύX����
	mPriority = 1;
	CTaskManager::Get()->Remove(this); //�폜����
	CTaskManager::Get()->Add(this); //�ǉ�����
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
		//�G�t�F�N�g����
		new CEffect(o->mpParent->mPosition, 1.0f, 1.0f, "exp.tga", 4, 4, 2);
		//�폜mEnabled = false;
		mHp--; //�q�b�g�|�C���g�̌��Z
		if (mHp <= 0){
			CSceneGame2::EnemyCount2--;
			CSceneGame2::Score2 += 50;
			mEnabled = false;
		}
	}
}
#include "CEnemy2.h"
#include "CEffect.h"
#include "CTaskManager.h"
#define HP 1  //�ϋv�l
#define OBJ "f16.obj"  //���f���̃t�@�C��
#define MTL "f16.mtl"  //���f���̃}�e���A���t�@�C��

CModel CEnemy2::mModel;   //���f���f�[�^�쐬

//�f�t�H���g�R���X�g���N�^
CEnemy2::CEnemy2()
:mCollider(this, &mMatrix, CVector(0.0f,0.0f,0.0f),0.4f)
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
CEnemy2::CEnemy2(const CVector& position,const CVector& rotation,const CVector& scale)
:CEnemy2()
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

//�X�V����
void CEnemy2::Update(){
	
}

void CEnemy2::Collision(CCollider*m, CCollider*o){
	if (CCollider::Collision(m, o)){
		//�G�t�F�N�g����
		new CEffect(o->mpParent->mPosition, 1.0f, 1.0f, "exp.tga", 4, 4, 2);
		//�폜mEnabled = false;
		mHp--; //�q�b�g�|�C���g�̌��Z
		if (mHp <= 0){
			mEnabled = false;
		}
	}
}
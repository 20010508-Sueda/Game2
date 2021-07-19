#include "CEnemy4.h"
#include "CEffect.h"
#include "CTaskManager.h"
#include "CSceneGame2.h"
#include "CSound.h"
#define HP 2  //�ϋv�l
#define OBJ "sphere.obj"  //���f���̃t�@�C��
#define MTL "sphere2.mtl"  //���f���̃}�e���A���t�@�C��

CModel CEnemy4::mModel;   //���f���f�[�^�쐬
extern CSound Se3;

//�f�t�H���g�R���X�g���N�^
CEnemy4::CEnemy4()
:mCollider(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), 0.5f)
, mHp(HP)
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
CEnemy4::CEnemy4(const CVector& position, const CVector& rotation, const CVector& scale)
:CEnemy4()
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
		//�G�t�F�N�g����
		new CEffect(o->mpParent->mPosition, 1.0f, 1.0f, "exp.tga", 4, 4, 2);
		//�폜mEnabled = false;
		mHp--; //�q�b�g�|�C���g�̌��Z
		//�T�E���h�Đ�
		Se3.Play();
		if (mHp <= 0){
			CSceneGame2::EnemyCount2--;
			CSceneGame2::Score2 += 100;
			mEnabled = false;
		}
	}
}
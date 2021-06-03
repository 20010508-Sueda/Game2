#include "CEnemy.h"
#include "CEffect.h"
#include "CSceneGame.h"
#define HP 1  //�ϋv�l

//�R���X�g���N�^
//CEnemy(���f���A�ʒu�A��]�A�g�k)
CEnemy::CEnemy(CModel*model, CVector position, CVector rotation, CVector scale)
:mCollider(this, &mMatrix, CVector(0.0f,0.0f,0.0f),0.4f)
, mHp(HP)
{
	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model;        //���f���̐ݒ�
	mPosition = position;   //�ʒu�̐ݒ�
	mRotation = rotation;   //��]�̐ݒ�
	mScale = scale;         //�g�k�̐ݒ�
}

//�X�V����
void CEnemy::Update(){
	//�s����X�V
	CTransform::Update();
	//�ʒu���ړ�
//	mPosition = CVector(0.0f, 0.0f, 0.9f)*mMatrix;
	//HP��0�ȉ��̎��@���j
	if (mHp <= 0)
	{
		mHp--;
		//15�t���[�����ɃG�t�F�N�g
		if (mHp % 15 == 0)
		{
			//�G�t�F�N�g����
			new CEffect(mPosition, 1.0f, 1.0f, "exp.tga", 4, 4, 2);
		}
	}
}

void CEnemy::Collision(CCollider*m, CCollider*o){
	if (CCollider::Collision(m, o)){
		//�G�t�F�N�g����
		new CEffect(o->mpParent->mPosition, 1.0f, 1.0f, "exp.tga", 4, 4, 2);
		//�폜mEnabled = false;
		mHp--; //�q�b�g�|�C���g�̌��Z
		if (mHp <= 0){
			CSceneGame::EnemyCount--;
			CSceneGame::Score += 50;
			mEnabled = false;
		}
	}
}
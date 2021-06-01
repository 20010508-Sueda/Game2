#ifndef CENEMY2_H
#define CENEMY2_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
//�R���C�_�N���X�̃C���N���[�h
#include "CCollider.h"

class CEnemy2 :public CCharacter{
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���X�g���N�^
	CEnemy2();
	//CEnemy(�ʒu�A��]�A�g�k)
	CEnemy2(const CVector& position,const CVector& rotation,const CVector& scale);
	//�X�V����
	void Update();

	//�R���C�_
	CCollider mCollider;

	void Collision(CCollider*m, CCollider*o);
	void TaskCollision();

	int mHp;  //�q�b�g�|�C���g
};

#endif
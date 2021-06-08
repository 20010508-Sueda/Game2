#ifndef CENEMY3_H
#define CENEMY3_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
//�R���C�_�N���X�̃C���N���[�h
#include "CCollider.h"

class CEnemy3 :public CCharacter{
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���X�g���N�^
	CEnemy3();
	//CEnemy(�ʒu�A��]�A�g�k)
	CEnemy3(const CVector& position, const CVector& rotation, const CVector& scale);

	//�R���C�_
	CCollider mCollider;

	void Collision(CCollider*m, CCollider*o);
	void TaskCollision();

	int mHp;  //�q�b�g�|�C���g
};

#endif
#ifndef CENEMY4_H
#define CENEMY4_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
//�R���C�_�N���X�̃C���N���[�h
#include "CCollider.h"

class CEnemy4 :public CCharacter{
public:
	//���f���f�[�^
	static CModel mModel;
	//�R���X�g���N�^
	CEnemy4();
	//CEnemy(�ʒu�A��]�A�g�k)
	CEnemy4(const CVector& position, const CVector& rotation, const CVector& scale);

	//�R���C�_
	CCollider mCollider;

	void Collision(CCollider*m, CCollider*o);
	void TaskCollision();
	void Update();

	int mHp;  //�q�b�g�|�C���g
	int CountFrame = 0;    //�G�̓����̔��]
};

#endif
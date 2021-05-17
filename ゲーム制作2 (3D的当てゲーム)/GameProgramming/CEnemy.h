#ifndef CENEMY_H
#define CENEMY_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
//�R���C�_�N���X�̃C���N���[�h
#include "CCollider.h"

class CEnemy :public CCharacter{
public:
	//�R���X�g���N�^
	//CEnemy(���f���A�ʒu�A��]�A�g�k)
	CEnemy(CModel*model, CVector position, CVector rotation, CVector scale);
	//�X�V����
	void Update();
	
	//�R���C�_
	CCollider mCollider;

	void Collision(CCollider*m, CCollider*o);

	int mHp;  //�q�b�g�|�C���g
};

#endif
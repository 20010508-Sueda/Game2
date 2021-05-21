#ifndef CENEMY_H
#define CENEMY_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
//�R���C�_�N���X�̃C���N���[�h
#include "CCollider.h"
//�e�L�X�g�N���X�̃C���N���[�h
#include "CText.h"

class CEnemy :public CCharacter{
public:
	//�R���X�g���N�^
	//CEnemy(���f���A�ʒu�A��]�A�g�k)
	CEnemy(CModel*model, CVector position, CVector rotation, CVector scale);
	//�X�V����
	void Update();
	//�`�揈��
	void Render();

	CText mText;
	//�R���C�_
	CCollider mCollider;

	void Collision(CCollider*m, CCollider*o);

	int mHp;  //�q�b�g�|�C���g
};

#endif
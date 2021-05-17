#ifndef CBULLET_H
#define CBULLET_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
//�O�p�`�N���X�̃C���N���[�h
#include "CTriangle.h"
//�R���C�_�N���X�̃C���N���[�h
#include "CCollider.h"

class CBullet :public CCharacter{
public:
	//�O�p�`
	CTriangle mT;
	//���Ɖ��s���̐ݒ�
	//Set(���A���s)
	void Set(float w, float d);
	//�X�V
	void Update();
	//�`��
	void Render();

	//��������
	int mLife;

	CBullet();

	//�R���C�_
	CCollider mCollider;

	//�Փˏ���
	//Collision(�R���C�_1�A�R���C�_2)
	void Collision(CCollider*m, CCollider*o);
};

#endif
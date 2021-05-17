#ifndef CCOLLIDER_H
#define CCOLLIDER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
//�g�����X�t�H�[���N���X�̃C���N���[�h
#include "CTransform.h"
/*
�R���C�_�N���X
�Փ˔���f�[�^
*/
class CCollider :public CTransform,public CTask{
public:
	CCharacter*mpParent; //�e
	CMatrix*mpMatrix; //�e�s��
	float mRadius; //���a
	//�R���X�g���N�^
	//CCollider(�e�A�e�s��A�ʒu�A��]�A�g�k�A���a)
	CCollider(CCharacter*parent, CMatrix*matrix, CVector position, float radius);
	//�`��
	void Render();
	//�f�X�g���N�^�̐錾
	~CCollider();
	//�Փ˔���
	//Collision(�R���C�_1�A�R���C�_2)
	//return:true(�Փ˂��Ă���)false(�Փ˂��Ă��Ȃ�)
	static bool Collision(CCollider*m, CCollider*o);
};

#endif
#include "CCollider.h"
#include "CCollisionManager.h"

//�R���X�g���N�^
//CCollider(�e�A�ʒu�A��]�A�g�k�A���a)
CCollider::CCollider(CCharacter*parent, CMatrix*matrix, CVector position, float radius){
	//�e�ݒ�
	mpParent = parent;
	//�e�s��ݒ�
	mpMatrix = matrix;
	//CTransform�ݒ�
	mPosition = position; //�ʒu
	//���a�ݒ�
	mRadius = radius;
	//�R���W�������X�g�ɒǉ�
	CCollisionManager::Get()->Add(this);
}

//�`��
void CCollider::Render(){
	glPushMatrix();
	//�R���C�_�̒��S���W���v�Z
	//�����̍��W�~�e�̕ϊ��s����|����
	CVector pos = mPosition**mpMatrix;
	//���S���W�ֈړ�
	glMultMatrixf(CMatrix().Translate(pos.mX, pos.mY, pos.mZ).mM[0]);
	//DIFFUSE�ԐF�ݒ�
	float c[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	//���`��
	glutWireSphere(mRadius, 16, 16);
	glPopMatrix();
}

CCollider::~CCollider(){
	//�R���W�������X�g����폜
	CCollisionManager::Get()->Remove(this);
}

//�Փ˔���
//Collision(�R���C�_1�A�R���C�_2)
//return:true(�Փ˂��Ă���)false(�Փ˂��Ă��Ȃ�)
bool CCollider::Collision(CCollider*m, CCollider*o){
	//�e�R���C�_�̒��S���W�����߂�
	//���_�~�R���C�_�̕ϊ��s��~�e�̕ϊ��s��
	CVector mpos = m->mPosition**m->mpMatrix;
	CVector opos = o->mPosition**o->mpMatrix;
	//���S���璆�S�ւ̃x�N�g�������߂�
	mpos = mpos - opos;
	//���S�̋��������a�̍��v��菬�����ƏՓ�
	if (m->mRadius + o->mRadius > mpos.Length()){
		//�Փ˂��Ă���
		return true;
	}
	//�Փ˂��Ă��Ȃ�
	return false;
}
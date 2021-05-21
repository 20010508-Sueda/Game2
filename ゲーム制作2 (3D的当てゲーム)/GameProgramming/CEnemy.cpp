#include "CEnemy.h"
#include "CEffect.h"
#include "CUtil.h"
#define HP 1  //�ϋv�l

int Time = 120 * 60;

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
	//�e�N�X�`���t�@�C���̓ǂݍ���(1�s64��)
	mText.LoadTexture("FontWhite.tga", 1, 64);
}

//�X�V����
void CEnemy::Update(){
	if (Time > 0){
		Time--;
	}
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
			mEnabled = false;
		}
	}
}

void CEnemy::Render()
{
	//�e�̕`�揈��
	CCharacter::Render();

	//2D�̕`��J�n
	CUtil::Start2D(-400, 400, -300, 300);
	//�`��F�̐ݒ�(��)
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	//�����ҏW�G���A�̍쐬
	char buf[64];

	//�c�莞�Ԃ̕\��
	//������̐ݒ�
	sprintf(buf, "TIME %d", Time / 60);
	//������̕`��
	mText.DrawString(buf, 150, -250, 16, 16);

	//�X�R�A�̕\��
	//������̐ݒ�


	//�Q�[���I���̕\��
	if (Time == 0){
		mText.DrawString("FINISH!!", -200, 0, 32, 32);
		mText.DrawString("NEXT STAGE", -130, -60, 15, 15);
	}

	//2D�̕`��I��
	CUtil::End2D();
}
//�v���C���[�N���X�̃C���N���[�h
#include "CPlayer.h"
//�L�[�N���X�̃C���N���[�h
#include "CKey.h"
#include "CTaskManager.h"
#include "CSound.h"

//�O���ϐ��̎Q�Ƃ̍쐬
extern CSound Se2;

//�X�V����
void CPlayer::Update(){
	//A�L�[���͂ŉ�]
	if (CKey::Push('A')){
		//Y���̉�]�l�𑝉�
		mRotation.mY += 1;
	}
	//�ϊ��s��̍X�V
	CTransform::Update();

	if (CKey::Push('D')){
		mRotation.mY -= 1;
	}
	//S�L�[���͂ŏ����
	if (CKey::Push('S')){
		//X���̉�]�l�����Z
		mRotation.mX -= 1;
	}
	//W�L�[���͂ŏ����
	if (CKey::Push('W')){
		//X���̉�]�l�����Z
		mRotation.mX += 1;
	}
	//CCharacter�̍X�V
	CTransform::Update();

	//�X�y�[�X�L�[���͂Œe����
	if (CKey::Once(VK_SPACE)){
		CBullet*bullet = new CBullet();
		bullet->Set(0.1f, 1.5f);
		bullet->mPosition = CVector(0.0f, 0.0f, 10.0f)*mMatrix;
		bullet->mRotation = mRotation;
		bullet->Update();
		//�T�E���h�Đ�
		Se2.Play();
//		TaskManager.Add(bullet);
	}
}
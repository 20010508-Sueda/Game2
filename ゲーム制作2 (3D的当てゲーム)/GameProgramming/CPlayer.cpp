//�v���C���[�N���X�̃C���N���[�h
#include "CPlayer.h"
//�L�[�N���X�̃C���N���[�h
#include "CKey.h"
#include "CTaskManager.h"
#include "CUtil.h"

int Time = 120 * 60;

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
	if (CKey::Push(VK_SPACE)){
		CBullet*bullet = new CBullet();
		bullet->Set(0.1f, 1.5f);
		bullet->mPosition = CVector(0.0f, 0.0f, 10.0f)*mMatrix;
		bullet->mRotation = mRotation;
		bullet->Update();
//		TaskManager.Add(bullet);
	}

	if (Time > 0){
		Time--;
	}
}

void CPlayer::Render()
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
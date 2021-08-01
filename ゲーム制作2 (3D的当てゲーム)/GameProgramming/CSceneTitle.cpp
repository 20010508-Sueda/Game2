#include "CSceneTitle.h"
#include "CUtil.h"
#include "CSound.h"

extern CSound Se1;

//���̃V�[���̎擾
CScene::EScene CSceneTitle::GetNextScene(){
	return mScene;
}

CSceneTitle::CSceneTitle()
{
	//�e�N�X�`���t�@�C����ǂݍ���
	//�t�H���g�̐ݒ�
	mText.LoadTexture("FontWhite.tga", 1, 64);
}

void CSceneTitle::Render(){
	//2D�̕`��J�n
	CUtil::Start2D(-400, 400, -300, 300);
	//�`��F�̐ݒ�(��)
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	//�����ҏW�G���A�̍쐬
	char buf[64];

	//������̕`��
	mText.DrawString("AIM TARGET!!", -320, 0, 30, 30);
	mText.DrawString("PUSH ENTER KEY", -200, -100, 16, 16);
	if (CKey::Once(VK_RETURN)){
		//���̃V�[���̓Q�[��
		mScene = EGAME;
		//�T�E���h�Đ�
		Se1.Play();
	}

	//2D�̕`��I��
	CUtil::End2D();
}
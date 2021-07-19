#ifndef CSCENETITLE_H
#define CSCENETITLE_H
#include "CScene.h"
#include "CKey.h"
#include "CText.h"
#include "CSound.h"

extern CSound Se1;

class CSceneTitle :public CScene{
public:
	CText mText;

	CSceneTitle();

	//�`�揈��
	void Render();

	//�������̃I�[�o�[���C�h
	void Init(){
		//�T�E���h(wav)�t�@�C���̓ǂݍ���
		Se1.Load("se_chun1 (online-audio-converter.com).wav");
		//�V�[���̐ݒ�
		mScene = ETITLE;
	}
	//�X�V�����̃I�[�o�[���C�h
	void Update(){
		//�e�̕`�揈��
		CSceneTitle::Render();
	}

	//���̃V�[���̎擾
	EScene GetNextScene();
};

#endif
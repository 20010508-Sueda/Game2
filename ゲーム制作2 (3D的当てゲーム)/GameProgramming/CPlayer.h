#ifndef CPLAYER_H
#define CPLAYER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
#include "CBullet.h"
#include "CText.h"

class CPlayer :public CCharacter{
public:
	CText mText;
	//�X�V����
	void Update();
	//�`�揈��
	void Render();

	//�f�t�H���g�R���X�g���N�^
	CPlayer::CPlayer()
	{
		//�e�N�X�`���t�@�C���̓ǂݍ���(1�s64��)
		mText.LoadTexture("font.tga", 1, 64);
	}
};

#endif
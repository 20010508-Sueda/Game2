#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CVector.h"
#include "CModel.h"
#include "CCharacter.h"
#include "CPlayer.h"

/*
�Q�[���̃V�[��
*/
class CSceneGame : public CScene {
public:
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

	CVector mEye;

	//���f���N���X�̃C���X�^���X�쐬
	CModel mModel;

	CModel mBackGround; //�w�i���f��

	CPlayer mPlayer;
};

#endif

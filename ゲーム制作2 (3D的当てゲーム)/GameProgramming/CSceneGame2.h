#ifndef CSCENEGAME2_H
#define CSCENEGAME2_H
#include "CScene.h"
#include "CVector.h"
#include "CModel.h"
#include "CCharacter.h"
#include "CPlayer.h"
#include "CText.h"

/*
�Q�[���̃V�[��
*/
class CSceneGame2 : public CScene {
public:
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

	void Render();

	static int Time2;

	static int EnemyCount2;

	static int Score2;

	int Count2;

	CVector mEye;

	//���f���N���X�̃C���X�^���X�쐬
	CModel mModel;

	CModel mBackGround; //�w�i���f��

	CPlayer mPlayer;

	CText mText;

	CSceneGame2();

	//���̃V�[���̎擾
	EScene GetNextScene();
};

#endif
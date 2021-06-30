#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CVector.h"
#include "CModel.h"
#include "CCharacter.h"
#include "CPlayer.h"
#include "CText.h"

/*
�Q�[���̃V�[��
*/
class CSceneGame : public CScene {
public:
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

	void Render();

	static int Time;

	static int EnemyCount;

	static int Score;

	int Count;

	CVector mEye;

	//���f���N���X�̃C���X�^���X�쐬
	CModel mModel;

	CModel mBackGround; //�w�i���f��

	CPlayer*mPlayer;

	CText mText;

	CSceneGame();

	~CSceneGame();

	//���̃V�[���̎擾
	EScene GetNextScene();
};

#endif

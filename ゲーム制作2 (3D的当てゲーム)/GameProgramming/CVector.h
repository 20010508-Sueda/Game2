#ifndef CVECTOR_H
#define CVECTOR_H
#include "CMatrix.h"

class CVector{
public:
	//3D�e���ł̒l��ݒ�
	float mX, mY, mZ;
	//�e���ł̒l�̐ݒ�
	//Set(X���W,Y���W,Z���W)
	void Set(float x, float y, float z);

	//�f�t�H���g�R���X�g���N�^
	CVector();
	//�R���X�g���N�^
	//CVector(X���W,Y���W,Z���W)
	CVector(float x, float y, float z);

	//CVector*CMatrix�̌��ʂ�CVector�ŕԂ�
	CVector operator*(const CMatrix &m);
	
	//-���Z�q�̃I�[�o�[���[�h
	//CVector-CVector�̉��Z���ʂ�Ԃ�
	CVector operator-(const CVector &v);
	//�x�N�g���̒�����Ԃ�
	float Length();
};
#endif
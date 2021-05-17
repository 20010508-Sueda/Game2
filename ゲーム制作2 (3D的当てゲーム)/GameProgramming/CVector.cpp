#include "CVector.h"
#include <math.h>

void CVector::Set(float x, float y, float z){
	mX = x;
	mY = y;
	mZ = z;
}

CVector::CVector()
:mX(0.0f), mY(0.0f), mZ(0.0f)
{}

CVector::CVector(float x, float y, float z)
: mX(x), mY(y), mZ(z)
{}

CVector CVector::operator*(const CMatrix &m)
{
	//�|���Z�̌��ʂ�CVector�^�̒l�ŕԂ�
	return CVector(
		mX*m.mM[0][0] + mY*m.mM[1][0] + mZ*m.mM[2][0] + m.mM[3][0],
		mX*m.mM[0][1] + mY*m.mM[1][1] + mZ*m.mM[2][1] + m.mM[3][1],
		mX*m.mM[0][2] + mY*m.mM[1][2] + mZ*m.mM[2][2] + m.mM[3][2]
		);
}

//-���Z�q�̃I�[�o�[���[�h
//CVector-CVector�̉��Z���ʂ�Ԃ�
CVector CVector::operator-(const CVector &v){
	return CVector(mX - v.mX, mY - v.mY, mZ - v.mZ);
}
//�x�N�g���̒�����Ԃ�
float CVector::Length(){
	//sprt�֐��ŕ�������Ԃ�
	return sqrtf(mX*mX + mY*mY + mZ*mZ);
}

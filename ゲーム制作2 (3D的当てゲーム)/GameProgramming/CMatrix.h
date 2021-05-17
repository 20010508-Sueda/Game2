#ifndef CMATRIX_H
#define CMATRIX_H

class CMatrix{
public:
	//4�~4�̍s��f�[�^��ݒ�
	float mM[4][4];
	//�\���m�F�p
	//4�~4�̍s�����ʏo��
	void Print();
	//�f�t�H���g�R���X�g���N�^
	CMatrix();
	//�P�ʍs��̍쐬
	CMatrix Identity();
	//�g��k���s��̍쐬
	//Scale(�{��X,�{��Y,�{��Z)
	CMatrix Scale(float sx, float sy, float sz);
	//��]�s��(Y��)�̍쐬
	//RotateY(�p�x)
	CMatrix RotateY(float degree);
	//��]�s��(Z��)�̍쐬
	//RotateZ(�p�x)
	CMatrix RotateZ(float degree);
	//��]�s��(X��)�̍쐬
	//RotateX(�p�x)
	CMatrix RotateX(float degree);
	//�ړ��s��̐ݒ�
	//Translate(�ړ���X�A�ړ���Y�A�ړ���Z)
	CMatrix Translate(float mx, float my, float mz);
	//*���Z�q�̃I�[�o�[���[�h
	//CMatrix*CMatrix�̉��Z���ʂ�Ԃ�
	CMatrix operator*(const CMatrix &m);
};
#endif
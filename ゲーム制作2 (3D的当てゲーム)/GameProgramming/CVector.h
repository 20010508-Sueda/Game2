#ifndef CVECTOR_H
#define CVECTOR_H
#include "CMatrix.h"

class CVector{
public:
	//3D各軸での値を設定
	float mX, mY, mZ;
	//各軸での値の設定
	//Set(X座標,Y座標,Z座標)
	void Set(float x, float y, float z);

	//デフォルトコンストラクタ
	CVector();
	//コンストラクタ
	//CVector(X座標,Y座標,Z座標)
	CVector(float x, float y, float z);

	//CVector*CMatrixの結果をCVectorで返す
	CVector operator*(const CMatrix &m);
	
	//-演算子のオーバーロード
	//CVector-CVectorの演算結果を返す
	CVector operator-(const CVector &v);
	//ベクトルの長さを返す
	float Length();
};
#endif
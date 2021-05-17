#ifndef CMODEL_H
#define CMODEL_H

#include <vector>
#include "CTriangle.h"
#include "CMaterial.h"
#include "CMatrix.h"

class CModel{
public:
	//モデルファイルの入力
	//Load(モデルファイル名,マテリアルファイル名)
	void Load(char*obj, char*mtl);

	//三角形の可変長配列
	std::vector<CTriangle>mTriangles;

	//マテリアルポインタの可変長配列
	std::vector<CMaterial*>mpMaterials;

	~CModel();

	//描画
	void Render();

	//描画
	//Render(行列)
	void Render(const CMatrix &m);

	//頂点配列
	float*mpVertex; //頂点座標
	float*mpNormal; //法線
	float*mpTextureCoord; //テクスチャマッピング
	//デフォルトコンストラクタ
	CModel();
};

#endif
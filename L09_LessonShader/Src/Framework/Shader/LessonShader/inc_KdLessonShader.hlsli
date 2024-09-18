// 定数バッファ(メッシュ単位)	本告授業
cbuffer cbMesh : register(b1)
{
	row_major float4x4 g_mWorld;	// ワールド変換行列
};

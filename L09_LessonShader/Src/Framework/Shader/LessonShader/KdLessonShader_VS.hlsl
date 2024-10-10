// カメラやライトのデータを使える様になる	本告授業
#include "../inc_KdCommon.hlsli"
#include "inc_KdLessonShader.hlsli"

//===========================================
// 頂点シェーダー　１つ１つの頂点がやってくる
//===========================================
VSOutput main(float4 pos : POSITION,float2 uv : TEXCOORD0,float color : COLOR)
{
	VSOutput Out;

	// 受け取った位置をそのまま渡す
	Out.Pos = pos;

	// ここ重要！(座標変換)
	Out.Pos = mul(pos, g_mWorld);
	Out.Pos = mul(Out.Pos, g_mView);
	Out.Pos = mul(Out.Pos, g_mProj);

	// 頂点色
	Out.Color = color;
	
	// UV座標
	Out.UV = uv;

	return Out;
}

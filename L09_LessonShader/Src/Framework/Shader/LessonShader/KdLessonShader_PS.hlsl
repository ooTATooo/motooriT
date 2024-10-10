// カメラやライトのデータを使える様になる	本告授業
#include "../inc_KdCommon.hlsli"
#include "inc_KdLessonShader.hlsli"

// テクスチャの受け取り(画像データ そのままでは使えない)
texture2D g_baseTex : register(t0);	// ベースカラーテクスチャ

// サンプラ(テクスチャから情報を抜き出す機能)
SamplerState g_ss : register(s0);	// 通常テクスチャ描画用

float4 main(VSOutput In) : SV_TARGET
{
	//-------------------------------
	// シャドウマッピング(影判定)
	//-------------------------------
	float shadow = 1;

	// ピクセルの3D座標から、DepthMapFromLight空間へ変換
	float4 liPos = mul(float4(In.wPos, 1), g_DL_mLightVP);
	liPos.xyz /= liPos.w;

	return g_baseTex.Sample(g_ss, In.UV) * g_BaseColor * In.Color;
}

#include "HamuHamu.h"

void HamuHamu::Init()
{
	m_spPoly = std::make_shared<KdSquarePolygon>();
	m_spPoly->SetMaterial("Asset/Data/LessonData/Character/Hamu.png");
	m_spPoly->SetPivot(KdSquarePolygon::PivotType::Center_Bottom);
	m_isExpired = true;
}

void HamuHamu::Update()
{
	// ベクトル
	// キャラクターの移動速度(マネしてはいけない)
	float moveSpd = 0.1f;
	Math::Vector3 nowPos = m_mWorld.Translation();

	// 移動する方向ベクトル = (必ず長さが1で無ければならない)
	Math::Vector3 moveVec = Math::Vector3::Zero;

	if (GetAsyncKeyState('A') & 0x8000) { moveVec.x = -1.0f; }
	if (GetAsyncKeyState('D') & 0x8000) { moveVec.x = 1.0f; }
	if (GetAsyncKeyState('W') & 0x8000) { moveVec.z = 1.0f; }
	if (GetAsyncKeyState('S') & 0x8000) { moveVec.z = -1.0f; }

	// 正規化
	moveVec.Normalize();
	moveVec *= moveSpd;
	nowPos += moveVec;

	// キャラクターのワールド行列を作る処理
	m_mWorld = Math::Matrix::CreateTranslation(nowPos);

}

void HamuHamu::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(*m_spPoly, m_mWorld);
}

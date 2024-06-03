#include "UI.h"

void UI::Update()
{
	m_pos = m_mWorld.Translation() + Math::Vector3{ 0,1.5f,0 };

	Math::Vector3 res = Math::Vector3::Zero;
	m_camera.lock()->ConvertWorldToScreenDetail(m_pos, res);

	m_transMat = Math::Matrix::CreateTranslation(res.x, res.y, 0);
	m_mat = m_scaleMat * m_transMat;
}

void UI::Init()
{
	m_tex.Load("Asset/Data/LessonData/UI/hamumad.png");
	m_scaleMat = Math::Matrix::CreateScale(m_scale);
	m_transMat = Math::Matrix::Identity;
}

void UI::DrawSprite()
{
	Math::Rectangle rect = { 0,0,182,52 };
	Math::Color color = { rand() / (float)RAND_MAX,rand() / (float)RAND_MAX,rand() / (float)RAND_MAX,1.0f };

	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat);
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0, 182, 52, &rect, &color);

}

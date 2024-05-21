#include "Sun.h"

void Sun::Update()
{
	m_rot += 0.5f;
	if (m_rot > 360) { m_rot - 360; }

	m_rotMat = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(m_rot));

	m_transMat = Math::Matrix::CreateTranslation(m_pos);

	m_mWorld = m_rotMat * m_transMat;
}

void Sun::Init()
{
	m_model = std::make_shared<KdModelData>();
	m_model->Load("Asset/Data/LessonData/Planets/sun.gltf");
	m_pos = { 0,0,0 };
	m_rot = 0;
}

void Sun::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld);
}

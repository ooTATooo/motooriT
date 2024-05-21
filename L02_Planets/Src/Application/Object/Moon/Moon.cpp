#include "Moon.h"

void Moon::Update()
{
	m_rot += 3;
	if (m_rot > 360) { m_rot - 360; }

	m_rotMat = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(m_rot));

	m_transMat = Math::Matrix::CreateTranslation(m_pos);

	m_mWorld = m_rotMat * m_transMat * m_rotMat * m_earthMat;
}

void Moon::Init()
{
	m_model = std::make_shared<KdModelData>();
	m_model->Load("Asset/Data/LessonData/Planets/moon.gltf");
	m_pos = { 0,0,-2 };
	m_rot = 0;
	m_earthMat = Math::Matrix::Identity;
}

void Moon::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld);
}

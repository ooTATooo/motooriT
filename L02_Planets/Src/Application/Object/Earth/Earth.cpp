#include "Earth.h"

void Earth::Update()
{
	m_rot += 0.5f;
	if (m_rot > 360) { m_rot - 360; }

	m_rotMat = Math::Matrix::CreateRotationY(DirectX::XMConvertToRadians(m_rot));

	m_transMat = Math::Matrix::CreateTranslation(m_pos);

	m_mWorld = m_rotMat * m_transMat * m_rotMat * m_sunMat;

}

void Earth::Init()
{
	m_model = std::make_shared<KdModelData>();
	m_model->Load("Asset/Data/LessonData/Planets/earth.gltf");
	m_pos = { 0,0,-5 };
	m_rot = 0;
}

void Earth::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_model, m_mWorld);
}

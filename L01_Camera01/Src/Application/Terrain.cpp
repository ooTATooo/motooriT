#include "Terrain.h"

void Terrain::Init()
{
	m_spModel = std::make_shared<KdModelData>();
	m_spModel->Load("Asset/Data/LessonData/Terrain/Terrain.gltf");
	m_isExpired = true;
}

void Terrain::Update()
{
}

void Terrain::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawModel(*m_spModel);
}

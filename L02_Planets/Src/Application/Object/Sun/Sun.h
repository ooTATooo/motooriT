#pragma once

class Sun :public KdGameObject
{
public:

	Sun() {}
	~Sun() override {}

	void Update()override;
	void Init()override;
	void DrawLit()override;

private:

	std::shared_ptr<KdModelData> m_model = nullptr;

	Math::Matrix m_rotMat;
	Math::Matrix m_transMat;

	Math::Vector3 m_pos;

	float m_rot;

};
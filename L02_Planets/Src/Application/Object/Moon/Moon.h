#pragma once

class Moon :public KdGameObject
{
public:

	Moon() {}
	~Moon() override {}

	void Update()override;
	void Init()override;
	void DrawLit()override;

	void SetMatrix(Math::Matrix _mat) { m_earthMat = _mat; }
private:

	std::shared_ptr<KdModelData> m_model = nullptr;

	Math::Matrix m_rotMat;
	Math::Matrix m_transMat;

	Math::Vector3 m_pos;
	float m_rot;

	Math::Matrix m_earthMat;
};
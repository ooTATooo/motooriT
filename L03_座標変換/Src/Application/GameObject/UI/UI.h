#pragma once

class UI :public KdGameObject
{
public:

	UI() { Init(); }
	~UI()override {}

	void Update()override;
	void Init()override;
	void DrawSprite()override;

	void SetCamera(std::weak_ptr<KdCamera> _camera) { m_camera = _camera; }

private:

	std::weak_ptr<KdCamera> m_camera;

	KdTexture m_tex;
	Math::Matrix m_scaleMat = Math::Matrix::Identity;
	Math::Matrix m_transMat = Math::Matrix::Identity;
	Math::Matrix m_mat = Math::Matrix::Identity;

	Math::Vector3 m_pos;
	float m_scale = 0.5f;
};

#pragma once

class Character : public KdGameObject
{
public:
	Character() {}
	virtual ~Character()	override {}

	void Init()				override;
	void Update()			override;
	void DrawLit()			override;
	void DrawSprite()		override;

	void SetCamera(const std::weak_ptr<KdCamera> _camera) { m_camera = _camera; }

	void SetTerrain(const std::weak_ptr<KdGameObject> _terrain) { m_terrain = _terrain; }

private:

	std::shared_ptr<KdSquarePolygon> m_spPoly = nullptr;
	std::weak_ptr<KdCamera> m_camera;
	std::weak_ptr<KdGameObject> m_terrain;

	Math::Vector3 m_TargetPos = Math::Vector3::Zero;
};
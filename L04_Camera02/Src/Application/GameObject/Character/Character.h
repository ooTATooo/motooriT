﻿#pragma once

class CameraBase;

class Character : public KdGameObject
{
public:
	Character() {}
	virtual ~Character()	override {}

	void Init()				override;
	void Update()			override;
	void DrawLit()			override;

	void SetCamera(std::shared_ptr<CameraBase> _camera) { m_wpCamera = _camera; }


private:

	void UpdateRotate(const Math::Vector3& srcMoveVec);

	std::shared_ptr<KdSquarePolygon>	m_spPoly	= nullptr;
	std::weak_ptr<CameraBase>			m_wpCamera;

	Math::Vector3 m_woeldRot;
};
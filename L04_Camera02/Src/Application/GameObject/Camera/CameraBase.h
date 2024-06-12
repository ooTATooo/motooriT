﻿#pragma once

class CameraBase :public KdGameObject
{
public:

	CameraBase() {}
	virtual ~CameraBase() override {}

	void Init()override;
	void Update()override;
	void PreDraw()override;

	void SetTarget(const std::shared_ptr<KdGameObject>& target) { m_wpTarget = target; }

	const Math::Matrix GetRotationMatrix() const
	{
		return Math::Matrix::CreateFromYawPitchRoll(
			DirectX::XMConvertToRadians(m_DegAng.y),
			DirectX::XMConvertToRadians(m_DegAng.x),
			DirectX::XMConvertToRadians(m_DegAng.z));
	}

	const Math::Matrix GetRotationYMatrix() const
	{
		return Math::Matrix::CreateRotationY(
			DirectX::XMConvertToRadians(m_DegAng.y));
	}

protected:

	std::shared_ptr<KdCamera> m_spCamera = nullptr;
	std::weak_ptr<KdGameObject> m_wpTarget;

	Math::Matrix m_LocalPos;
	Math::Matrix m_Rotation;

	// カメラ回転用角度
	Math::Vector3 m_DegAng;
};
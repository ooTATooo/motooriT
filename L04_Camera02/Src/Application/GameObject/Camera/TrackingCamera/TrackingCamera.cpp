#include "TrackingCamera.h"

void TrackingCamera::Init()
{
	CameraBase::Init();

	// 基準点(ターゲット)からどれだけ離れているか
	m_LocalPos = Math::Matrix::CreateTranslation(0, 6.f, -5.f);

	// どれだけ傾けているか
	m_Rotation = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(45));
}

void TrackingCamera::Update()
{
	// ターゲット
	Math::Matrix _targetMat = Math::Matrix::Identity;

	const std::shared_ptr<const KdGameObject> _spTarget = m_wpTarget.lock();
	if (_spTarget)
	{
		_targetMat = _spTarget->GetMatrix();
	}

	m_mWorld = m_Rotation * m_LocalPos * _targetMat;

	CameraBase::Update();
}

#pragma once

class CameraBase;
class Character : public KdGameObject
{
public:
	Character() {}
	~Character()override {}

	void Init()override;
	void Update()override;
	void PostUpdate()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;

	void SetCamera(const std::shared_ptr<CameraBase>& camera)
	{
		m_wpCamera = camera;
	}

	void RegistHitObject(const std::shared_ptr<KdGameObject>& object)
	{
		m_wpHitObjectList.push_back(object);
	}

private:

	// キャラクターの回転行列を作成する
	void UpdateRotate(const Math::Vector3& srcMoveVec);
	// 衝突判定とそれに伴う座標の更新
	void UpdateCollision();

	std::shared_ptr<KdModelWork> m_spModel = nullptr;
	std::shared_ptr<KdAnimator>	m_spAnimator = nullptr;

	std::weak_ptr<CameraBase> m_wpCamera;
	std::vector<std::weak_ptr<KdGameObject>> m_wpHitObjectList{};

	Math::Vector3 m_worldRot;

	float m_Gravity = 0;
	bool m_IsGround = false;

	// ステートパターン管理係！
private:

	class ActionAtateBase
	{
	public:

		virtual ~ActionAtateBase() {}

		virtual void Enter(Character& owner) {}
		virtual void Update(Character& owner) {}
		virtual void Exit(Character& owner) {}
	};

	class ActionIdle :public ActionAtateBase
	{
	public:

		~ActionIdle() {}

		void Enter(Character& owner)override;
		void Update(Character& owner)override;
		void Exit(Character& owner)override;
	};

	class ActionJump :public ActionAtateBase
	{
	public:

		~ActionJump() {}

		void Enter(Character& owner)override;
		void Update(Character& owner)override;
		void Exit(Character& owner)override;
	};

	class ActionMove :public ActionAtateBase
	{
	public:

		~ActionMove() {}

		void Enter(Character& owner)override;
		void Update(Character& owner)override;
		void Exit(Character& owner)override;
	};

	void ChangeActionState(std::shared_ptr<ActionAtateBase> nextState);
	std::shared_ptr<ActionAtateBase> m_nowAction = nullptr;
};
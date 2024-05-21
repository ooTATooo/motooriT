#pragma once

class Terrain :public KdGameObject
{
public:

	Terrain() {}
	~Terrain()override {}

	void Init()override;
	void Update()override;
	void DrawLit()override;

private:

	// モデル
	std::shared_ptr<KdModelData> m_spModel = nullptr;

};
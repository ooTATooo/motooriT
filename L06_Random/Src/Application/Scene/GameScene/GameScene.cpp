#include "GameScene.h"
#include"../SceneManager.h"

#include "../../GameObject/Terrain/Terrain.h"
#include "../../GameObject/Character/Character.h"

#include "../../GameObject/Camera/FPSCamera/FPSCamera.h"
#include "../../GameObject/Camera/TPSCamera/TPSCamera.h"
#include "../../GameObject/Camera/CCTVCamera/CCTVCamera.h"

// 少数第n位で四捨五入する
void round_n(float& number, int n)
{
	number = number * pow(10, n - 1);
	number = round(number);
	number /= pow(10, n - 1);
}

void GameScene::Init()
{
	//===================================================================
	// ステージ初期化
	//===================================================================
	std::shared_ptr<Terrain> _terrain = std::make_shared<Terrain>();
	_terrain->Init();
	AddObject(_terrain);

	//===================================================================
	// キャラクター初期化
	//===================================================================
	std::shared_ptr<Character> _character = std::make_shared<Character>();
	_character->Init();
	AddObject(_character);

	//===================================================================
	// カメラ初期化
	//===================================================================
	//std::shared_ptr<FPSCamera>		_camera = std::make_shared<FPSCamera>();
	//std::shared_ptr<TPSCamera>		_camera = std::make_shared<TPSCamera>();
	std::shared_ptr<CCTVCamera>		_camera = std::make_shared<CCTVCamera>();
	_camera->Init();
	_camera->SetTarget(_character);
	_camera->RegistHitObject(_terrain);
	_character->SetCamera(_camera);
	AddObject(_camera);

	//===================================================================
	// 乱数の実験所
	//===================================================================
	//int randRes[10] = {};

	//如何にrand()が偏るか
	//srand((unsigned)time(NULL));
	//for (int i = 0 ; i < 100000000 ; i++)
	//{
	//	// 0～32767 % 10000(0～9999)
	//	int tmp = rand() % 10000;
	//	int idx = tmp / 1000;

	//	randRes[idx]++;
	//}

	//OutputDebugStringA("--------------------------------------");
	//for (int i = 0 ; i < 10 ; i++)
	//{
	//	std::stringstream ss;
	//	ss << "取得した値が" << i * 1000 << "～" << (i + 1) * 1000 << "の件数:\t" << randRes[i] << "\n";
	//	std::string str = ss.str();
	//	//OutputDebugStringA(str.c_str())
	//}
	//OutputDebugStringA("--------------------------------------");

	// メルセンヌツイスター
	//for (int i = 0; i < 100000000; i++)
	//{
	//	// 0～32767 % 10000(0～9999)
	//	int tmp = KdGetInt(0, 9999);
	//	int idx = tmp / 1000;

	//	randRes[idx]++;
	//}

	//OutputDebugStringA("--------------------------------------");
	//for (int i = 0; i < 10; i++)
	//{
	//	std::stringstream ss;
	//	ss << "取得した値が" << i * 1000 << "～" << (i + 1) * 1000 << "の件数:\t" << randRes[i] << "\n";
	//	std::string str = ss.str();
	//	OutputDebugStringA(str.c_str());
	//}
	//OutputDebugStringA("--------------------------------------");

	// レッスンその1:CカードとRカードをそれぞれ50%の確率で起動時に表示せよ
	//OutputDebugStringA("--------------------------------------\n");
	//int tmp = KdGetInt(0, 1);
	//std::stringstream ss;
	//if (tmp == 0)
	//{
	//	ss << "Cカード\n";
	//}
	//else
	//{
	//	ss << "Rカード\n";
	//}
	//std::string str = ss.str();
	//OutputDebugStringA(str.c_str());
	//OutputDebugStringA("--------------------------------------\n");

	// レッスンその2:CカードとRカードをそれぞれ99.5% 0.5%の確率で起動時に表示せよ
	//OutputDebugStringA("--------------------------------------\n");
	//int bunbo = 1000;
	//int thusenNum = 10000000;
	//int tosenNum[2] = {};

	//for (int i = 0; i < thusenNum; i++)
	//{
	//	int rad = KdGetInt(0, bunbo - 1);
	//	if (rad <= 4)
	//	{
	//		tosenNum[1]++;
	//	}
	//	else
	//	{
	//		tosenNum[0]++;
	//	}
	//}

	//float prob = 0;
	//for (int i = 0; i < 2; i++)
	//{
	//	std::stringstream ss;
	//	prob = ((float)tosenNum[i] / (float)thusenNum) * 100;
	//	round_n(prob, 3);

	//	switch (i)
	//	{
	//	case 0:
	//		ss << "Cカード当選回数 = " << tosenNum[0] << "\n" << "当選確率 = " << prob << "%" << "\n";
	//		break;
	//	case 1:
	//		ss << "Rカード当選回数 = " << tosenNum[1] << "\n" << "当選確率 = " << prob << "%" << "\n";
	//		break;
	//	}
	//	std::string str = ss.str();
	//	OutputDebugStringA(str.c_str());
	//}
	//OutputDebugStringA("--------------------------------------\n");

	// レッスンその3:CカードとRカードとSRカードをそれぞれ34% 33% 33%の確率で起動時に表示せよ
	OutputDebugStringA("--------------------------------------\n");
	int bunbo = 100;
	int thusenNum = 10000000;
	int tosenNum[3] = {};

	for (int i = 0; i < thusenNum; i++)
	{
		int rad = KdGetInt(0, bunbo - 1);
		if (rad < 33)
		{
			tosenNum[2]++;
		}
		else if (rad > 32 && rad < 66)
		{
			tosenNum[1]++;
		}
		else
		{
			tosenNum[0]++;
		}
	}

	float prob = 0;
	for (int i = 0; i < 3; i++)
	{
		std::stringstream ss;
		prob = ((float)tosenNum[i] / (float)thusenNum) * 100;
		round_n(prob, 2);

		switch (i)
		{
		case 0:
			ss << "Cカード当選回数 = " << tosenNum[0] << "\n" << "当選確率 = " << prob << "%" << "\n";
			break;
		case 1:
			ss << "Rカード当選回数 = " << tosenNum[1] << "\n" << "当選確率 = " << prob << "%" << "\n";
			break;
		case 2:
			ss << "SRカード当選回数 = " << tosenNum[2] << "\n" << "当選確率 = " << prob << "%" << "\n";
			break;
		}
		std::string str = ss.str();
		OutputDebugStringA(str.c_str());
	}
	OutputDebugStringA("--------------------------------------\n");

}

void GameScene::Event()
{
}
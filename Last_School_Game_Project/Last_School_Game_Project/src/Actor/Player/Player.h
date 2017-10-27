#pragma once

/**
 * @file Player.h
 * @brief ユーザーが操作するキャラクターの定義ファイル
 * @author 阿曽
 * @date 2017/9/9
 */

#include"Actor/Base/Actor.h"
#include"Mesh/SkinningMesh/SkinningMesh.h"
#include"Actor/State/StateManager.h"
#include"Actor/Status/HitPoint/HitPoint.h"
class ICamera;

 /*! @class Player
 *   @brief ユーザーが操作するキャラクター
 */
class Player : public Actor{
public:
	enum class State {
		Idle,
		Move,
		Damage,
		Dead,
		SwordAttack,
		Guard,
		BowAttack,
		Max_State_Num
	};
	enum Anime {
		Idle_,
		Walk_,
		Run_,
		Damage_,
		Dead_,
		Climb_,
		Fall_,
		Fall_Stand_,
		Guard_Start_,
		Guard_,
		Guard_End_,
		Aim_Walk_,
		Aim_OverDraw_,
		Aim_Recoil_,
		Draw_Sword_,
		Slash_00_,
		Slash_01_,
	};
public:
	Player(IWorld& world, const Vector3& position);
	~Player();

private:
	virtual void OnInitialize() override;
	virtual void OnUpdate(float deltaTime) override;
	virtual void OnDraw(Renderer& renderer) override;
	virtual void OnCollide(const HitInfo& hitInfo) override;
	virtual void OnMessage(EventMessage message, void* param = nullptr) override;
private:
	SkinningMesh mesh;
	ICamera* camera;
	StateManager stateManager;
	bool isGround;
public:
	HitPoint hp;
};


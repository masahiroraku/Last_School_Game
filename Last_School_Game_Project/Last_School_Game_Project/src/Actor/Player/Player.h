#pragma once

/**
 * @file Player.h
 * @brief ���[�U�[�����삷��L�����N�^�[�̒�`�t�@�C��
 * @author ���]
 * @date 2017/9/9
 */

#include"Actor/Base/Actor.h"
#include"Mesh/SkinningMesh/SkinningMesh.h"
#include"Actor/State/StateManager.h"
class ICamera;

 /*! @class Player
 *   @brief ���[�U�[�����삷��L�����N�^�[
 */
class Player : public Actor{
public:
	enum class State {
		Idle,
		Move,
		Damage,
		Dead,
		Max_State_Num
	};
	enum Anime {
		Idle_,
		Walk_,
		Run_,
		Damage_,
		Dead_
	};
public:
	Player(IWorld& world, const Vector3& position);
	~Player();

private:
	virtual void OnUpdate(float deltaTime) override;
	virtual void OnDraw(Renderer& renderer) override;
	virtual void OnCollide(const HitInfo& hitInfo) override;
	virtual void OnMessage(EventMessage message, void* param = nullptr) override;
private:
	SkinningMesh mesh;
	State state;

	ICamera* camera;
	StateManager stateManager;
};


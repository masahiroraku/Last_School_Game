#pragma once

#include "ActorPtr.h"
#include "Actor.h"
#include <unordered_map>
#include <functional>

enum class ActorGroup;
class Renderer;

/************************************************************
* File Name	: ActorManager.h
* Description	: �A�N�^�[�Ǘ��N���X
*																Date		:	2015-09-12.
*															  Author	:	���]
*************************************************************/
class ActorManager {
public:
	ActorManager();

	/// <summary>�������@</summary>
	void Initialize();

	/// <summary>�X�V�@</summary>
	void Update(float deltaTime);

	/// <summary>�`��@</summary>
	void Draw(Renderer& renderer);

	/// <summary>�I���@</summary>
	void Finalize();

	/// <summary>�A�N�^�[��ǉ��@</summary>
	void AddActor(ActorGroup group, const ActorPtr& actor);

	/// <summary>�O���[�v��ǉ��@</summary>
	void AddGroup(ActorGroup group, const std::string& name = "none", const ActorPtr& actor = nullptr);

	void HandleMessage(EventMessage message, void* param);

	/// <summary>�A�N�^�[�������@</summary>
	ActorPtr FindActor(const std::string& name);
	ActorPtr FindActor(ActorGroup group, const std::string& name);

	ActorPtr GetRoot(ActorGroup group);

private:
	void RegisterGroup();
	void Collide();

private:
	ActorManager(const ActorManager& other) = delete;
	ActorManager& operator = (const ActorManager& other) = delete;

private:
	Actor root;
	std::unordered_map<ActorGroup, ActorPtr> actors;
};
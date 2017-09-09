#pragma once

#include "ActorPtr.h"
#include "Actor.h"
#include <unordered_map>
#include <functional>

enum class ActorGroup;
class Renderer;

/************************************************************
* File Name	: ActorManager.h
* Description	: アクター管理クラス
*																Date		:	2015-09-12.
*															  Author	:	阿曽
*************************************************************/
class ActorManager {
public:
	ActorManager();

	/// <summary>初期化　</summary>
	void Initialize();

	/// <summary>更新　</summary>
	void Update(float deltaTime);

	/// <summary>描画　</summary>
	void Draw(Renderer& renderer);

	/// <summary>終了　</summary>
	void Finalize();

	/// <summary>アクターを追加　</summary>
	void AddActor(ActorGroup group, const ActorPtr& actor);

	/// <summary>グループを追加　</summary>
	void AddGroup(ActorGroup group, const std::string& name = "none", const ActorPtr& actor = nullptr);

	void HandleMessage(EventMessage message, void* param);

	/// <summary>アクターを検索　</summary>
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
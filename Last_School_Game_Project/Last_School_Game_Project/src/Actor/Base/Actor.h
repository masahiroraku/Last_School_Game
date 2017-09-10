#pragma once

#include <string>
#include<functional>
#include<forward_list>
#include "ActorPtr.h"

#include"Math\Vector3\Vector3.h"
#include"Math\Matrix4\Matrix4.h"
#include"ActorTag.h"
#include "Status.h"
#include "ActorGroup.h"
#include"Collision\ShapePtr.h"
class HitInfo;

class IWorld;
class Renderer;
enum class EventMessage;



/************************************************************
* File Name	: Actor.h
* Description	: アクタークラス（ゲームキャラの基底クラス）
*																Date		:	2015-09-12.
*															  Author	:	阿曽
*************************************************************/
class Actor
{
public:
	/// <summary>コンストラクタ　</summary>
	Actor();
	/// <summary>コンストラクタ　</summary>
	/// <param name="name">名前</param>
	/// <param name="position">初期位置</param>
	Actor(IWorld& world, const std::string& name, const Vector3& position, ShapePtr body);

	explicit Actor(const std::string& name);


	/// <summary>仮想デストラクタ　</summary>
	virtual ~Actor();

	void Initialize();

	/// <summary>更新　</summary>
	void Update(float deltaTime);

	/// <summary>描画　</summary>
	void Draw(Renderer& renderer);

	void Finalize();

	/// <summary>衝突判定　</summary>
	void Collide(Actor& other);
	/// <summary>子の衝突判定　</summary>
	void CollideChildren(Actor& other);

	//同じグループのあたり判定
	void CollideSibling();

	/// <summary>追加　</summary>
	void AddChild(const ActorPtr& actor);
	/// <summary>追加　</summary>
	void AddChild(ActorGroup group, const ActorPtr& actor);

	/// <summary>ステータス変更　</summary>
	void ChangeStatus(Status status);

	void SetBodyActive(bool isActive);

	/// <summary>巡回　</summary>
	void EachChildren(std::function<void(Actor&)> func);
	/// <summary>巡回　</summary>
	void EachChildren(std::function<void(const Actor&)> func) const;

	/// <summary>削除　</summary>
	void RemoveChildren(std::function<bool(Actor& actor)> func);
	/// <summary>削除　</summary>
	void RemoveChildren();

	/// <summary>子を検索　</summary>
	ActorPtr FindChildren(std::function<bool(const Actor&)> func);
	ActorPtr FindChildren(const std::string& name);

	/// <summary>全て削除　</summary>
	void ClearChildren();

	void HandleMessage(EventMessage message, void* param);

	void SetPosition(const Vector3& position);
	/// <summary>座標取得　</summary>
	Vector3 GetPosition() const;
	void SetMatrix(const Matrix4& matrix);
	/// <summary>変換行列取得　</summary>
	Matrix4 GetMatrix() const;
	Matrix4 GetRotate() const;

	/// <summary> 概要 :　状態取得　</summary>
	const Status GetStatus() const;

	/// <summary>名前取得　</summary>
	const std::string& GetName() const;

	void SetTag(ActorTag tag);
	ActorTag GetTag() const;

	ShapePtr GetBody() const;
	int SetID(int id);
	int GetID() const;
	const Actor& GetParent() const;

	std::forward_list<ActorPtr>& GetChildren();
	int GetChildNum() const;

protected:
	virtual void OnInitialize();
	virtual void OnUpdate(float deltaTime);
	virtual void OnDraw(Renderer& renderer);
	virtual void OnFinalize();
	virtual void OnMessage(EventMessage message, void* param);
	virtual void OnCollide(const HitInfo& hitInfo);
	virtual bool IsCollide(const Actor& other, HitInfo& hitInfo);

protected:
	Vector3		position;
	Matrix4		matrix;
	Status			status;
	std::string		name;

	ActorTag tag;

	ShapePtr body;

	const Actor* parent;

	IWorld*			world;
	int id;

private:
	std::forward_list<ActorPtr> children;
public:
	//コピー禁止
	Actor(const Actor& other) = delete;
	Actor& operator = (const Actor& other) = delete;
};

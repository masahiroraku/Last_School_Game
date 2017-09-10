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
* Description	: �A�N�^�[�N���X�i�Q�[���L�����̊��N���X�j
*																Date		:	2015-09-12.
*															  Author	:	���]
*************************************************************/
class Actor
{
public:
	/// <summary>�R���X�g���N�^�@</summary>
	Actor();
	/// <summary>�R���X�g���N�^�@</summary>
	/// <param name="name">���O</param>
	/// <param name="position">�����ʒu</param>
	Actor(IWorld& world, const std::string& name, const Vector3& position, ShapePtr body);

	explicit Actor(const std::string& name);


	/// <summary>���z�f�X�g���N�^�@</summary>
	virtual ~Actor();

	void Initialize();

	/// <summary>�X�V�@</summary>
	void Update(float deltaTime);

	/// <summary>�`��@</summary>
	void Draw(Renderer& renderer);

	void Finalize();

	/// <summary>�Փ˔���@</summary>
	void Collide(Actor& other);
	/// <summary>�q�̏Փ˔���@</summary>
	void CollideChildren(Actor& other);

	//�����O���[�v�̂����蔻��
	void CollideSibling();

	/// <summary>�ǉ��@</summary>
	void AddChild(const ActorPtr& actor);
	/// <summary>�ǉ��@</summary>
	void AddChild(ActorGroup group, const ActorPtr& actor);

	/// <summary>�X�e�[�^�X�ύX�@</summary>
	void ChangeStatus(Status status);

	void SetBodyActive(bool isActive);

	/// <summary>����@</summary>
	void EachChildren(std::function<void(Actor&)> func);
	/// <summary>����@</summary>
	void EachChildren(std::function<void(const Actor&)> func) const;

	/// <summary>�폜�@</summary>
	void RemoveChildren(std::function<bool(Actor& actor)> func);
	/// <summary>�폜�@</summary>
	void RemoveChildren();

	/// <summary>�q�������@</summary>
	ActorPtr FindChildren(std::function<bool(const Actor&)> func);
	ActorPtr FindChildren(const std::string& name);

	/// <summary>�S�č폜�@</summary>
	void ClearChildren();

	void HandleMessage(EventMessage message, void* param);

	void SetPosition(const Vector3& position);
	/// <summary>���W�擾�@</summary>
	Vector3 GetPosition() const;
	void SetMatrix(const Matrix4& matrix);
	/// <summary>�ϊ��s��擾�@</summary>
	Matrix4 GetMatrix() const;
	Matrix4 GetRotate() const;

	/// <summary> �T�v :�@��Ԏ擾�@</summary>
	const Status GetStatus() const;

	/// <summary>���O�擾�@</summary>
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
	//�R�s�[�֎~
	Actor(const Actor& other) = delete;
	Actor& operator = (const Actor& other) = delete;
};

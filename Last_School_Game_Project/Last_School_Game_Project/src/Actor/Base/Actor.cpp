#include "Actor.h"
#include "ActorGroup.h"
#include "Status.h"
#include"Renderer/Renderer.h"
#include "World/IWorld.h"
#include <algorithm>
#include"Collision/HitInfo.h"
#include"Collision/BoundingSphere/BoundingSphere.h"

Actor::Actor()
	:Actor(*world, "none", Vector3(0, 0, 0), std::make_shared<BoundingSphere>())
{
}

Actor::Actor(IWorld& world, const std::string& name, const Vector3& position, ShapePtr body)
	: world(&world)
	, position(position)
	, status(Status::Active)
	, name(name)
	, matrix()
	, body(body)
	, tag(ActorTag::None)
{
}
Actor::Actor(const std::string & name)
	: world(nullptr)
	, position(Vector3::Zero)
	, status(Status::Active)
	, name(name)
	, matrix()
	, body(nullptr)
	, tag(ActorTag::None)
{
}


Actor::~Actor() {

}

void Actor::Initialize() {
	OnInitialize();

	EachChildren([](Actor& actor) {
		actor.Initialize();
	});
}

void Actor::Update(float deltaTime) {
	OnUpdate(deltaTime);

	EachChildren([&deltaTime](Actor& actor) {
		bool isActive = actor.GetStatus() == Status::Active;
		bool isUpdateOnly = actor.GetStatus() == Status::UpdateOnly;

		if (isActive || isUpdateOnly)
			actor.Update(deltaTime);
	});
}

void Actor::Draw(Renderer& renderer) {
	OnDraw(renderer);

	EachChildren([&renderer](Actor& actor) {
		bool isActive = actor.GetStatus() == Status::Active;
		bool isDrawOnly = actor.GetStatus() == Status::DrawOnly;

		if (isActive || isDrawOnly)
			actor.Draw(renderer);
	});
}

void Actor::Finalize() {
	OnFinalize();

	EachChildren([](Actor& actor) {
		actor.Finalize();
	});
}

void Actor::Collide(Actor& other) {
	HitInfo hitInfo;


	//衝突したか？
	if (IsCollide(other, hitInfo)) {
		//衝突したお互いのアクターのOnCollide()を呼ぶ
		hitInfo.collideActor = &other;
		OnCollide(hitInfo);

		hitInfo.collideActor = this;
		other.OnCollide(hitInfo);
	}


	//子の衝突判定を行う
	EachChildren([&](Actor& actor) {
		actor.Collide(other);
	});
}

void Actor::CollideChildren(Actor& other) {
	EachChildren([&other](Actor& my) {
		other.EachChildren([&](Actor& target) {
			my.Collide(target);
		});
	});
}

void Actor::CollideSibling()
{
	for (auto& i = children.begin(); i != children.end(); ++i) {
		std::for_each(std::next(i), children.end(),
			[&](const ActorPtr& actor) {(*i)->Collide(*actor); });
	}

}

void Actor::AddChild(const ActorPtr& actor) {
	children.emplace_front(actor);
}

void Actor::AddChild(ActorGroup group, const ActorPtr& actor) {
	world->AddActor(group, actor);
}

void Actor::ChangeStatus(Status status) {
	this->status = status;
}

void Actor::SetBodyActive(bool isActive)
{
	body->isActive = isActive;
}

void Actor::EachChildren(std::function<void(Actor&)> func) {
	std::for_each(children.begin(), children.end(),
		[&](const ActorPtr& actor) { func(*actor); });
}

void Actor::EachChildren(std::function<void(const Actor&)> func) const
{
	std::for_each(children.begin(), children.end(),
		[&](const ActorPtr& actor) { func(*actor); });
}

void Actor::RemoveChildren(std::function<bool(Actor& actor)> func) {
	children.remove_if(
		[&](const ActorPtr& actor) {return func(*actor); });
}

void Actor::RemoveChildren() {
	RemoveChildren([](Actor& actor) {
		return actor.GetStatus() == Status::Dead;
	});

	EachChildren([](Actor& actor) {
		actor.RemoveChildren();
	});
}

ActorPtr Actor::FindChildren(std::function<bool(const Actor&)> func) {
	auto childIterator = std::find_if(children.begin(), children.end(),
		[&func](const ActorPtr& child) {
		return func(*child);
	});

	//見つかったら
	if (childIterator != children.end())
		return *childIterator;

	//子にもFindChildrenを実行させる
	for (ActorPtr& child : children) {
		ActorPtr actor = child->FindChildren(func);
		if (actor != nullptr)
			return actor;
	}

	return nullptr;
}

ActorPtr Actor::FindChildren(const std::string& name) {
	return FindChildren([&](const Actor& actor) {
		return actor.GetName() == name;
	});
}

void Actor::ClearChildren() {
	children.clear();
}

void Actor::HandleMessage(EventMessage message, void * param)
{
	OnMessage(message, param);
	EachChildren([&](Actor& child) {
		child.HandleMessage(message, param);
	});
}

void Actor::OnInitialize() {
}

void Actor::OnUpdate(float deltaTime) {
	(void)deltaTime;
}

void Actor::OnDraw(Renderer& renderer) {
	(void)renderer;
}

void Actor::OnFinalize() {

}

void Actor::OnMessage(EventMessage message, void * param)
{
	(void)message;
	(void)param;
}

void Actor::OnCollide(const HitInfo& hitInfo) {
	(void)hitInfo;
}

bool Actor::IsCollide(const Actor& other, HitInfo& hitInfo) {
	if (body == nullptr || body->isActive == false) return false;
	if (other.body == nullptr || other.body->isActive == false) return false;

	return body->Transform(GetMatrix())->Intersect(
		*other.body->Transform(other.GetMatrix()), hitInfo);
}

void Actor::SetPosition(const Vector3 & position)
{
	this->position = position;
}


Vector3 Actor::GetPosition() const {
	return position;
}

void Actor::SetMatrix(const Matrix4 & matrix)
{
	this->matrix = matrix;
}

Matrix4 Actor::GetMatrix() const {
	return Matrix4(matrix).SetPosition(position);
}

Matrix4 Actor::GetRotate() const
{
	return Matrix4(matrix).SetPosition(Vector3::Zero);
}

Status Actor::GetStatus() const {
	return status;
}

const std::string& Actor::GetName() const {
	return name;
}

void Actor::SetTag(ActorTag tag)
{
	this->tag = tag;
}

ActorTag Actor::GetTag() const
{
	return tag;
}



ShapePtr Actor::GetBody() const
{
	return body->Transform(GetMatrix());
}



std::forward_list<ActorPtr>& Actor::GetChildren(){
	return children;
}

int Actor::GetChildNum() const
{
	return static_cast<int>(std::distance(children.begin(), children.end()));
}

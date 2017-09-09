#include"BoundingSphere.h"

#include"Collision/HitInfo.h"
#include"Collision/Collision.h"
#include"Math\Matrix4\Matrix4.h"
#include<DxLib.h>
#include<cassert>
#include"Collision\Capsule\Capsule.h"
#include"Collision\Line\Line.h"
#include"Math/Convert/Convert.h"

BoundingSphere::BoundingSphere(const Vector3& center, float radius)
	:ShapeBase()
	, center(center)
	, radius(radius) {
	
}

//デフォルトのコンストラクタ
BoundingSphere::BoundingSphere(float radius) :
	BoundingSphere(Vector3::Zero, radius) {
}

ShapePtr BoundingSphere::Translate(const Vector3& position) const {
	ShapePtr shape = std::make_shared<BoundingSphere>(center + position, radius);
	shape->isActive = isActive;
	return shape;
}

ShapePtr BoundingSphere::Transform(const Matrix4& matrix) const {
	ShapePtr shape = std::make_shared<BoundingSphere>(matrix.Transform(center), radius * matrix.GetScale().y);
	shape->isActive = isActive;
	return shape;
}

ShapeType BoundingSphere::GetShapeType() const
{
	return ShapeType::BoundingSphere;
}

bool BoundingSphere::Collide_BoundingSphere(const ShapeBase & shape, HitInfo & hitInfo)
{
	const BoundingSphere* sphere = static_cast<const BoundingSphere*>(&shape);
	if (sphere == nullptr) {
		assert(!"Conversion failed.");
		return false;
	}
	return Collision::BoundingShpere_BoundingSphere(*this, *sphere, hitInfo);
}

bool BoundingSphere::Collide_Capsule(const ShapeBase & shape, HitInfo & hitInfo)
{
	const Capsule* capsule = static_cast<const Capsule*>(&shape);
	if (capsule == nullptr) {
		assert(!"Conversion failed.");
		return false;
	}
	return Collision::BoundingSphere_Capsule(*this, *capsule, hitInfo);
}

bool BoundingSphere::Collide_Line(const ShapeBase & shape, HitInfo & hitInfo)
{
	const Line* line = static_cast<const Line*>(&shape);
	if (line == nullptr) {
		assert(!"Conversion failed.");
		return false;
	}
	return Collision::BoundingSphere_Line(*this, *line, hitInfo);
}

void BoundingSphere::Draw() const
{
	Color color = (isActive == true) ? Color::Green : Color::Red;
	DrawSphere3D(Convert::ToVECTOR(center), radius, 32, color.ToCOLOR(), color.ToCOLOR(), FALSE);
}
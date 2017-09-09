#include"Capsule.h"
#include"Utility\Color\Color.h"
#include<DxLib.h>
#include"Collision\Collision.h"
#include"Collision\Line\Line.h"
#include"Collision\BoundingSphere\BoundingSphere.h"
#include<cassert>
#include"Math/Convert/Convert.h"

Capsule::Capsule(const Vector3& p1, const Vector3& p2, float radius)
	: p1(p1)
	, p2(p2)
	, vector(p2 - p1)
	, radius(radius)
{
}

Capsule::~Capsule() {
}

ShapePtr Capsule::Translate(const Vector3 & position) const
{
	ShapePtr shape = std::make_shared<Capsule>(p1 + position, p2 + position, radius);
	shape->isActive = isActive;
	return shape;
}

ShapePtr Capsule::Transform(const Matrix4 & matrix) const
{
	ShapePtr shape = std::make_shared<Capsule>(matrix.Transform(p1), matrix.Transform(p2), radius);
	shape->isActive = isActive;
	return shape;
}

ShapeType Capsule::GetShapeType() const
{
	return ShapeType::Capsule;
}

bool Capsule::Collide_BoundingSphere(const ShapeBase & shape, HitInfo & hitInfo)
{
	const BoundingSphere* sphere = static_cast<const BoundingSphere*>(&shape);
	if (sphere == nullptr) {
		assert(!"Conversion failed.");
		return false;
	}
	return Collision::BoundingSphere_Capsule(*sphere, *this, hitInfo);
}

bool Capsule::Collide_Capsule(const ShapeBase & shape, HitInfo & hitInfo)
{
	const Capsule* capsule = static_cast<const Capsule*>(&shape);
	if (capsule == nullptr) {
		assert(!"Conversion failed.");
		return false;
	}
	return Collision::Capsule_Capsule(*this, *capsule, hitInfo);
}

bool Capsule::Collide_Line(const ShapeBase & shape, HitInfo & hitInfo)
{
	const Line* line = static_cast<const Line*>(&shape);
	if (line == nullptr) {
		assert(!"Conversion failed.");
		return false;
	}
	return Collision::Capsule_Line(*this, *line, hitInfo);
}

void Capsule::Draw() const
{
	Color color = (isActive == true) ? Color::Green : Color::Red;
	DrawCapsule3D(Convert::ToVECTOR(p1), Convert::ToVECTOR(p2), radius, 8, color.ToCOLOR(), color.ToCOLOR(), FALSE);
}
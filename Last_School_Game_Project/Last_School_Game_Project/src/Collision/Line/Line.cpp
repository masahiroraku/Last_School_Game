#include"Line.h"
#include"Utility\Color\Color.h"
#include"Collision\BoundingSphere\BoundingSphere.h"
#include"Collision\HitInfo.h"
#include"Collision/Capsule/Capsule.h"
#include"Math/Convert/Convert.h"
#include"Collision/Collision.h"
#include<cassert>

Line::Line(const Vector3& p1, const Vector3& p2)
	: p1(p1)
	, p2(p2)
	, vector(p2 - p1)
{
}

Line::Line(const Vector2 & screenPosition, const Matrix4 & screen, const Matrix4 & projection, const Matrix4 & view)
{
	p1 = Matrix4::CreateUnProjection(Vector3(screenPosition.x, screenPosition.y, -1), screen, projection, view);
	p2 = Matrix4::CreateUnProjection(Vector3(screenPosition.x, screenPosition.y, 1), screen, projection, view);
}

Line::~Line() {
}

ShapePtr Line::Translate(const Vector3 & position) const
{
	ShapePtr shape = std::make_shared<Line>(p1 + position, p2 + position);
	shape->isActive = isActive;
	return shape;
}

ShapePtr Line::Transform(const Matrix4 & matrix) const
{
	ShapePtr shape = std::make_shared<Line>(matrix.Transform(p1), matrix.Transform(p2));
	shape->isActive = isActive;
	return shape;
}

ShapeType Line::GetShapeType() const
{
	return ShapeType::Line;
}

bool Line::Collide_BoundingSphere(const ShapeBase & shape, HitInfo & hitInfo)
{
	const BoundingSphere* sphere = static_cast<const BoundingSphere*>(&shape);
	if (sphere == nullptr) {
		assert(!"Conversion failed.");
		return false;
	}
	return Collision::BoundingSphere_Line(*sphere, *this, hitInfo);
}

bool Line::Collide_Capsule(const ShapeBase & shape, HitInfo & hitInfo)
{
	const Capsule* capsule = static_cast<const Capsule*>(&shape);
	if (capsule == nullptr) {
		assert(!"Conversion failed.");
		return false;
	}
	return Collision::Capsule_Line(*capsule, *this, hitInfo);
}

bool Line::Collide_Line(const ShapeBase & shape, HitInfo & hitInfo)
{
	const Line* line = static_cast<const Line*>(&shape);
	if (line == nullptr) {
		assert(!"Conversion failed.");
		return false;
	}
	return Collision::Line_Line(*this, *line, hitInfo);
}

void Line::Draw() const
{
	Color color = (isActive == true) ? Color::Green : Color::Red;
	DrawLine3D(Convert::ToVECTOR(p1), Convert::ToVECTOR(p2), color.ToCOLOR());
}

void Line::Draw(const Color & color)
{
	DrawLine3D(Convert::ToVECTOR(p1), Convert::ToVECTOR(p2), color.ToCOLOR());
}


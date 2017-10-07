#include "BoundingBox.h"

BoundingBox::BoundingBox()
	: min(0,0,0)
	, max(0,0,0)
{
}

BoundingBox::BoundingBox(const Vector3 & min, const Vector3 & max)
	: min(min)
	, max(max)
{
}

ShapePtr BoundingBox::Translate(const Vector3 & position) const
{
	return ShapePtr();
}

ShapePtr BoundingBox::Transform(const Matrix4 & matrix) const
{
	return ShapePtr();
}

ShapeType BoundingBox::GetShapeType() const
{
	return ShapeType::BoundingBox;
}

bool BoundingBox::Collide_BoundingSphere(const ShapeBase & shape, HitInfo & hitInfo)
{
	return false;
}

bool BoundingBox::Collide_Capsule(const ShapeBase & shape, HitInfo & hitInfo)
{
	return false;
}

bool BoundingBox::Collide_Line(const ShapeBase & shape, HitInfo & hitInfo)
{
	return false;
}

bool BoundingBox::Collide_BoundingBox(const ShapeBase & shape, HitInfo & hitInfo)
{
	return false;
}

bool BoundingBox::Collide_OrientedBoundingBox(const ShapeBase & shape, HitInfo & hitInfo)
{
	return false;
}

void BoundingBox::Draw() const
{
}

Vector3 BoundingBox::ClosestPoint(const Vector3 & target) const
{
	Vector3 clamp = target;
	clamp.Clamp(min, max);
	return clamp;
}

Vector3 BoundingBox::CornerPoint(int cornerIndex) const
{
	switch (cornerIndex) {
	default: // For release builds where assume() is diamled, return always the first option if out-of-bounds.
	case 0: return min;
	case 1: return Vector3(min.x, min.y, max.z);
	case 2: return Vector3(min.x, max.y, min.z);
	case 3: return Vector3(min.x, max.y, max.z);
	case 4: return Vector3(max.x, min.y, min.z);
	case 5: return Vector3(max.x, min.y, max.z);
	case 6: return Vector3(max.x, max.y, min.z);
	case 7: return max;
	}
	return Vector3();
}

Vector3 BoundingBox::Size() const
{
	return max - min;
}

Vector3 BoundingBox::Center() const
{
	return (max + min) / 2.0f;
}

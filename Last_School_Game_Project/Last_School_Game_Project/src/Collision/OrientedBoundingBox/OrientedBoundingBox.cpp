#include "OrientedBoundingBox.h"
#include "Collision/BoundingBox/BoundingBox.h"
#include "Math/Math.h"

OrientedBoundingBox::OrientedBoundingBox()
	: position(0.0f, 0.0f, 0.0f)
	, extents(1.0f, 1.0f, 1.0f) 
{
	axis[0] = Vector3(1.0f, 0.0f, 0.0f);
	axis[1] = Vector3(0.0f, 1.0f, 0.0f);
	axis[2] = Vector3(0.0f, 0.0f, 1.0f);
}

OrientedBoundingBox::OrientedBoundingBox(const Vector3 & position, const Vector3 & extents, const Vector3 & axis_x, const Vector3 & axis_y, const Vector3 & axis_z)
	: position(position)
	, extents(extents)
{
	axis[0] = axis_x;
	axis[1] = axis_y;
	axis[2] = axis_z;
}

OrientedBoundingBox::OrientedBoundingBox(const BoundingBox & aabb)
	: position((aabb.min + aabb.max) / 2.0f)
	, extents((aabb.max - aabb.min) / 2.0f)
{
	axis[0] = Vector3(1.0f, 0.0f, 0.0f);
	axis[1] = Vector3(0.0f, 1.0f, 0.0f);
	axis[2] = Vector3(0.0f, 0.0f, 1.0f);
}

bool OrientedBoundingBox::Intersect(const ShapeBase & shape, HitInfo & hitInfo)
{
	return false;
}

ShapePtr OrientedBoundingBox::Translate(const Vector3 & position) const
{
	return ShapePtr();
}

ShapePtr OrientedBoundingBox::Transform(const Matrix4 & matrix) const
{
	return ShapePtr();
}

bool OrientedBoundingBox::Collide_BoundingSphere(const ShapeBase & shape, HitInfo & hitInfo)
{
	return false;
}

bool OrientedBoundingBox::Collide_Capsule(const ShapeBase & shape, HitInfo & hitInfo)
{
	return false;
}

bool OrientedBoundingBox::Collide_Line(const ShapeBase & shape, HitInfo & hitInfo)
{
	return false;
}

bool OrientedBoundingBox::Collide_BoundingBox(const ShapeBase & shape, HitInfo & hitInfo)
{
	return false;
}

bool OrientedBoundingBox::Collide_OrientedBoundingBox(const ShapeBase & shape, HitInfo & hitInfo)
{
	return false;
}

void OrientedBoundingBox::Draw() const
{
}

Vector3 OrientedBoundingBox::ClosestPoint(const Vector3 & target) const
{
	const Vector3& d = target - position;
	Vector3 result = position;
	result += Math::Clamp(d.Dot(axis[0]), -extents.x, extents.x) * axis[0];
	result += Math::Clamp(d.Dot(axis[1]), -extents.y, extents.y) * axis[1];
	result += Math::Clamp(d.Dot(axis[2]), -extents.z, extents.z) * axis[2];
	return result;
}

Matrix4 OrientedBoundingBox::LocalToWorld() const
{
	return Matrix4(
		axis[0].x, axis[0].y, axis[0].z, 0.0f,
		axis[1].x, axis[1].y, axis[1].z, 0.0f,
		axis[2].x, axis[2].y, axis[2].z, 0.0f,
		position.x, position.y, position.z, 1.0f
	);
}

Matrix4 OrientedBoundingBox::WorldToLocal() const
{
	return LocalToWorld().InverseFast();
}

Vector3 OrientedBoundingBox::CornerPoint(int cornerIndex) const
{
	switch (cornerIndex) {
	default: // For release builds where assume() is disabled, return always the first option if out-of-bounds.
	case 0: return position - extents.x * axis[0] - extents.y * axis[1] - extents.z * axis[2];
	case 1: return position - extents.x * axis[0] - extents.y * axis[1] + extents.z * axis[2];
	case 2: return position - extents.x * axis[0] + extents.y * axis[1] - extents.z * axis[2];
	case 3: return position - extents.x * axis[0] + extents.y * axis[1] + extents.z * axis[2];
	case 4: return position + extents.x * axis[0] - extents.y * axis[1] - extents.z * axis[2];
	case 5: return position + extents.x * axis[0] - extents.y * axis[1] + extents.z * axis[2];
	case 6: return position + extents.x * axis[0] + extents.y * axis[1] - extents.z * axis[2];
	case 7: return position + extents.x * axis[0] + extents.y * axis[1] + extents.z * axis[2];
	}
}

Vector3 OrientedBoundingBox::Size() const
{
	return extents * 2.0f;
}

Vector3 OrientedBoundingBox::Center() const
{
	return position;
}

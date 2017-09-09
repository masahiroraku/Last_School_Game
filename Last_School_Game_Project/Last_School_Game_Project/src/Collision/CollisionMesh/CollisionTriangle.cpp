#include "CollisionTriangle.h"
#include<DxLib.h>
#include"Math/Convert/Convert.h"

CollisionTriangle::CollisionTriangle(const Vector3 & p1, const Vector3 & p2, const Vector3 & p3)
	: points()
{
	points[0] = Convert::ToVECTOR(p1);
	points[1] = Convert::ToVECTOR(p2);
	points[2] = Convert::ToVECTOR(p3);
}

CollisionTriangle::CollisionTriangle(const VECTOR & p1, const VECTOR & p2, const VECTOR & p3)
	: points({p1,p2,p3})
{
}

CollisionTriangle::~CollisionTriangle()
{
}

bool CollisionTriangle::IsInside(const Vector3 & point) const
{
	float w1, w2, w3;
	TriangleBarycenter(points[0], points[1], points[2],Convert::ToVECTOR(point), &w1, &w2, &w3);
	return (0.0f <= w1 && w1 <= 1.0f) && (0.0f <= w2 && w2 <= 1.0f) && (0.0f <= w3 && w3 <= 1.0f);
}

bool CollisionTriangle::Collide_Edge_And_Sphere(const BoundingSphere & sphere, Vector3 * result)
{
	bool is_collided = false;
	VECTOR result_center = Convert::ToVECTOR(sphere.center);
	const VECTOR edges[4]{ points[0],points[1], points[2], points[0] };
	for (int i = 0; i < 3; i++)
	{
		SEGMENT_POINT_RESULT segment_point_result;
		Segment_Point_Analyse(&edges[i], &edges[i + 1], &result_center, &segment_point_result);
		const auto distance = std::sqrt(segment_point_result.Seg_Point_MinDist_Square);
		if (distance <= sphere.radius)
		{
			VECTOR offset = VScale(VNorm(VSub(result_center, segment_point_result.Seg_MinDist_Pos)), sphere.radius - distance);
			result_center = VAdd(result_center, offset);
			is_collided = true;
		}
	}
	if (is_collided && (result != nullptr))
	{
		*result = Convert::ToVector3(result_center);
	}
	return is_collided;
}

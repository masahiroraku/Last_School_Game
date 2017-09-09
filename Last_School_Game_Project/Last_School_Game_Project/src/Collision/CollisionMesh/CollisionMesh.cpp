#include "CollisionMesh.h"
#include"CollisionTriangle.h"
#include"Math/Convert/Convert.h"
CollisionMesh::CollisionMesh(int modelHandle)
	: modelHandle(modelHandle)
{
}

CollisionMesh::~CollisionMesh()
{
}

bool CollisionMesh::Collide_Line(const Line & line, Vector3 * point, Vector3 * normal) const
{
	const auto coll_poly = MV1CollCheck_Line(modelHandle, 0,  Convert::ToVECTOR(line.p1), Convert::ToVECTOR(line.p2));
	if (coll_poly.HitFlag == TRUE)
	{
		if (point != nullptr)
		{
			*point = Convert::ToVector3(coll_poly.HitPosition);
		}
		if (normal != nullptr)
		{
			*normal = Convert::ToVector3(coll_poly.Normal);
		}
	}
	return coll_poly.HitFlag == TRUE;
}

bool CollisionMesh::Collide_Sphere(const BoundingSphere & sphere, Vector3 * result) const
{
	const auto coll_poly = MV1CollCheck_Sphere(modelHandle, 0, Convert::ToVECTOR(sphere.center), sphere.radius);
	if (coll_poly.HitNum == 0)
	{
		MV1CollResultPolyDimTerminate(coll_poly);
		return false;
	}
	VECTOR result_center = Convert::ToVECTOR(sphere.center);
	for (int i = 0; i < coll_poly.HitNum; ++i)
	{
		PLANE_POINT_RESULT plane_point_result;
		Plane_Point_Analyse(
			&coll_poly.Dim[i].Position[0],
			&coll_poly.Dim[i].Normal,
			&result_center,
			&plane_point_result);

		if (CollisionTriangle(
			coll_poly.Dim[i].Position[0],
			coll_poly.Dim[i].Position[1],
			coll_poly.Dim[i].Position[2]).IsInside(Convert::ToVector3(plane_point_result.Plane_MinDist_Pos)))
		{
			const float distance = std::sqrt(plane_point_result.Plane_Pnt_MinDist_Square);
			const VECTOR offset = VScale(coll_poly.Dim[i].Normal, sphere.radius - distance);
			result_center = VAdd(result_center, offset);
		}
	}

	Vector3 result_center_vector3;
	for (int i = 0; i < coll_poly.HitNum; ++i)
	{
		BoundingSphere s = BoundingSphere(Convert::ToVector3(result_center), sphere.radius);
		CollisionTriangle(
			coll_poly.Dim[i].Position[0],
			coll_poly.Dim[i].Position[1],
			coll_poly.Dim[i].Position[2]).Collide_Edge_And_Sphere(s, &result_center_vector3);
	}
	if (result != nullptr)
	{
		*result = result_center_vector3;
	}
	MV1CollResultPolyDimTerminate(coll_poly);
	return true;
}

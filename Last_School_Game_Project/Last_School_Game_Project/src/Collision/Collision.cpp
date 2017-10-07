#include"Collision.h"

#include"Collision/Line/Line.h"
#include"Collision/Capsule/Capsule.h"
#include"Collision/BoundingSphere/BoundingSphere.h"
#include"HitInfo.h"
#include"Math/Math.h"
#include"Math/Convert/Convert.h"
#include<cassert>
#include"Collision/BoundingBox/BoundingBox.h"
#include"Collision/OrientedBoundingBox/OrientedBoundingBox.h"

void Collision::SetUpOctree(unsigned int modelID, int XDivNum, int YDivNum, int ZDivNum)
{
	int isSuccess = MV1SetupCollInfo(modelID, -1, XDivNum, YDivNum, ZDivNum);
	if (isSuccess == -1) {
		assert(!"It failed to initialize.");
	}
}

bool Collision::BoundingShpere_BoundingSphere(const BoundingSphere& sphere1, const BoundingSphere& sphere2, HitInfo& hitInfo) {
	float radius = sphere1.radius + sphere2.radius;
	Vector3 distance = sphere2.center - sphere1.center;

	if (distance.SquareLength() >= radius * radius)
		return false;

	//’†‰›‚ğŒ‹‚ñ‚¾ƒxƒNƒgƒ‹‚Ì³‹K‰»
	Vector3 n = distance.GetNormal();

	hitInfo.intersect = sphere2.center - radius * n;
	return true;
}

bool Collision::BoundingSphere_Line(const BoundingSphere& sphere, const Line& line, HitInfo& hitInfo) {
	Vector3 vec = line.vector;

	Vector3 v1 = sphere.center - line.p1;
	float t = vec.Dot(v1) / vec.Dot(vec);
	if (t < 0 && v1.SquareLength() <= sphere.radius * sphere.radius) {
		hitInfo.intersect = line.p1;
		return true;
	}

	Vector3 v2 = sphere.center - line.p2;
	if (t > 0 && v2.SquareLength() <= sphere.radius * sphere.radius) {
		hitInfo.intersect = line.p2;
		return true;
	}

	Vector3 vn = v1 - t * vec;
	if ((0 < t && t < 1) && (vn.SquareLength() < sphere.radius * sphere.radius)) {
		hitInfo.intersect = line.p1 + t * vec;
		return true;
	}

	return false;
}

bool Collision::BoundingSphere_Capsule(const BoundingSphere& sphere, const Capsule& capsule, HitInfo& hitInfo) {
	BoundingSphere s = { sphere.center, sphere.radius + capsule.radius };
	Line l = { capsule.p1, capsule.p2 };
	return BoundingSphere_Line(s, l, hitInfo);
}

bool Collision::Capsule_Capsule(const Capsule& capsule1, const Capsule& capsule2, HitInfo& hitInfo) {
	
	VECTOR cap1pos1 = Convert::ToVECTOR(capsule1.p1);
	VECTOR cap1pos2 = Convert::ToVECTOR(capsule1.p2);

	VECTOR cap2pos1 = Convert::ToVECTOR(capsule2.p1);
	VECTOR cap2pos2 = Convert::ToVECTOR(capsule2.p2);
	
	int isCollide = HitCheck_Capsule_Capsule(cap1pos1, cap1pos2, capsule1.radius, cap2pos1, cap2pos2, capsule2.radius);

	return (isCollide != 0);
}

bool Collision::Capsule_Line(const Capsule& capsule, const Line& line, HitInfo& hitInfo) {
	
	VECTOR cappos1 = Convert::ToVECTOR(capsule.p1);
	VECTOR cappos2 = Convert::ToVECTOR(capsule.p2);

	VECTOR linepos1 = Convert::ToVECTOR(line.p1);
	VECTOR linepos2 = Convert::ToVECTOR(line.p2);

	int isCollide = HitCheck_Capsule_Capsule(cappos1, cappos2, capsule.radius, linepos1, linepos2, 0.0f);

	return (isCollide != 0);
}

bool Collision::Line_Line(const Line & line1, const Line & line2, HitInfo & hitInfo)
{
	VECTOR line1pos1 = Convert::ToVECTOR(line1.p1);
	VECTOR line1pos2 = Convert::ToVECTOR(line1.p2);

	VECTOR line2pos1 = Convert::ToVECTOR(line2.p1);
	VECTOR line2pos2 = Convert::ToVECTOR(line2.p2);

	int isCollide = HitCheck_Capsule_Capsule(line1pos1, line1pos2, 0.0f, line2pos1, line2pos2, 0.0f);

	return (isCollide != 0);
}

bool Collision::Octree_Line(int modelID, const Line& line, HitInfo& hitInfo) {
	MV1_COLL_RESULT_POLY mv1HitInfo;
	mv1HitInfo = MV1CollCheck_Line(modelID, -1, Convert::ToVECTOR(line.p1), Convert::ToVECTOR(line.p2));

	if (mv1HitInfo.HitFlag != 1) {
		return false;
	}
	VECTOR pos = mv1HitInfo.HitPosition;
	hitInfo.intersect = Vector3(pos.x, pos.y, pos.z);
	VECTOR normal = mv1HitInfo.Normal;
	hitInfo.normal = Vector3(normal.x, normal.y, normal.z);

	return true;
}

bool Collision::Octree_BoundingSphere(int modelID, const BoundingSphere& sphere, HitInfo& hitInfo) {
	MV1_COLL_RESULT_POLY_DIM mv1HitInfo;
	mv1HitInfo = MV1CollCheck_Sphere(modelID, -1, Convert::ToVECTOR(sphere.center), sphere.radius);

	if (mv1HitInfo.HitNum < 1) {
		return false;
	}

	int hitNum = mv1HitInfo.HitNum;

	Vector3 pos;
	Vector3 normal;
	for (int i = 0; i < hitNum; ++i) {
		VECTOR p = mv1HitInfo.Dim[i].HitPosition;
		pos += Vector3(p.x, p.y, p.z);
		VECTOR n = mv1HitInfo.Dim[i].Normal;
		normal += Vector3(n.x, n.y, n.z);
	}
	pos /= hitNum;
	normal /= hitNum;
	hitInfo.intersect = pos;
	hitInfo.normal = normal.GetNormal();

	MV1CollResultPolyDimTerminate(mv1HitInfo);

	return true;
}

bool Collision::Octree_Capsule(int modelID, const Capsule& capsule, HitInfo& hitInfo) {
	MV1_COLL_RESULT_POLY_DIM mv1HitInfo;
	mv1HitInfo = MV1CollCheck_Capsule(modelID, -1, Convert::ToVECTOR(capsule.p1), Convert::ToVECTOR(capsule.p2), capsule.radius);

	if (mv1HitInfo.HitNum < 1) {
		return false;
	}

	int hitNum = mv1HitInfo.HitNum;

	Vector3 pos;
	Vector3 normal;
	for (int i = 0; i < hitNum; ++i) {
		VECTOR p = mv1HitInfo.Dim[i].HitPosition;
		pos += Vector3(p.x, p.y, p.z);
		VECTOR n = mv1HitInfo.Dim[i].Normal;
		normal += Vector3(n.x, n.y, n.z);
	}
	pos /= hitNum;
	normal /= hitNum;
	hitInfo.intersect = pos;
	hitInfo.normal = normal.GetNormal();

	MV1CollResultPolyDimTerminate(mv1HitInfo);

	return true;
}

